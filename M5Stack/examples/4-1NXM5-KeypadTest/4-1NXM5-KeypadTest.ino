#include<M5Stack.h>
#include <Keypad.h>
const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns
byte rowPins[ROWS] = {17, 16, 21, 22}; //กำหนดขา GPIO ชุด  Rows
byte colPins[COLS] = {5, 12, 13, 15}; //กำหนดขา GPIO ชุด  Columns
// สร้างตัวอักษรประจำปุ่มกด
char keys[ROWS][COLS] = {
  {'a', 'b', 'c', 'd'},
  {'e', 'f', 'g', 'h'},
  {'i', 'j', 'k', 'l'},
  {'m', 'n', 'o', 'p'}
};
// สร้างตัวแปร keypad มารองรับการกำหนดคุณสมบัติของ keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() {
  M5.begin();
  M5.Lcd.setCursor(100, 0, 4);
  M5.Lcd.println("KEYBOARD");
  M5.Lcd.setCursor(0, 140, 4);
}
void loop() {
  char key = keypad.getKey(); // อ่านค่าตัวอักษรแต่ละปุ่มกดมาเก็บไว้ในตัวแปร key
  if (key) { // ตรวจสอบการกดปุ่ม
    M5.Lcd.print(key); // แสดงค่าตัวอักษรออกทางหน้าจอ
  }
}
