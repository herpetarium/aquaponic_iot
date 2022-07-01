#ifndef VEML_H
#define VEML_H
#include "DFRobot_VEML7700.h"
#include <Wire.h>
#include <Arduino.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP32Servo.h>

DFRobot_VEML7700 als;
const int lamp = 25; //Pin Relay

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void ntpSETUP() {
  timeClient.begin();
  timeClient.setTimeOffset(25200);
}

void vemlSETUP() {
  als.begin();
  pinMode(lamp, OUTPUT);
}

int luxValue() {
  float lux;
  als.getALSLux(lux);
  return lux;
}

void luxControl() {
  timeClient.update();
  int jam = timeClient.getHours();
  TelnetStream.print("Jam:");
  TelnetStream.println (jam);
  if (jam >= 7 && jam < 17 && luxValue() <= 1500)
  {
    TelnetStream.print("Lamp ON");
    digitalWrite (lamp, HIGH);
  }
  else
  {
    TelnetStream.println("Lamp Off");
    digitalWrite (lamp, LOW);
  }
}

#endif
