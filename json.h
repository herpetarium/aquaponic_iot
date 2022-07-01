#ifndef JSON_H
#define JSON_H

#include <HTTPClient.h>
#include <ArduinoJson.h>

void sensorData() {
  StaticJsonDocument<200> val;

  // json
  String jsonVal;
  val["device_id"] = "aqua-1";
  val["suhu_udara"] = airtempValue();
  val["kelembapan_udara"] = airhumidValue();
  val["intensitas_cahaya"] = luxValue();
  val["ph"] = phValue();
  val["suhu_air"] = watertempValue();
  serializeJson(val, jsonVal);

  String Link;
  Link = "http://192.168.0.177/IoT_aquaponic/aqua.php";
  HTTPClient http;
  http.begin(Link);
  http.addHeader("Content-Type", "application/json");
  int httpResponse = http.POST(jsonVal);
  if (httpResponse > 0) {
    String response = http.getString();
    TelnetStream.println(response);
    TelnetStream.println(httpResponse);
  }
  TelnetStream.println(httpResponse);
  TelnetStream.println(http.GET());
  TelnetStream.print("JSON : ");
  TelnetStream.println(jsonVal);
  http.end();
  delay(20000);
}

#endif
