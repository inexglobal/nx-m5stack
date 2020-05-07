#include <M5Stack.h>
void setup() {
  M5.begin();
  Serial2.begin(115200); //กำหนดอัตราส่งข้อมูล 115200 bps
  M5.Lcd.setCursor(100, 0, 4);
  M5.Lcd.print("RS-232");
}
int rx_num = 0;
void loop() {
  if (Serial2.available()) { //ตรวจสอบว่ามีข้อมูลส่งเข้ามา
    int ch = Serial2.read(); //อ่านค่าที่รับเข้ามาเก็บไว้ในตัวแปร ch
    if (ch == 'a') { //ตรวจสอบข้อมูลที่เข้ามามีค่าเท่ากับ a หรือไม่
      rx_num++;  // เพิ่มค่าตัวแปร rx_num ทีละ 1 ค่า
    }
    M5.Lcd.setCursor(30, 120, 4);
    M5.Lcd.printf("rx_num = %d\n", rx_num); //แสดงค่าตัวแปร rx_num ออกทางหน้าจอ
  }
  Serial2.write('a'); // ส่งตัวอักษร a ออกทาง Serial
  delay(1000);
}
