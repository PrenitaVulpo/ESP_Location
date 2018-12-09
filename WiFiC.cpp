#include <ESP8266WiFi.h>
#include "WiFiC.h"

String wifiMAC;
String *pwifiMAC = &wifiMAC;
int wifiRSSI = -100; 
int *pwifiRSSI = &wifiRSSI;

WiFiC::WiFiC(){
  Serial.println("criado");
}

void WiFiC::setMAC(String mac){
  wifiMAC=mac;
  Serial.println("funfou");
}

String WiFiC::getMAC(){
  return wifiMAC;
}

void WiFiC::setRSSI(int wifiRSSI){
  *pwifiRSSI = wifiRSSI;
}

int WiFiC::getRSSI(){
  return wifiRSSI;
}

