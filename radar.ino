#include <Servo.h>
#include <Ultrasonic.h>

#define TRIG 10
#define ECHO 11

Servo servo
Ultrasonic ultrasonic(TRIG, ECHO);

int a=0;
int dir=5;

void setup(){
  Serial.begin(9600);
  servo.attach(9);
  }
void loop(){
  long msec = ultrasonic.timing();
  float cm = ultrasonic.convert(msec, Ultrasonic::CM);

  a+=dir;

  if(a==0)dir=5;
  if(a==180)dir=-5;

  delay(100);
  }

