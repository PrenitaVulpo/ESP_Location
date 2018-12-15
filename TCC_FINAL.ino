//includes
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

//WiFi Station setup variables
//const char* SSID = "OBERDAN-WIFI";
const char* lSSID = "FJN-UNIFI";
//const char* senha = "Jol1965jol";
const char* senha = "";

//Code
void setup() {
  // Set the microcontroler to station mode and disconect from previously connected network
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.begin(115200);
  delay(100);
  Serial.println("Setup done");
  //Connect to network
  WiFi.begin(lSSID, senha);
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Conectado à rede ");
    Serial.println(lSSID);
  }
};
void json(String mac[3], int rssi[3]) {
  const size_t bufferSize = JSON_ARRAY_SIZE(3) + 4 * JSON_OBJECT_SIZE(2);
  DynamicJsonBuffer jsonBuffer(bufferSize);

  JsonObject& root = jsonBuffer.createObject();
  root["considerIp"] = "false";

  JsonArray& wifiAccessPoints = root.createNestedArray("wifiAccessPoints");

  JsonObject& wifiAccessPoints_0 = wifiAccessPoints.createNestedObject();
  wifiAccessPoints_0["macAddress"] = mac[0];
  wifiAccessPoints_0["signalStrength"] = rssi[0];

  JsonObject& wifiAccessPoints_1 = wifiAccessPoints.createNestedObject();
  wifiAccessPoints_1["macAddress"] = mac[1];
  wifiAccessPoints_1["signalStrength"] = rssi[1];

  JsonObject& wifiAccessPoints_2 = wifiAccessPoints.createNestedObject();
  wifiAccessPoints_2["macAddress"] = mac[2];
  wifiAccessPoints_2["signalStrength"] = rssi[2];

  root.printTo(Serial);
}
void loop() {
  Serial.println("Teste");
  int n = WiFi.scanNetworks();
  Serial.println(n);
  String mac[3];
  int rssi[3];
  if (n>=3){
    for (int x = 0; x < 3; x++) {
      Serial.println("Teste do for");
      Serial.println(WiFi.SSID(x));
      Serial.println(WiFi.RSSI(x));
      Serial.println(WiFi.BSSIDstr(x));
      mac[x] = WiFi.BSSIDstr(x);
      rssi[x] = WiFi.RSSI(x);
    }
    json(mac, rssi);
  }else{
    Serial.println("Nao ha redes o suficiente para o mapeamento");
  }

  delay(1000);

  //void Loop end

};


