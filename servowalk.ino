#include "HCPCA9685.h"
#define  i2cport 0x40
#include <Wire.h>
#include <MPU6050.h>
#include <ESP8266WiFi.h>
#define SERVERMODE 0
#define BAUD_SERIAL 115200
#define RXBUFFERSIZE 1024
#define STACK_PROTECTOR  512 // bytes
#define MAX_SRV_CLIENTS 2

MPU6050 mpu;
HCPCA9685 HCPCA9685(i2cport);

const int port = 23;
WiFiServer server(port);
WiFiClient serverClients[MAX_SRV_CLIENTS];

#if SERVERMODE
const char* ssid = "PandoraAccessPoint";
const char* password = "b8070ecd10cd20";
#else
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
String id = "ESPsoftAP_10";
String pw = "Soft_AP_PW";
#endif
String sbuf;
double val1;
double val2;

double s1c = 90;
double s1t = 55;
double s2c = 90;
double s2t = 90;
double s3c = 90;
double s3t = 90;
double s4c = 90;
double s4t = 55;
double s5c = 90;
double s5t = 90;
double s6c = 90;
double s6t = 90;
double s7c = 90;
double s7t = 55;
double s8c = 90;
double s8t = 90;
double s9c = 90;
double s9t = 90;
double s10c = 90;
double s10t = 60;
double s11c = 90;
double s11t = 90;
double s12c = 90;
double s12t = 90;

double wSpeed = 0;
double tSpeed = 0;
double servoSpeed = 6 * (abs(wSpeed) + 0.1); //orignally 2
double distance = wSpeed * 35;
long delayTime = 15 - (abs(wSpeed) * 14);
long cycle = 0;
long pastTime = 0;
long currentTime = 0;
int sChange = 1.5; // originally 1.5
int sHeight = 50;
int sRaise = sHeight + 35;
int sMid = sHeight;
int sTurnAngle = 55;
int turn = tSpeed * 60;

//All s1, s2, s3 etc. all are servos on the robot
//s1, s4, s7, and s10 are all the turn servos
//s2, s5, s8, s11 are first joint servos
//s3, s6, s9, s12 are all foot actuation servos
//All servo walk methods are called in the loop to add the number to the servo postion
//Servoupdate tells the servos to all move in the PCA9685 servo driver

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

void FRmove(){
  if(cycle >= 0 && cycle < 13){
    s2t = sRaise;
    s1t = sTurnAngle - (turn * 2);
  } else if(cycle >= 13 && cycle < 25){
    s3t = sMid - (distance * sChange);
    s1t = sTurnAngle + (turn * 2);
  } else if(cycle >= 25 && cycle < 50){
    s2t = sHeight;
  } else if(cycle >= 75 && cycle < 100){
    s1t = sTurnAngle + turn;
  }else if(cycle >= 100 && cycle < 125){
    s3t = sMid;
    s1t = sTurnAngle;
  } else if(cycle >= 150 && cycle < 175){
    s3t = sMid + distance;
    s1t = sTurnAngle - turn;
  }
}

void FLmove(){
  if(cycle < 25 && cycle >= 0){
    s6t = sMid;
    s4t = sTurnAngle;
  } else if(cycle >= 50 && cycle < 75){
    s6t = sMid + distance;
    s4t = sTurnAngle + turn;
  } else if(cycle >= 100 && cycle < 113){
    s5t = sRaise;
    s4t = sTurnAngle + (turn * 2);
  } else if(cycle >= 113 && cycle < 125){
    s6t = sMid - (distance * sChange);
    s4t = sTurnAngle - (turn * 2);
  } else if(cycle >= 125 && cycle < 150){
    s5t = sHeight;
  } else if(cycle >= 150 && cycle < 175){
    s4t = sTurnAngle - turn;
  }
}

void BRmove(){
  if(cycle >= 175 && cycle < 200){
    s8t = sHeight; //70
  } else if(cycle >= 0 && cycle < 25){
    s7t = sTurnAngle - turn;
  } else if(cycle >= 50 && cycle < 75){
    s9t = sMid; //90
    s7t = sTurnAngle;
  } else if(cycle >= 100 && cycle < 125){
    s9t = sMid - distance; //45
    s7t = sTurnAngle + turn;
  } else if(cycle >= 150 && cycle < 163){
    s8t = sRaise; //135
    s7t = sTurnAngle + (turn * 2);
  } else if(cycle >= 163 && cycle < 175){
    s9t = sMid + (distance * sChange); //135
    s7t = sTurnAngle - (turn * 2);
  }
}

