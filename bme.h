#ifndef BME_H
#define BME_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Arduino.h>

Adafruit_BME280 bmesensor;
void bmeSETUP() {
  bmesensor.begin(0x76);
}

int airtempValue() {
  int airtemp;
  airtemp = bmesensor.readTemperature();
  return airtemp;
}
int airhumidValue() {
  int airhumid;
  airhumid = bmesensor.readHumidity();
  return airhumid;
}

#endif
