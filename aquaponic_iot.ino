#include "bme.h"
#include "ota.h"
#include "veml.h"
#include "ph.h"
#include "ds.h"
#include "json.h"
#include "pakan.h"

void setup() {
  Serial.begin(115200);
  wifiSETUP();
  otaSETUP();
  ntpSETUP();
  bmeSETUP();
  vemlSETUP();
  phSETUP();
  dsSETUP();
  pakanSETUP();
}

void loop() {
  otaLOOP();
  heatControl();
  luxControl();
  phControl();
  kontrolPakan();
  sensorData();
}
