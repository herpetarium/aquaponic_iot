#include <TelnetStream.h>
#include "bme.h"
#include "ota.h"
#include "veml.h"
#include "ph.h"
#include "ds.h"
#include "json.h"
#include "pakan.h"

unsigned long period = 0;
void setup() {
  Serial.begin(115200);
  wifiSETUP();
  TelnetStream.begin();
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
  if (millis() - period > 300000) {
    phControl();
    period = millis();
  }
  kontrolPakan();
  sensorData();
}
