#ifndef PAKAN_H
#define PAKAN_H

#include <ESP32Servo.h>
#include <Wire.h>
#include <Arduino.h>
#include "veml.h"

int minute;
int jam;
int waktu[] = {7, 12, 17};
bool x = true;
int jp = 3;
Servo myservo;
int pos = 0;
int servoPin = 33;

void tuang_pakan(int jp) {
  for (int i = 1; i <= jp; i++) {
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);
  }
}

void pakanSETUP() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 500, 2400);
}

void kontrolPakan() {
  minute = timeClient.getMinutes();
  jam = timeClient.getHours();

  for (int b = 0; b < 3; b++) {
    if (jam == waktu [b] && minute == 00 && x == true) {
      tuang_pakan(jp);
      x = false;
    }
    else {
      x = true;
      delay(10000);
    }
  }
}

#endif
