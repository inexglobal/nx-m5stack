#include <M5Stack.h>
#define ADC_ADDR 0x48
const float multiplier = 0.0001875F; // อัตราแรงดันต่อ 1 บิต = 0.1875mV
uint16_t InVoltage(uint8_t ch) { // ฟังก์ชันอ่านค่าอนาล็อก
  uint8_t data_L = 0;
  uint8_t data_H = 0;
  uint16_t data_adc = 0;
  Wire.beginTransmission(ADC_ADDR);
  Wire.write(0X01);
  Wire.write(0XC0 | (ch << 4));
  Wire.write(0X83);
  Wire.endTransmission();

  Wire.beginTransmission(ADC_ADDR);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(50);
  Wire.requestFrom(ADC_ADDR, 2);
  while (Wire.available()) {
    data_H = Wire.read();
    data_L = Wire.read();
  }
  data_adc = (data_H << 8) | data_L;
  return data_adc;
}
void setup() {
  M5.begin();
  Wire.begin();
  dacWrite(25, 0);
  M5.Lcd.setCursor(140, 0, 4);
  M5.Lcd.print("ADC");
}
uint16_t adc_ch0 = 0;
void loop() {
  adc_ch0 = InVoltage(0);  // อ่านค่าอนาล็อกช่อง 0
  M5.Lcd.setCursor(0, 100, 4);
  // แสดงค่าจริงที่อ่านได้และคำนวนหาแรงดันที่อ่านได้
  M5.Lcd.printf("CH0:%05d   \n Volt:%0.2fV  \n", adc_ch0 , adc_ch0 * multiplier);
  delay(500);
}
