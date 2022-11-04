#include "YoupiLabEsp32.h"


YoupiLabEsp32::YoupiLabEsp32(String APP_ID, String APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api"){}

/********************************************** Les SETTER ET GETTER */
/*
  get app key
*/
String YoupiLabEsp32::getAppKey(){
  return _APP_KEY;
}
/*
  get app id
*/
String YoupiLabEsp32::getAppId(){
  return _APP_ID;
}
/*
  set app key
*/
void YoupiLabEsp32::setAppKey(String appkey){
       _APP_KEY = appkey;
}
/*
  set app id
*/
void YoupiLabEsp32::setAppID(String appid){
      _APP_ID = appid;
}
/*
  get base key
*/
String YoupiLabEsp32::getBaseUrl(){
     return _BASE_URL;
}

/*
  allows to connect to a wifi
*/
int YoupiLabEsp32::veriyAndConnectToWifi(char* ssid, char* password){
  delay(200); 
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
     delay(500);
  }
   return 1;

}
/*
  check yor ip adress
*/
void YoupiLabEsp32::checkMyAdressIp(){

    Serial.println(WiFi.localIP());
}

/*
  create access point
*/
int YoupiLabEsp32::createAccessPoint(char* ssid, char* password){

      WiFi.mode(WIFI_AP);
      WiFi.softAP(ssid, password); 
      return 1;  
}
/*
  create server
*/
int YoupiLabEsp32::createServer(char* ssid, char* password){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  WiFiServer server(80);
  return 1;
}
/*
  execute an action
*/

int YoupiLabEsp32::executeAnAction(int led ){
    String url = "https://iot.youpilab.com/api/controls/get?APP_ID=" + _APP_ID + "&APP_KEY=" + _APP_KEY;
   
    http.begin(url);  
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      Serial.print("HTTP ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println();
      Serial.println(payload);
  
      String etatb=http.getString();
      payload.replace("\n", "");
      payload.replace("[", "");
      payload.replace("]", "");
      payload.replace(",", "");
      payload.replace(" ", "");
      payload.trim();
      
      char etat= etatb.charAt(0);
      int etat1 = etat -48; //convertir l'etat en entier 49 c'est que le bouton a ete appuer
      if(etat1==1)
      {
        digitalWrite(led, HIGH);
        return 1;
      }
      else
      {
        digitalWrite(led, LOW);
        return 0;
      }
    }
    else {
        return 2; // error network
    }
}
/*
  send a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
*/
int YoupiLabEsp32::sendDataFloat(float px){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=_APP_ID;
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      /*send request*/
      http.begin(post_url);   
    
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        return 1;
      }
      else {
        return 0;
      }
}
/*
  send a int data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
*/
int YoupiLabEsp32::sendDataIntegger(int px){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=_APP_ID;
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      /*send request*/
      http.begin(post_url);

      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        
        String payload = http.getString();
        return 1;
      }
      else {
        return 0;
      }
}
/*
  send a boolean data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
*/
int YoupiLabEsp32::sendDataBoolean(boolean px){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=_APP_ID;
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      /*send request*/
     http.begin(post_url);
     
    
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        return 1;
      }
      else {
        return 0;
      }
}
/*
  You can execute a task you have written in the terminal thing using this methode 
*/
int YoupiLabEsp32::executeTerminalTask(String TERMINAL_ID){

  String post_url = "https://iot.youpilab.com/api/terminal/?TERM=";
  //ok good
  post_url+=TERMINAL_ID;
  http.begin(post_url);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    
    String payload = http.getString();
    return 1;
  }
  else {
    
    return 0;
    
  }
  delay(1000);
}
/*
  count the number of data received by our iot platform
*/
void YoupiLabEsp32::countData(){

    String post_url = "https://iot.youpilab.com/api/data/count?APP_ID=";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;
    http.begin(post_url);
      int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      // Serial.print("HTTP ");
      // Serial.println(httpResponseCode);
      String payload = http.getString();
      // Serial.println();
      Serial.println(payload);
    }
    else {
      
      Serial.println(httpResponseCode);
      
    }
    delay(1000);
}

/*
  These informations must be used to execute the following request which will display the response in terminal of thing

*/
int YoupiLabEsp32::executeAnActionWithTerminal(String TERMINAL, String TASK_ID, String RESPONSE_OF_EXECUTION){

    String post_url = "https://iot.youpilab.com/api/terminal/response/?TERM=";
    //ok good
    post_url+=TERMINAL;
    post_url +="&TASK_ID=";
    post_url +=TASK_ID;
    post_url +="&RESP=";
    post_url +=RESPONSE_OF_EXECUTION;
    http.begin(post_url);
      int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {

      String payload = http.getString();
      return 1;
    }
    else {
      return 0;      
    }
}
/*
  send feed back
*/
void YoupiLabEsp32::sendFeedback(){

    String post_url = "https://iot.youpilab.com/api/controls/executed?APP_ID";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;
    http.begin(post_url);
      int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
     
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      
      Serial.println(httpResponseCode);
      
    }
}
