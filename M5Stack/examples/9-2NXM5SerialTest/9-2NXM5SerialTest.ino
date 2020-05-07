#include <M5Stack.h>
void setup() {
  M5.begin();
  Serial.begin(115200); //กำหนดอัตราส่งข้อมูล 115200 bps
  M5.Lcd.setCursor(100, 0, 4);
  M5.Lcd.print("Serial");
}
int x , y = 0;
void loop() {
  if (Serial.available()) {
    String topic = "";
    String msg = "";
    while (Serial.available()) { //;วนทำซ้ำจนกว่าจะอ่านข้อมูลเสร็จ
      //อ่านและเก็บเฉพาะข้อความที่มีเครื่องหมาย = อยู่ด้านหลังข้อความ
      topic = Serial.readStringUntil('=');
      //อ่านและเก็บเฉพาะข้อความที่ \n  อยู่ด้านหลังข้อความ (\n หมายถึงขึ้นบรรทัดใหม่)
      msg = Serial.readStringUntil('\n');
      msg.trim(); //ตัดช่องว่างหัวและท้ายข้อความออก
    }
    if (topic == "x") {
      x = msg.toInt(); //เปลี่ยนข้อความให้เป็นตัวเลข
    }
    if (topic == "y") {
      y = msg.toInt(); //เปลี่ยนข้อความให้เป็นตัวเลข
    }
    M5.Lcd.setCursor(0, 40, 4);
    //แสดงผลลัพธ์ออกทางหน้าจอ
    M5.Lcd.printf("x = %d \ny = %d  \nsum= %d \n", x, y, x + y);
    //แสดงผลลัพธ์ไปยัง Serila Monitor
    Serial.printf("x = %d \ny = %d  \nsum= %d \n", x, y, x + y);
  }
  delay(1000);
}
