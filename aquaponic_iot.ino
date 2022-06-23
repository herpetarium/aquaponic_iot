#include "bme.h"
#include "ota.h"
#include "veml.h"
#include "ph.h"
#include "ds.h"
#include "json.h"

void setup() {
  Serial.begin(115200);
  wifiSETUP();
  otaSETUP();
  ntpSETUP();
  bmeSETUP();
  vemlSETUP();
  phSETUP();
  dsSETUP();
}

void loop() {
  otaLOOP();
  WiFiClient client;
  if(!client.connect(hostt,80)){
    Serial.println("Connection Failed");
    return;
  }
  heatControl();
  luxControl();
  sensorData();
}
