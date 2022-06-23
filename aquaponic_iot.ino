#include "json.h"
#include "bme.h"
#include "ota.h"
#include "veml.h"
#include "ph.h"
#include "ds.h"


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
  heatControl();
  luxControl();
  sensorData();
}
