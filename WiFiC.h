#ifndef WiFiC_h
#define WiFiC_h

class WiFiC{
  public:
    WiFiC();
    /*String wifiMAC;
    int wifiRSSI = 0;*/
    void setMAC(String mac);
    String getMAC();
    void setRSSI(int wifiRSSI);
    int getRSSI();
  private:
   String wifiMAC;
    int wifiRSSI;
    
};

#endif

