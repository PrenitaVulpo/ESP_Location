/*//includes  
#include <latencia.h>

#include <ESPNexUpload.h>

#include <ArduinoJson.h>

//libraries
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <EEPROM.h>
#include <FS.h>

//General Setup Variables
String s2 ;
  //WiFi
    //Access
    const char* SSID = "OBERDAN-WIFI";
    const char* senha = "Jol1965jol";
    //For Json
      //Network 1
      const char* wifiMAC1;
      int wifiRSSI1 = 0;
      //Network 2
      const char* wifiMAC2;
      int wifiRSSI2 = 0;
      //Network 3
      const char* wifiMAC3;
      int wifiRSSI3 = 0;
  //Json
  const size_t bufferSize = JSON_ARRAY_SIZE(3) + 4*JSON_OBJECT_SIZE(2);
  DynamicJsonBuffer jsonBuffer(bufferSize);
  
  JsonObject& root = jsonBuffer.createObject();
  //EEPROM
  int EEPROMaddr = 0;
  byte value;

//Code
  void setup(){
    Serial.begin(115200);

    //Set WiFi to station mode
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    Serial.println("Station mode Activated");
     //SPIFFS initalizing
     SPIFFS.begin();
    //void Setup end
  };
  void loop(){
  //WiFi scanning
    int n = WiFi.scanNetworks();
    if (n > 0){
      //Scan completed message
      Serial.print("Scan completed, ");
      Serial.print(n);
      Serial.println(" networks found");
      //end of message
        if (n >= 3){
          int i;
        for (i = 0; i < n; ++i){
          //"for" scope variables
            int d = i+1;
            s2 = WiFi.SSID(i);
            const char* s = s2.c_str();
            int j = WiFi.RSSI(i);
            int jApoio = 0;
            int jApoio2 = 0;
            const char* macApoio;
            const char* macApoio2;
          //WiFi SSIDs printing
          Serial.print(d);
          Serial.print(": ");
          Serial.print(s);
          Serial.print("(");
          Serial.print(j);
          Serial.println(");");
          //WiFi SSIDs printing end
          Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
          //RSSI comparison for Json composal
          if (j < wifiRSSI3){
            if (j < wifiRSSI2){
              if (j < wifiRSSI1){
                //Alocating the RSSI values on the variables that will compose the Json file
                jApoio = wifiRSSI1;
                wifiRSSI1 = j;
                jApoio2 = wifiRSSI2;
                wifiRSSI2 = jApoio;
                wifiRSSI3 = jApoio2;
                //Alocating the MAC addresses on the variables that will compose the Json file
                macApoio = wifiMAC1;
                wifiMAC1 = WiFi.macAddress().c_str();
                macApoio2 = wifiMAC2;
                wifiMAC2 = macApoio;
                wifiMAC3 = macApoio2;
              }else{
                //Alocating the RSSI values on the variables that will compose the Json file
                jApoio = wifiRSSI2;
                wifiRSSI2 = j;
                wifiRSSI3 = jApoio;
                //Alocating the MAC addresses on the variables that will compose the Json file
                macApoio = wifiMAC2;
                wifiMAC2 = WiFi.macAddress().c_str();
                wifiMAC3 = wifiMAC2;
              }
            }else{
              wifiRSSI3 = j;
              wifiMAC3 = WiFi.macAddress().c_str();
            }
          }
        }
        //End of comparison
        //Json Serialization and printing
          //Printing
          Serial.print("Endereço MAC da rede Nº1: ");
          Serial.println(wifiMAC1);
          Serial.println("RSSI da rede Nº1: "+wifiRSSI1);
          Serial.print("Endereço MAC da rede Nº2: ");
          Serial.println(wifiMAC2);
          Serial.println("RSSI da rede Nº2: "+wifiRSSI2);
          Serial.print("Endereço MAC da rede Nº3: ");
          Serial.println(wifiMAC3);
          Serial.println("RSSI da rede Nº3: "+wifiRSSI3);
          //Serializing
          JsonArray& wifiAccessPoints = root.createNestedArray("wifiAccessPoints");
          //Rede 1
          JsonObject& wifiAccessPoints_0 = wifiAccessPoints.createNestedObject();
          wifiAccessPoints_0["macAddress"] = wifiMAC1;
          wifiAccessPoints_0["signalStrength"] = wifiRSSI1;
          //Rede 2
          JsonObject& wifiAccessPoints_1 = wifiAccessPoints.createNestedObject();
          wifiAccessPoints_1["macAddress"] = wifiMAC2;
          wifiAccessPoints_1["signalStrength"] = wifiRSSI2;
          //Rede 3
          JsonObject& wifiAccessPoints_2 = wifiAccessPoints.createNestedObject();
          wifiAccessPoints_2["macAddress"] = wifiMAC3;
          wifiAccessPoints_2["signalStrength"] = wifiRSSI3;
      
        root.printTo(Serial);
        //Saving the Json file on the SPIFFS
        File file = SPIFFS.open("/TesteJson", "w");
        if (!file){
          Serial.println("Datei konnte nicht geöffnet werden");
        }else{
          Serial.println("Deu certo!");
          root.printTo(file);
        }
        
      }else{
        Serial.println("Less than 3 networks found, it is not possible serialize the Json file");
        }
    }else{
      Serial.println("No network found");
    }
    
    delay(60000);
    
  //void Loop end
  
  };
   */

