#ifndef BME_H
#define BME_H

#include <HTTPClient.h>
#include <ArduinoJson.h>
const char* host = "192.168.0.81";

void sensorData(){
   StaticJsonDocument<200> val;

  // json
  String jsonVal;
  val["device_id"] = "aqua-1";
  val["suhu_udara"] = airtempValue();
  val["kelembapan_udara"] =airhumidValue();
  val["intensitas_cahaya"] = luxValue();
  val["ph"] = phValue();
  val["suhu_air"] = watertempValue();
  serializeJson(val,jsonVal);
  
  String Link;
  Link = "http://192.168.0.81/IoT_aquaponic/aqua.php";
  HTTPClient http;
  http.begin(Link);
  http.addHeader("Content-Type", "application/json");   
  int httpResponse = http.POST(jsonVal);
  if(httpResponse > 0){
    String response = http.getString();
    Serial.println(response);
    Serial.println(httpResponse);}
  Serial.println(httpResponse);
  Serial.println(http.GET());
  Serial.print("JSON : ");
  Serial.println(jsonVal);
  http.end();
  delay(10000);}

#endif
