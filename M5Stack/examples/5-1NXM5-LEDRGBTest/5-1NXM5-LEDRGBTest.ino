#include <M5Stack.h>
#include <FastLED.h>
#define DATA_PIN 15 // กำหนดขา
#define LED_TYPE WS2811 // เลือกเบอร์ LED 
#define COLOR_ORDER GRB // เลือกรูปแบบการแสดงสี
#define NUM_LEDS 64 // จำนวน LED ที่ต่อเข้าทั้งหมด
#define BRIGHTNESS 5 // ความสว่าง 0 - 255
CRGB leds[NUM_LEDS];  // สร้างตัวแปร leds มารองรับ
void setup() {
  M5.begin();
  M5.Lcd.setCursor(120, 110, 4);
  M5.Lcd.println("MATRIX");
  // กำหนดขาที่ต่อใช้งาน,รูปแบบสี,และจำนวน LED
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);  // กำหนดความสว่าง
}
void loop() {
  for (int i = 0; i < 64; i++) {
    leds[i] = CRGB(255, 0, 0);  // กำหนดสีแดง : CRGB(สีแดง,สีเขียว,สีน้ำเงิน) ค่าสี 0-255
  }
  FastLED.show(); // คำสั่งแสดงสี
  delay(500);
  for (int i = 0; i < 64; i++) {
    leds[i] = CRGB(0, 255, 0); // กำหนดสีเขียว
  }
  FastLED.show(); // คำสั่งแสดงสี
  delay(500);
  for (int i = 0; i < 64; i++) {
    leds[i] = CRGB(0, 0, 255);  // กำหนดสีน้ำเงิน
  }
  FastLED.show(); // คำสั่งแสดงสี
  delay(500);
  for (int i = 0; i < 64; i++) {
    leds[i] = CRGB(0, 0, 0); // กำหนดสีดำ
  }
  FastLED.show(); // คำสั่งแสดงสี
  delay(500);
}
