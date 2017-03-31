#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing....");

  tft.begin();
  // rotate 270 degree clockwise
  tft.setRotation(3);
}

void loop() {
  tft.fillScreen(0xFFFF);
  tft.drawLine(0, 0, tft.width(), tft.height(), 0x0000);
  delay(3000);

  tft.fillScreen(0xFFFF);
  tft.drawCircle(tft.width()/2, tft.height()/2, 30, 0x0000);
  tft.fillCircle(tft.width()/2, tft.height()/2, 30, 0xFAAF);
  delay(3000);

  tft.fillScreen(0xFFFF);
  tft.drawRect(30, 30, 50, 50, 0xFF03);
  tft.fillRect(30, 30, 50, 50, 0xFF03);
  delay(3000);

  tft.fillScreen(0xFFFF);
  tft.drawRoundRect(30, 30, 80, 50, 15, 0xFF03);
  tft.fillRoundRect(30, 30, 80, 50, 15, 0xFF03);
  delay(3000);

  tft.fillScreen(0xFFFF);
  tft.drawTriangle(30, 80, 60, 10, 180, 100, 0xAFAF);
  tft.fillTriangle(30, 80, 60, 10, 180, 100, 0xAFAF);
  delay(3000);

  tft.fillScreen(0xFFFF);
  tft.drawChar(tft.width()/2 - 30, tft.height()/2 - 30, 'X', 0xAFFA, 0xFFFF, 10);
  delay(3000);

  tft.fillScreen(0xFFFF);
  tft.setCursor(20, tft.height()/2 - 10);
  tft.setTextColor(0x00FF, 0xFFFF);
  tft.setTextSize(2);
  tft.setTextWrap(true);
  tft.print("Happy Birthday Arduino!");
  delay(3000);

}