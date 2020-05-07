#include <M5Stack.h>
#include <DHT12.h>
#include <Wire.h> //The DHT12 uses I2C comunication.
DHT12 dht12; //Preset scale CELSIUS and ID 0x5c.
void setup() {
  M5.begin();
  Wire.begin();
  dacWrite(25, 0); //ปิดเสียงออกทางลำโพง M5Stack
  M5.Lcd.clear(BLACK);
}
void loop() {
  float tmp = dht12.readTemperature(); // อ่านค่าอุณหภูมิ
  float hum = dht12.readHumidity();  // อ่านค่าความชื้น
  M5.Lcd.setTextColor(WHITE, BLACK); // กำหนดตัวอักษรสีขาว,พื้นหลังสีดำ
  M5.Lcd.setCursor(0, 0, 4);//กำหนดค่าเริ่มต้นที่จะแสดง x=0,y=0 และขนาดตัวอักษรเท่ากับ 4
  //แสดงค่าที่อ่านได้ออกทางหน้าจอ  M5Stack แบบกำหนดรูปแบบได้
  M5.Lcd.printf("Temp: %2.1f  \r\nHumi: %2.0f%%  \r\n", tmp, hum );
  delay(100);
}
