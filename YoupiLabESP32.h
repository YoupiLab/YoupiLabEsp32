#ifndef YOUPILAB_LIBRARY_ESP_32_H
#define YOUPILAB_LIBRARY_ESP_32_H
#include<WiFi.h>
#include <WiFiAP.h>
#include <HTTPClient.h>


struct YoupiLabESP32{
  
   public:
      YoupiLabESP32(String APP_KEY, String APP_ID);

      int veriyAndConnectToWifi(const char* ssid, const char* password); //allows to connect to a wifi

      int send_Data(int count, ...); //send a data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      void executeAnAction(int nbr_args, ...); //execute an action return 1 in case of success and 0 in case of failure

      int executeTerminalTask(String TERMINAL_ID);// get info

      String countData();//count the number of data items sent to the object

      int sendFeedback();//Send feedback after executing a task

      void getInformationOfThingCreated();// You can have the information about your thing

      int executeAnActionWithTerminal(String TERMINAL, String TASK_ID, String RESPONSE_OF_EXECUTION);//execute an action in the terminal

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