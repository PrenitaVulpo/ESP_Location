#include <ESP8266WiFi.h>
#include "WiFiC.h"

const char* wifiMAC;
const char* *pwifiMAC = &wifiMAC;
int wifiRSSI = 0; 
int *pwifiRSSI = &wifiRSSI;

WiFiC::WiFiC(){

}

void WiFiC::setMAC(const char* mac){
  *pwifiMAC=mac;
}

const char* WiFiC::getMAC(){
  return wifiMAC;
}

void WiFiC::setRSSI(int wifiRSSI){
  *pwifiRSSI = wifiRSSI;
}

int WiFiC::getRSSI(){
  return wifiRSSI;
}
