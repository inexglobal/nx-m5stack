#include <M5Stack.h>
#include "driver/ledc.h"
const int servo_pin = 15; // กำหนดขา 15
int freq = 50; // ความถี่ 50 Hz
int ledChannel = 0; // ใช้ช่องสัญญาณที่ 0 (0 -7)
int resolution = 10; // กำหนดความละเอียด 10 บิต 0 - 1023
void setup() {
  M5.begin();
  M5.Lcd.setCursor(120, 110, 4);
  M5.Lcd.println("SERVO");
  ledcSetup(ledChannel, freq, resolution);//กำหนดช่องสัญญาณ,ความถี่,ความละเอียด
  ledcAttachPin(servo_pin, ledChannel);//กำหนดขาที่ใช้งานให้กับช่องสัญญาณ
}
void loop() {
  ledcWrite(ledChannel, 26);//กำหนดสัญญาน PWM ด้วยค่า 26 คือ 0 องศานั้นเอง
  delay(1000);
  ledcWrite(ledChannel, 76);//90°
  delay(1000);
  ledcWrite(ledChannel, 127);//180°
  delay(1000);
}
