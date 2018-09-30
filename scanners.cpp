/*#include <ESP8266WiFi.h>
#include "WiFiC.h"

int networksAmount;

scannersClass::scannersClass(){
  
}

int scan(){
  int n = WiFi.scanNetworks();
  //Scan completed message
  Serial.print("Scan completed, ");
  Serial.print(n);
  Serial.println(" networks found");
  networks = n;
  return n 
}

bool possible(){
  if networksAmount >= 3{
    return true;
  }else{
    Serial.println("No networks or less than 3 networks found")
    return false;
  }
}

void scanSet(WiFiC *redes[3]){
  Serial.print(n);
  Serial.println(" networks found");
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
  }
}
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
          */
