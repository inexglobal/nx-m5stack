#include <M5Stack.h>
#define DAC_ADDR 0x4C
// ฟังก์ชันกำหนดแรงดังไฟฟ้าออกตามช่องสัญญาณที่เลือก
void outVoltage(uint8_t ch, uint16_t v) {
  Wire.beginTransmission(DAC_ADDR);
  Wire.write(0x10 | (ch << 1));
  Wire.write((v >> 2) & 0xff);
  Wire.write((v << 6) & 0xff);
  Wire.endTransmission();
}
void setup() {
  M5.begin();
  Wire.begin(21, 22);
  dacWrite(25, 0); //ปิดเสียงออกทางลำโพง
  M5.Lcd.setCursor(140, 0, 4);
  M5.Lcd.print("DAC");
  outVoltage(0, 256);  // กำหนดช่อง CH0 = 1.25V
  outVoltage(1, 512);  //กำหนดช่อง CH1 = 2.50V
  outVoltage(2, 768);  //กำหนดช่อง CH2 = 3.75V
  outVoltage(3, 1023); //กำหนดช่อง CH3 = 5.00v
  M5.Lcd.setCursor(40, 100, 4);
  M5.Lcd.println("ch0:1.25V ch1:2.50V");
  M5.Lcd.setCursor(40, 130, 4);
  M5.Lcd.println("ch2:3.75V ch3:5.00V");
}
void loop() {
  delay(200);
}
