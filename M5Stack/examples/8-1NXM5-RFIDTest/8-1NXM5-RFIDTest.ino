#include <Wire.h>
#include <MFRC522_I2C.h>
#include <M5Stack.h>
// 0x28 is i2c address on SDA. Check your address with i2cscanner if not match.
MFRC522 mfrc522(0x28);   // Create MFRC522 instance.
void setup() {
  M5.begin();
  Wire.begin();
  M5.Lcd.setCursor(140, 0, 4);
  M5.Lcd.println("RFID");
  mfrc522.PCD_Init();             // Init MFRC522
  M5.Lcd.setCursor(0, 30, 2);
  M5.Lcd.println("Scan PICC to see UID");
}
void loop() {
  // Look for new cards, and select one if present
  if (!mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()) { // ตรวจสอบการแตะ tag
    delay(50);
    return; // ถ้าไม่มี tag มาแตะให้กระโดดไปทำงานที่บรรทัดเรียก ของ void loop()
  }
  M5.Lcd.setCursor(0, 100, 4);
  String ID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    ID += String(mfrc522.uid.uidByte[i], HEX); // อ่านค่า UID มาเก็บไว้ในตัวแปร ID
  }
  M5.Lcd.printf("UID: %s   ", ID); // แสดง ID ออกทางหน้าจอ
  M5.Speaker.tone(500); //ส่งเสียงอกกทางลำโพง M5Stack ด้วยความถี่ 500 Hz
  delay(250);  // หน่วงเวลาไว้ 0.25 วินาที
  M5.Speaker.mute();  // เปิดเสียง
}
