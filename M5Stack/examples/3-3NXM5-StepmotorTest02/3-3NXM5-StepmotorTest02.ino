#include <M5Stack.h>
const int MOTOR_A = 2;
const int MOTOR_B = 5;
const int MOTOR_C = 12;
const int MOTOR_D = 13;
const int pinMotor[2][4] = {{MOTOR_A, MOTOR_B, MOTOR_C, MOTOR_D},
  {MOTOR_D, MOTOR_C, MOTOR_B, MOTOR_A}
};
const byte logic[4][4] = {{1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};
int count;
void setup() {
  M5.begin();
  pinMode(pinMotor[0][0], OUTPUT);
  pinMode(pinMotor[0][1], OUTPUT);
  pinMode(pinMotor[0][2], OUTPUT);
  pinMode(pinMotor[0][3], OUTPUT);
}
void loop() {
  for (int i = 0 ; i < 2048; i++) //2048 = 1รอบ 360 องศา
    driveMotor(0); // หมุนตามเข็มนาฬิกา
    delay(2000);
  for (int i = 0 ; i < 2048; i++)
    driveMotor(1); // ทวนเข็มนาฬิกา
    delay(2000);

}
void driveMotor(int direct) {
  count++;
  int step = count % 4;
  digitalWrite(pinMotor[direct][0], logic[step][0]);
  digitalWrite(pinMotor[direct][1], logic[step][1]);
  digitalWrite(pinMotor[direct][2], logic[step][2]);
  digitalWrite(pinMotor[direct][3], logic[step][3]);
  delay(2); // ค่าเวลาระยะห่างระหว่าง 1 สเต็ปที่เร็วที่สุดที่ใช้งานได้ 0.02 วินาที
}
