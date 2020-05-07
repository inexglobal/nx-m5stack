#include <M5Stack.h>
const int phaseA = 2;
const int phaseB = 13;
const int Button = 15;
#define GET_CODE() uint8_t(digitalRead(phaseA) << 4 | digitalRead(phaseB)) // ฟังก์ชันอ่านสถานะสัญญาณ Encode
int32_t count_change = 0;
uint8_t code = 0;
uint8_t code_old = 0;
void encoderEvent() { // ฟังก์ชันนับเมื่อเกิดเหตุการณ์หมุน Encoder
  code = GET_CODE();
  if (code != code_old) {
    if (code == 0x00) {
      if (code_old == 0x10) { //ตรวจสอบทิศทางการหมุน
        count_change--;  //ลดค่าลงเมื่อหมุนทวนเข็มนาฬิกา
      } else {
        count_change++; //เพิ่มค่าขึ้นเมื่อหมุนตามเข็มนาฬิกา
      }
    }
    code_old = code;
  }
}
void setup() {
  // put your setup code here, to run once:
  M5.begin();
  pinMode(phaseA, INPUT_PULLUP);
  pinMode(phaseB, INPUT_PULLUP);
  pinMode(Button, INPUT_PULLUP);
  dacWrite(25, 0);
  M5.Lcd.setCursor(100, 0, 4);
  M5.Lcd.print("ENCODER");
  code = GET_CODE();
  code_old = code;
}
void loop() {
  uint8_t value = digitalRead(Button); // อ่านค่าปุ่มกดของตัว Encoder
  encoderEvent(); // เรียกใช้ฟังก์ชันอ่านค่า Encoder
  M5.Lcd.setCursor(30, 120, 4);
  // แสดงค่าการหมุนและสถานะกดปุ่ม
  M5.Lcd.printf("code = %05d,button = %d\r\n ", count_change, value);
  delay(1);
}
