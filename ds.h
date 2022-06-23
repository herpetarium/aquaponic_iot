#ifndef DS_H
#define DS_H
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

#define oneWireBus 4
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
const int heat=32;

void dsSETUP(){
  sensors.begin();
  pinMode(heat, OUTPUT);
}

int watertempValue(){
  int watertemp; 
  sensors.requestTemperatures();
  watertemp=sensors.getTempCByIndex(0);
  delay(1000);
   return watertemp;
    } 
void heatControl(){
     if (watertempValue() <= 29) {
    Serial.println("Turn the heater on");
    digitalWrite(heat, HIGH); // turn on
    }
  else if (watertempValue() > 30) {
    Serial.println("Turn the heater off");
    digitalWrite(heat, LOW); // turn off
  }}
#endif
