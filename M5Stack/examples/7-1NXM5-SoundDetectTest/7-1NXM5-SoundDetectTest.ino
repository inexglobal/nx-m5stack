#include <M5Stack.h> //ผนวกไลบรารี
const int Analog = 36;
const int Digtal = 2;
void setup() {
  M5.begin();
  pinMode(Digtal, INPUT_PULLUP);
  dacWrite(25, 0); // ปิดเสียงออกลำโพง
  M5.Lcd.setCursor(100, 0, 4); // กำหนดตำแหน่งเริ่มต้นบนหน้าจอ x= 100 ,y=0 ตัวอักษรขนาด 4
  M5.Lcd.print("MICROPHONE"); // แสดงข้อความ
}
void loop() {
  uint16_t a_data = analogRead(Analog); // อ่านแอนาล็อก
  uint16_t d_data = digitalRead(Digtal); // อ่านค่าดิจิตอล
  Serial.printf("Analog:%0d Digtal:%0d\n", a_data, d_data); // ส่งค่าออกทาง Serial
  M5.Lcd.setCursor(30, 120, 4); // กำหนดตำแหน่งเริ่มต้นบนหน้าจอ x= 30 ,y=120 ตัวอักษรขนาด 4
  M5.Lcd.printf("Analog:%0d Digtal:%0d  \n", a_data, d_data); // แสดงข้อความค่าที่อ่านได้
  delay(200);
}
