#ifndef OTA_H
#define OTA_H
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <HTTPUpdateServer.h>
#include <WiFi.h>
#include <Arduino.h>

WebServer httpServer(80);
HTTPUpdateServer httpUpdater;
const char* hostt="esp32-webupdate";
#define WIFI_SSID "Workshop Elka" // Change the name of your WIFI
#define WIFI_PASSWORD "gapakekabel" // Change the password of your WIFI

void wifiSETUP(){
     WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();}
  
void otaSETUP() {

  MDNS.begin(hostt);
  if (MDNS.begin("esp32")) {
    Serial.println("mDNS responder started");
  }

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", hostt);
}

void otaLOOP() {
  httpServer.handleClient();
}

#endif
