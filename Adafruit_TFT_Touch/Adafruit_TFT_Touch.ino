#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Adafruit_STMPE610.h"

#define TFT_DC 9
#define TFT_CS 10

#define TS_MINX 150
#define TS_MINY 130
#define TS_MAXX 3800
#define TS_MAXY 4000

#define SMTPE_CS 8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(SMTPE_CS);

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing....");

  tft.begin();
  if (!ts.begin()) {
    Serial.println("SMTPE is not found");
  }

  // rotate 270 degree clockwise
  tft.setRotation(3);
}

void loop() {
  if (!ts.bufferEmpty()) {
    TS_Point p = ts.getPoint();
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());

    if (ts.touched()) {
      Serial.println("Touched!");
      Serial.print(p.x);
      Serial.print(",");
      Serial.println(p.y);
    }
  }
}