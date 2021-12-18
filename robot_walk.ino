#include <Servo.h>
double servoSpeed = 0;
double servoTarget = 180;
double servoPos = 0;

double sFRUpos = 0;
double sFRUtarget = 0;

double sFLUpos = 0;
double sFLUtarget = 0;

double sFRLpos = 0;
double sFRLtarget = 0;

double sFLLpos = 0;
double sFLLtarget = 0;

double sBRUpos = 0;
double sBRUtarget = 0;

double sBLUpos = 0;
double sBLUtarget = 0;

double sBRLpos = 0;
double sBRLtarget = 0;

double sBLLpos = 0;
double sBLLtarget = 0;

double walk(double servoSpeed,double servoTarget){
  if (servoPos > servoTarget + servoSpeed){
    servoPos -= servoSpeed;
  } else if (servoPos < servoTarget - servoSpeed){
    servoPos += servoSpeed;
  }
  if (servoPos > 180){
    servoPos = 180;
  } else if (servoPos < 0){
    servoPos = 0;
  }
  return(servoPos);
}
void setup() {
  //myservo.attach();
  Serial.begin(1000000);
}
void loop() {
  sFRUpos = walk(0.01,0);
  sFRLpos = walk(0.01,180);
  Serial.println(sFRUpos);
}