void BLmove(){
  if(cycle >= 0 && cycle < 25){
    s12t = sMid - distance;
    s10t = sTurnAngle - turn;
  } else if(cycle >= 50 && cycle < 63){
    s11t = sRaise;
    s10t = sTurnAngle - (turn * 2);
  } else if(cycle >= 63 && cycle < 75){
    s12t = sMid + (distance * sChange);
    s10t = sTurnAngle + (turn * 2);
  } else if(cycle >= 75 && cycle < 100){
    s11t = sHeight;
  } else if(cycle >= 100 && cycle < 125){
    s10t = sTurnAngle + turn;
  } else if(cycle >= 150 && cycle < 175){
    s12t = sMid;
    s10t = sTurnAngle;
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
    // Initialize MPU6050
  Serial.println("Initialize MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  mpu.calibrateGyro();
  mpu.setThreshold(3);
  checkSettings();
  
  #if SERVERMODE
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  
  Serial.println();
  Serial.print("connected, address=");
  Serial.println(WiFi.localIP());
  #else
  Serial.print("Setting soft-AP ... ");
  boolean result = WiFi.softAP(id, pw);
  if(result == true)
  {
    WiFi.softAPConfig(local_ip, gateway, subnet);
    Serial.println("Wifi Ready");
  }
  else
  {
    Serial.print("WiFi Failed: ");
    Serial.println(result);
  }

  #endif

  server.begin();
  server.setNoDelay(true);
}

void checkSettings()
{
  Serial.println();
  
  Serial.print(" * Sleep Mode:        ");
  Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");
  
  Serial.print(" * Clock Source:      ");
  switch(mpu.getClockSource())
  {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }
  
  Serial.print(" * Gyroscope:         ");
  switch(mpu.getScale())
  {
    case MPU6050_SCALE_2000DPS:        Serial.println("2000 dps"); break;
    case MPU6050_SCALE_1000DPS:        Serial.println("1000 dps"); break;
    case MPU6050_SCALE_500DPS:         Serial.println("500 dps"); break;
    case MPU6050_SCALE_250DPS:         Serial.println("250 dps"); break;
  } 
  
  Serial.print(" * Gyroscope offsets: ");
  Serial.print(mpu.getGyroOffsetX());
  Serial.print(" / ");
  Serial.print(mpu.getGyroOffsetY());
  Serial.print(" / ");
  Serial.println(mpu.getGyroOffsetZ());
  
  Serial.println();
}

void sRun(){
  if (server.hasClient()) {
    for (int i = 0; i < MAX_SRV_CLIENTS; i++) {
      if (!serverClients[i]) {
        serverClients[i] = server.available();
        Serial.print("New client idx: ");
        Serial.println(i);
        break;
      }

      if (i >= MAX_SRV_CLIENTS) {
        server.available().println("no sessions available");
        Serial.print("Server exceeded max connections: ");
        Serial.println(MAX_SRV_CLIENTS);
      }
    }
  }

  for (int i = 0; i < MAX_SRV_CLIENTS; i++) {
    while (serverClients[i].available()) {
      size_t maxToSerial = std::min(serverClients[i].available(), Serial.availableForWrite());
      maxToSerial = std::min(maxToSerial, (size_t)STACK_PROTECTOR);
      uint8_t buf[maxToSerial];
      size_t tcp_got = serverClients[i].read(buf, maxToSerial);

      sbuf = String((char*)buf);

      //serverClients[i].println("0");
      if (sbuf.length() > 0 && sbuf.substring(0,1) != 0) {
        val1 = sbuf.substring(0,2).toInt();
        val2 = sbuf.substring(2,4).toInt();
        wSpeed = (val1 - 40) / 40;
        tSpeed = (val2 - 40);
        serverClients[i].print("walkSpeed = ");
        serverClients[i].println(wSpeed);
        serverClients[i].print("wSpeed = ");
        serverClients[i].print("turnspeed = ");
        serverClients[i].println(tSpeed);
        Serial.println(wSpeed);
        Serial.println(val1);
        Serial.println((val1 - 40) / 40);
      }

      
    }
  }
}

void loop() {
  servoSpeed = 6 * (abs(wSpeed) + 0.1); //orignally 2
  distance = wSpeed * 35;
  delayTime = 15 - (abs(wSpeed) * 14);
  turn = tSpeed;
  if(wSpeed < 0){
    sChange = 1;
    if(distance > 20){
      distance = 20;
    }
  } else {
    sChange = 1.5;
  }
  sRun();
  currentTime = millis();
  servoUpdate();
  FRmove();
  FLmove();
  BRmove();
  BLmove();
  if (pastTime + delayTime <= currentTime){
    cycle ++;
    if(cycle > 200){
      cycle = 0;
    }
    pastTime = currentTime;
  }
  
  /*Vector rawGyro = mpu.readRawGyro();
  Serial.print(" Xraw = ");
  Serial.print(rawGyro.XAxis);
  Serial.print(" Yraw = ");
  Serial.print(rawGyro.YAxis);
  Serial.print(" Zraw = ");
  Serial.println(rawGyro.ZAxis);*/
}
