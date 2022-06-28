#ifndef PH_H
#define PH_H

#include "DFRobot_ESP_PH.h"
#include "EEPROM.h"
#include <Arduino.h>

DFRobot_ESP_PH ph;
#define ESPADC 4096.0   //the esp Analog Digital Convertion value
#define ESPVOLTAGE 3300 //the esp voltage supply value
#define PH_PIN 35    //the esp gpio data pin number

//motorsetup
const int motor1Pin1 = 27; // IN1
const int motor1Pin2 = 14; // IN2
const int motor2Pin1 = 12; // IN3
const int motor2Pin2 = 13; // IN4

void phSETUP(){
  EEPROM.begin(32);//needed to permit storage of calibration value in eeprom
  ph.begin();
  // Motor pin setting
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  }

float phValue(){
  float voltage, phValue, temperature = 25;
    //voltage = rawPinValue / esp32ADC * esp32Vin
    voltage = analogRead(PH_PIN) / ESPADC * ESPVOLTAGE;
    phValue = ph.readPH(voltage, temperature);
    return phValue;
  }  
void phControl(){
  unsigned long timepoint = millis();
  if(phValue()<5.5){
    Serial.println("LOWph");
      while(millis()-timepoint<5000){
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);}
        } 
    else if(phValue()>6.5){
      Serial.println("HIGHph");
      while(millis()-timepoint<5000){
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);}
        }
    else{
        Serial.println("NORMALph");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);}
        }
#endif
