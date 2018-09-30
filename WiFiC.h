#ifndef WiFiC_h
#define WiFiC_h

class WiFiC{
  public:
    WiFiC();
    void setMAC(const char* mac);
    const char* getMAC();
    void setRSSI(int wifiRSSI);
    int getRSSI();
};

#endif
