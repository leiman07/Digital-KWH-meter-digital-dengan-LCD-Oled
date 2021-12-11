#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#include <PZEM004Tv30.h>
PZEM004Tv30 pzem(D3, D4);
void setup() {
Serial.begin(115200);
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

}
void loop() {
float voltage = pzem.voltage();
float current = pzem.current();
float power = pzem.power();
float energy = pzem.energy();
float frequency = pzem.frequency();
float pf = pzem.pf();
  display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(voltage);
  display.print("V");
  display.setCursor(0, 24);
  display.print(current);
  display.print("A");
  display.setCursor(0, 45);
  display.print(power);
  display.print("W");
  display.display();
delay(2000);
}

//PROJECT : Program Digital KWH Meter dengan OLED 128X64
//DIBUAT  : TRIDIPI.PROJECT
//TANGGAL : 07/12/2021

