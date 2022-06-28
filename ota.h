#ifndef OTA_H
#define OTA_H
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <HTTPUpdateServer.h>
#include <WiFi.h>

#ifndef STASSID
#define STASSID "Workshop7"
#define STAPSK  "gapakekabel"
#endif
  
const char* ssid = STASSID;
const char* password = STAPSK;
const char* host = "192.168.0.176";
WebServer httpServer(80);
HTTPUpdateServer httpUpdater;
  

void wifiSETUP(){
  Serial.print("Connecting to ");
  //setting koneksi Wifi
  Serial.println(ssid);
  WiFi.hostname("aquaponic");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wifi Terhubung");
  }
  
void otaSETUP() {

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.println(WiFi.localIP());
}

void otaLOOP() {
  httpServer.handleClient();
    WiFiClient client;
  if(!client.connect(host,80)){
    Serial.println("Connection Failed");
    return;
  }
}

#endif
