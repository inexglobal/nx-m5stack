#include <M5Stack.h>
void setup() {
  M5.begin();
  Serial2.begin(9600); // กำหนดอัตราส่ง 9600 bps 
  M5.Lcd.setCursor(100, 0, 4);
  M5.Lcd.print("RS-485");
}
void loop() {
  Serial2.print("AT+O1");//เปิดช่องสัญญาณ 1 
  delay(1000); //หน่วงเวลา 1 วินาที
  Serial2.print("AT+C1");//ปิดช่องสัญญาณ 1
  delay(1000);
}
