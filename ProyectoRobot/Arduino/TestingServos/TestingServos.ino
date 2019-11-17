#include <Servo.h>
Servo s1;
//Servo s2;
//Servo s3;
//Servo s4;
//Servo s5;


void setup() {
  // put your setup code here, to run once:
  s1.attach(5);
  //s2.attach(6);
  //s3.attach(9);
  //s4.attach(10);
  //s5.attach(11);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  s1.write(45);
  /*
  s2.write(45);
  s3.write(45);
  s4.write(45);
  s5.write(45);*/
  delay(2000);
  s1.write(90);/*
  s2.write(90);
  s3.write(90);
  s4.write(90);
  s5.write(90);*/
  delay(2000);
  s1.write(135);
  delay(2000);
}
