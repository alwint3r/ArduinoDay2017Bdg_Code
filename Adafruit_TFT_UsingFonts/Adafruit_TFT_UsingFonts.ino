#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  Serial.begin(9600);

  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(0xFFFF);
  tft.setFont(&FreeSerif12pt7b);
  tft.setCursor(30, tft.height()/2 - 10);
  tft.setTextColor(0x00FF, 0xFFFF);
  tft.setTextSize(1);
  tft.setTextWrap(true);
  tft.print("Happy Birthday Arduino!");
}

void loop() {

}