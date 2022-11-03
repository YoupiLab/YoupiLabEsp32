#ifndef YOUPILAB_LIBRARY_ESP_32_H
#define YOUPILAB_LIBRARY_ESP_32_H
#include<WiFi.h>
#include <WiFiAP.h>
//#include <WebServer.h>
#include <HTTPClient.h>
// #include <BLEDevice.h>
// #include <BLEUtils.h>
// #include <BLEServer.h>


struct YoupiLabEsp32{
  
   public:
      YoupiLabEsp32(String APP_KEY, String APP_ID);
      YoupiLabEsp32();
      void VeriyToConnectWifi(char* ssid, char* password);

      void checkMyAdressIp();


      void createPointAccess(char* ssid, char* password);

      void createServer(char* ssid, char* password);
      
      void sendDataFloat(float px);
      
      void dynamicExecution(int led1);
      
       void sendDataIntegger(int px);

       void sendDataBoolean(bool px);


      void sendDataString(String px);
      
      String getAppKey();
      String getBaseUrl();
      String getAppId();

      void setAppKey(String key);
      void setAppUrl(String url);
      void setAppID(String id);
   
   private:
      String _APP_ID;
      String _APP_KEY;
      String _BASE_URL;
};


#endif
