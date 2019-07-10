  /*//includes
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//WiFi Station setup variables
const char* lSSID = "OBERDAN-WIFI";
//const char* lSSID = "FJN-UNIFI";
const char* senha = "Jol1965jol";
//const char* senha = "";

//Google GeoLocation API.
const char* Host = "www.googleapis.com";
String thisPage = "/geolocation/v1/geolocate?key=";
String key = "MyKey";

// Credential for Dweetio API
const char* HostDweetURL = "www.dweet.io";

double latitude    = 0.0;
double longitude   = 0.0;
double accuracy    = 0.0;
int more_text = 1;

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

  char JSONmessageBuffer[400];
  root.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  Serial.println(JSONmessageBuffer);
  post(JSONmessageBuffer);



}
void post(char JSONmessageBuffer[400]) {
  //std::String JsonNewBuffer(JSONmessageBuffer);
  Serial.println("método post funcionou");
  DynamicJsonBuffer JsonNewBuffer;
  String JsonString = JSONmessageBuffer;
  Serial.println(JsonString);
  WiFiClientSecure client;
  Serial.print("Requesting URL: ");
  Serial.println("https://" + (String)Host + thisPage + key);
  Serial.println(" ");
  if (client.connect(Host, 443)) {
    Serial.println("Connected");
    client.println("POST " + thisPage + key + " HTTP/1.1");
    client.println("Host: " + (String)Host);
    client.println("Connection: close");
    client.println("Content-Type: application/json");
    client.println("User-Agent: Arduino/1.0");
    client.print("Content-Length: ");
    client.println(JsonString.length());
    client.println();
    client.print(JsonString);
    delay(500);
  }

  //Read and parse all the lines of the reply from server
  while (client.available()) {
    String line = client.readStringUntil('\r');
    if (more_text) {
      Serial.print(line);
    }
   
    JsonObject& root2 = JsonNewBuffer.parseObject(line);
    if (root2.success()) {
      latitude    = root2["location"]["lat"];
      longitude   = root2["location"]["lng"];
      accuracy   = root2["accuracy"];
    }
  }

  Serial.print("Latitude = ");
  Serial.println(latitude, 6);
  Serial.print("Longitude = ");
  Serial.println(longitude, 6);
  Serial.print("Accuracy = ");
  Serial.println(accuracy);

  String posturl =  "/dweet/for/tcc?Latitude=" + String(latitude) + "&Longitude=" + String(longitude);

  //Connect to the dweet.io client and make the api call
  Serial.print("Requesting URL Dweet: ");
  Serial.println("https://" + (String)HostDweetURL + posturl);
  Serial.println(" ");
  if (client.connect(HostDweetURL, 443)) {
    Serial.println("Connected to dweet");
    client.println("POST " + posturl + " HTTP/1.1");
    client.println("Host: " + (String)HostDweetURL );
    client.println("Connection: close");
    client.println("Content-Type: application/json");
    client.println("User-Agent: Arduino/1.0");
    client.print("Content-Length: ");
    client.println(JsonString.length());
    client.println();
    client.print(JsonString);
    delay(500);
  }

  Serial.println("closing connection");
  Serial.println();
  client.stop();
}

void loop() {
  //Serial.println("Teste");
  int n = WiFi.scanNetworks();
  Serial.println(n);
  String mac[3];
  int rssi[3];
  if (n >= 3) {
    for (int x = 0; x < 3; x++) {
      Serial.println("Teste do for");
      Serial.println(WiFi.SSID(x));
      Serial.println(WiFi.RSSI(x));
      Serial.println(WiFi.BSSIDstr(x));
      mac[x] = WiFi.BSSIDstr(x);
      rssi[x] = WiFi.RSSI(x);
    }
    json(mac, rssi);
  } else {
    Serial.println("Nao ha redes o suficiente para o mapeamento");
  }

  delay(1000);

  //void Loop end

};
*/

