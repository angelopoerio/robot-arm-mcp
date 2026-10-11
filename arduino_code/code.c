#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 125  
#define SERVOMAX 625  
#define INITIAL_POSITION 90

#define SERVO_0 0
#define SERVO_1 1
#define SERVO_2 2
#define SERVO_3 3
#define SERVO_4 4 

void setup() {
  Serial.begin(9600);
  board1.begin();
  board1.setPWMFreq(60); 
  board1.setPWM(SERVO_0, 0, angleToPulse(INITIAL_POSITION));
  board1.setPWM(SERVO_1, 0, angleToPulse(INITIAL_POSITION));
  board1.setPWM(SERVO_2, 0, angleToPulse(INITIAL_POSITION));
  board1.setPWM(SERVO_4, 0, angleToPulse(INITIAL_POSITION));
  board1.setPWM(SERVO_3, 0, angleToPulse(180));
}

void loop() {
  int joint_index, degree;
  char printBuf[100];
  while (Serial.available() == 0) {}
  String cmdStr = Serial.readString();
  Serial.println(cmdStr);
  cmdStr.trim(); 
  sscanf(cmdStr.c_str(), "%d %d", &joint_index, &degree);
  sprintf(printBuf, "Moving join:%d degree:%d", joint_index, degree);
  Serial.println(printBuf);
  board1.setPWM(joint_index, 0, angleToPulse(degree));
}

int angleToPulse(int ang) {
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX);
  return pulse;
}
