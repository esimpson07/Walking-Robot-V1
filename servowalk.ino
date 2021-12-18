#include "HCPCA9685.h"
#define  i2cport 0x40
HCPCA9685 HCPCA9685(i2cport);

double servoSpeed = 180;
double distance = 40;

double s1c = 90;
double s1t = 45;
double s2c = 90;
double s2t = 90;
double s3c = 90;
double s3t = 90;
double s4c = 90;
double s4t = 45;
double s5c = 90;
double s5t = 90;
double s6c = 90;
double s6t = 90;
double s7c = 90;
double s7t = 45;
double s8c = 90;
double s8t = 90;
double s9c = 90;
double s9t = 90;
double s10c = 90;
double s10t = 45;
double s11c = 90;
double s11t = 90;
double s12c = 90;
double s12t = 90;

int cycle = 0;
long pastTime = 0;
long currentTime = 0;
long delayTime = 12;

void s1walk(){
  if (s1c > s1t + servoSpeed){
    s1c -= servoSpeed;
  } else if (s1c < s1t - servoSpeed){
    s1c += servoSpeed;
  }
  if (s1c > 180){
    s1c = 180;
  } else if (s1c < 0){
    s1c = 0;
  }
  if (s1c + servoSpeed > s1t && s1c - servoSpeed < s1t){
    s1c = s1t;
  }
}

void s2walk(){
  if (s2c > s2t + servoSpeed){
    s2c -= servoSpeed;
  } else if (s2c < s2t - servoSpeed){
    s2c += servoSpeed;
  }
  if (s2c > 180){
    s2c = 180;
  } else if (s2c < 0){
    s2c = 0;
  }
  if (s2c + servoSpeed > s2t && s2c - servoSpeed < s2t){
    s2c = s2t;
  }
}

void s3walk(){
  if (s3c > s3t + servoSpeed){
    s3c -= servoSpeed;
  } else if (s3c < s3t - servoSpeed){
    s3c += servoSpeed;
  }
  if (s3c > 180){
    s3c = 180;
  } else if (s3c < 0){
    s3c = 0;
  }
  if (s3c + servoSpeed > s3t && s3c - servoSpeed < s3t){
    s3c = s3t;
  }
}

void s4walk(){
  if (s4c > s4t + servoSpeed){
    s4c -= servoSpeed;
  } else if (s4c < s4t - servoSpeed){
    s4c += servoSpeed;
  }
  if (s4c > 180){
    s4c = 180;
  } else if (s4c < 0){
    s4c = 0;
  }
  if (s4c + servoSpeed > s4t && s4c - servoSpeed < s4t){
    s4c = s4t;
  }
}

void s5walk(){
  if (s5c > s5t + servoSpeed){
    s5c -= servoSpeed;
  } else if (s5c < s5t - servoSpeed){
    s5c += servoSpeed;
  }
  if (s5c > 180){
    s5c = 180;
  } else if (s5c < 0){
    s5c = 0;
  }
  if (s5c + servoSpeed > s5t && s5c - servoSpeed < s5t){
    s5c = s5t;
  }
}

void s6walk(){
  if (s6c > s6t + servoSpeed){
    s6c -= servoSpeed;
  } else if (s6c < s6t - servoSpeed){
    s6c += servoSpeed;
  }
  if (s6c > 180){
    s6c = 180;
  } else if (s6c < 0){
    s6c = 0;
  }
  if (s6c + servoSpeed > s6t && s6c - servoSpeed < s6t){
    s6c = s6t;
  }
}

void s7walk(){
  if (s7c > s7t + servoSpeed){
    s7c -= servoSpeed;
  } else if (s7c < s7t - servoSpeed){
    s7c += servoSpeed;
  }
  if (s7c > 180){
    s7c = 180;
  } else if (s7c < 0){
    s7c = 0;
  }
  if (s7c + servoSpeed > s7t && s7c - servoSpeed < s7t){
    s7c = s7t;
  }
}

void s8walk(){
  if (s8c > s8t + servoSpeed){
    s8c -= servoSpeed;
  } else if (s8c < s8t - servoSpeed){
    s8c += servoSpeed;
  }
  if (s8c > 180){
    s8c = 180;
  } else if (s8c < 0){
    s8c = 0;
  }
  if (s8c + servoSpeed > s8t && s8c - servoSpeed < s8t){
    s8c = s8t;
  }
}

void s9walk(){
  if (s9c > s9t + servoSpeed){
    s9c -= servoSpeed;
  } else if (s9c < s9t - servoSpeed){
    s9c += servoSpeed;
  }
  if (s9c > 180){
    s9c = 180;
  } else if (s9c < 0){
    s9c = 0;
  }
  if (s9c + servoSpeed > s9t && s9c - servoSpeed < s9t){
    s9c = s9t;
  }
}

