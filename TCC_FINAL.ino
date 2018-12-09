  //includes  
#include <ESP8266WiFi.h>
#include "WiFiC.h"

/*//General Setup Variables
int wRSSI,wRSSI2 = 0;
String s2,s3, s4;*/ 
  //WiFi
    //Access
    const char* SSIDl = "OBERDAN-WIFI";
    const char* senha = "Jol1965jol";
    //const char* senha = "";
/*//Temporário
WiFiC rede1;
WiFiC rede2;
WiFiC rede3;*/
/*  //Json
  const size_t bufferSize = JSON_ARRAY_SIZE(3) + 4*JSON_OBJECT_SIZE(2);
  DynamicJsonBuffer jsonBuffer(bufferSize);
  
  JsonObject& root = jsonBuffer.createObject();
  //EEPROM
  int EEPROMaddr = 0;
  byte value;
*/
//Code
  void setup(){
    //ṭemporário
    WiFiC rede1;
WiFiC rede2;
WiFiC rede3;
//General Setup Variables
int wRSSI,wRSSI2 = 0;
String s2,s3, s4; 
    Serial.begin(115200);
    //Set WiFi to station mode
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    Serial.println("Station mode Activated");
    //Local network connction
    WiFi.begin(SSIDl,senha);
    while (WiFi.status() != WL_CONNECTED){
      delay(1000);
      Serial.println("Não conectado a nenhuma rede");
    } 
    Serial.println("Conectado");
    //void Setup end
  };
  void loop(){
    //Temporário
WiFiC rede1;
WiFiC rede2;
WiFiC rede3;
//General Setup Variables
int wRSSI,wRSSI2 = 0;
String s2,s3, s4; 
        //Json Serialization and printing
          //Printing
          int n = WiFi.scanNetworks();
          for (int i = 0; i < n; ++i) {
          // Print SSID and RSSI for each network found
          Serial.print(i + 1);
          Serial.print(": ");
          Serial.print(WiFi.SSID(i));
          Serial.print(" (");
          Serial.print(WiFi.RSSI(i));
          Serial.print(")");
          Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
          delay(10);
          if(rede1.getRSSI()<WiFi.RSSI(i)){
            //RSSI
            wRSSI = rede1.getRSSI();
            rede1.setRSSI(WiFi.RSSI(i));
            rede3.setRSSI(rede2.getRSSI());
            rede2.setRSSI(wRSSI);
            //MAC
            s2 = rede1.getMAC();
            s3 = WiFi.BSSIDstr();
            s4 = rede2.getMAC();
            rede1.setMAC(s3);
            rede3.setMAC(s4);
            rede2.setMAC(s2);
            }else if(rede2.getRSSI()<WiFi.RSSI(i)){
              wRSSI = rede2.getRSSI();
              rede2.setRSSI(WiFi.RSSI(i));
              rede3.setRSSI(wRSSI);
              //MAC
              s2 = rede2.getMAC();
              s3 = WiFi.BSSIDstr();
              rede2.setMAC(s3);
              rede3.setMAC(s2);
            }else if(rede3.getRSSI()<WiFi.RSSI(i)){
              rede3.setRSSI(WiFi.RSSI(i));
              //MAC
              s3 = WiFi.BSSIDstr();
              rede3.setMAC(s3);
            }
          }
          Serial.print("Endereço MAC da rede Nº1: ");
          Serial.println(rede1.getMAC());
          Serial.println("RSSI da rede Nº1: "+String(rede1.getRSSI()));
          Serial.print("Endereço MAC da rede Nº2: ");
          Serial.println(rede2.getMAC());
          Serial.println("RSSI da rede Nº2: "+rede2.getRSSI());
          Serial.print("Endereço MAC da rede Nº3: ");
          Serial.println(rede3.getMAC());
          Serial.println("RSSI da rede Nº3: "+rede3.getRSSI());
/*          //Serializing
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
*/    
    delay(5000);
    
  //void Loop end
  
  };
   

