#include <M5Stack.h>
void setup() {
  M5.begin(true, false, true); // init lcd, serial, but don't init sd card
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(65, 10);
  M5.Lcd.println("DC motor example");
  M5.Lcd.setCursor(30, 220);
  M5.Lcd.println("Forward");
  M5.Lcd.setCursor(140, 220);
  M5.Lcd.println("stop");
  M5.Lcd.setCursor(220, 220);
  M5.Lcd.println("Reverse");
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
}
void loop() {
  M5.update(); //ฟังชันก์ค่อยปรับปรุงค่าสถานะการกดปุ่มบน M5Stack
  if (M5.BtnA.wasReleased()) { //ตรวจสอบการกดปุ่ม  A
    digitalWrite(22, LOW);
    digitalWrite(21, HIGH);
  } else if (M5.BtnB.wasReleased()) { //ตรวจสอบการกดปุ่ม  B
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
  } else if (M5.BtnC.wasReleased()) { //ตรวจสอบการกดปุ่ม  C
    digitalWrite(21, LOW);
    digitalWrite(22, HIGH);
  }
}
