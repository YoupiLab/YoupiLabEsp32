#ifndef YOUPILAB_LIBRARY_ESP_32_H
#define YOUPILAB_LIBRARY_ESP_32_H
#include<WiFi.h>
#include <WiFiAP.h>
#include <HTTPClient.h>

// #include <BLEUtils.h>
// #include <BLEServer.h>

struct YoupiLabEsp32{
  
   public:
      YoupiLabEsp32(String APP_KEY, String APP_ID);

      int veriyAndConnectToWifi(char* ssid, char* password); //allows to connect to a wifi

      void checkMyAdressIp(); // //allows to check your ip adress

      int createPointAccess(char* ssid, char* password);  //allows to create access point to a wifi

      int createServer(char* ssid, char* password);  //allows to create server to a wifi

      int sendDataFloat(float px); //send a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataIntegger(int px); //send a int data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataString(String px); //send a String data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataBoolean(boolean px);//boolean a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int executeAnAction(int led); //execute an action return 1 in case of success and 0 in case of failure

      void retrieveInformation(String TERMINAL_ID);

      void countData();

      void retrieveAllData(String start, String end);

      void getInformationForTerminal();

      void sendFeedback();

      void executeTerminalTask(String TERMINAL, String TASK_ID, String RESPONSE_OF_EXECUTION);

      String getAppKey();
      String getBaseUrl();
      String getAppId();

      void setAppKey(String key);
      void setAppUrl(String url);
      void setAppID(String id);
   
   private:
      HTTPClient http;
      String _APP_ID;
      String _APP_KEY;
      String _BASE_URL;
};

#endif