void s10walk(){
  if (s10c > s10t + servoSpeed){
    s10c -= servoSpeed;
  } else if (s10c < s10t - servoSpeed){
    s10c += servoSpeed;
  }
  if (s10c > 180){
    s10c = 180;
  } else if (s10c < 0){
    s10c = 0;
  }
  if (s10c + servoSpeed > s10t && s10c - servoSpeed < s10t){
    s10c = s10t;
  }
}

void s11walk(){
  if (s11c > s11t + servoSpeed){
    s11c -= servoSpeed;
  } else if (s11c < s11t - servoSpeed){
    s11c += servoSpeed;
  }
  if (s11c > 180){
    s11c = 180;
  } else if (s11c < 0){
    s11c = 0;
  }
  if (s11c + servoSpeed > s11t && s11c - servoSpeed < s11t){
    s11c = s11t;
  }
}

void s12walk(){
  if (s12c > s12t + servoSpeed){
    s12c -= servoSpeed;
  } else if (s12c < s12t - servoSpeed){
    s12c += servoSpeed;
  }
  if (s12c > 180){
    s12c = 180;
  } else if (s12c < 0){
    s12c = 0;
  }
  if (s12c + servoSpeed > s12t && s12c - servoSpeed < s12t){
    s12c = s12t;
  }
}

/*int sRaise = 135;
int c2 = 0;
int sHeight = 45;
int c4 = 45;
int c5 = 90;*/

int sChange = 1.66;
int sRaise = 170;
int sHeight = 60;
int sMid = sHeight;

void FRmove(){
  if(cycle >= 0 && cycle < 13){
    s2t = sRaise;
  } else if(cycle >= 13 && cycle < 25){
    s3t = sMid - (distance * sChange);
  } else if(cycle >= 25 && cycle < 50){
    s2t = sHeight;
  } else if(cycle >= 100 && cycle < 125){
    s3t = sMid;
  } else if(cycle >= 150 && cycle < 175){
    s3t = sMid + distance;
  }
}

void FLmove(){
  if(cycle >= 0 && cycle < 25){
    s6t = sMid + (distance * sChange);
  } else if(cycle >= 50 && cycle < 63){
    s5t = sRaise;
  } else if(cycle >= 63 && cycle < 75){
    s6t = sMid - distance;
  } else if(cycle >= 75 && cycle < 100){
    s5t = sHeight;
  } else if(cycle >= 150 && cycle < 175){
    s6t = sMid;
  }
}

void BLmove(){
  if(cycle < 25 && cycle >= 0){
    s12t = sMid;
  } else if(cycle >= 50 && cycle < 75){
    s12t = sMid - distance;
  } else if(cycle >= 100 && cycle < 113){
    s11t = sRaise;
  } else if(cycle >= 113 && cycle < 125){
    s12t = sMid + (distance * sChange);
  } else if(cycle >= 125 && cycle < 150){
    s11t = sHeight;
  }
}

void BRmove(){
  if(cycle >= 175 && cycle < 200){
    s8t = sHeight; //70
  } else if(cycle >= 50 && cycle < 75){
    s9t = sMid; //90
  } else if(cycle >= 100 && cycle < 125){
    s9t = sMid - distance; //45
  } else if(cycle >= 150 && cycle < 163){
    s8t = sRaise; //135
  } else if(cycle >= 163 && cycle < 175){
    s9t = sMid + (distance * sChange); //135
  }
}

void servoUpdate(){
  HCPCA9685.Servo(1, (180 - s1c) * 2.2888);
  HCPCA9685.Servo(2, (180 - s2c) * 2.2888);
  HCPCA9685.Servo(3, (180 - s3c) * 2.2888);
  HCPCA9685.Servo(5, s7c * 2.2888);
  HCPCA9685.Servo(6, s8c * 2.2888);
  HCPCA9685.Servo(7, s9c * 2.2888);
  HCPCA9685.Servo(9, (180 - s10c) * 2.2888);
  HCPCA9685.Servo(10, (180 - s11c) * 2.2888);
  HCPCA9685.Servo(11, (180 - s12c) * 2.2888);
  HCPCA9685.Servo(13, s4c * 2.2888);
  HCPCA9685.Servo(14, s5c * 2.2888);
  HCPCA9685.Servo(15, s6c * 2.2888);
  s1walk();
  s2walk();
  s3walk();
  s4walk();
  s5walk();
  s6walk();
  s7walk();
  s8walk();
  s9walk();
  s10walk();
  s11walk();
  s12walk();
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(5);
  HCPCA9685.Init(SERVO_MODE);
  HCPCA9685.Sleep(false);
}

void loop() {
  currentTime = millis();
  servoUpdate();
  FRmove();
  FLmove();
  BRmove();
  BLmove();
  Serial.println(cycle);
  if (pastTime + delayTime <= currentTime){
    cycle ++;
    if(cycle > 200){
      cycle = 0;
    }
    pastTime = currentTime;
  }
}
