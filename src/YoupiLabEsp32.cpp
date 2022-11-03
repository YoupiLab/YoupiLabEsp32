#include "YoupiLabEsp32.h"


YoupiLabEsp32::YoupiLabEsp32(String APP_ID, String APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api"){}

/********************************************** Les SETTER ET GETTER */
String YoupiLabEsp32::getAppKey(){
  return _APP_KEY;
}

String YoupiLabEsp32::getAppId(){
  return _APP_ID;
}

void YoupiLabEsp32::setAppKey(String appkey){
       _APP_KEY = appkey;
}

void YoupiLabEsp32::setAppID(String appid){
      _APP_ID = appid;
}

String YoupiLabEsp32::getBaseUrl(){
     return _BASE_URL;
}

//permet de verifier si la carte esp c'est bien connecter
int YoupiLabEsp32::veriyAndConnectToWifi(char* ssid, char* password){
  delay(200); 
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
     delay(500);
  }
   return 1;

}

void YoupiLabEsp32::checkMyAdressIp(){

    Serial.println(WiFi.localIP());
}

//creete reseau wifi un pourt d'acces
int YoupiLabEsp32::createPointAccess(char* ssid, char* password){

      WiFi.mode(WIFI_AP);
      WiFi.softAP(ssid, password); 
      return 1;  
}

int YoupiLabEsp32::createServer(char* ssid, char* password){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  WiFiServer server(80);
  return 1;
}


int YoupiLabEsp32::executeAnAction(int led1 ){
    /***********recuperation des instructions a executer depuis la plateforme IoT ******/
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
        digitalWrite(led1, HIGH);
        return 1;
      }
      else
      {
        digitalWrite(led1, LOW);
        return 0;
      }
    }
    else {
        return 2; // error network
    }
}

int YoupiLabEsp32::sendDataFloat(float px){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=_APP_ID;
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      /*send request*/
      HTTPClient http;
    
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        return 1;
      }
      else {
        return 0;
      }
}

int YoupiLabEsp32::sendDataIntegger(int px){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=_APP_ID;
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      /*send request*/
      HTTPClient http;

      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        
        String payload = http.getString();
        return 1;
      }
      else {
        return 0;
      }
}

int YoupiLabEsp32::sendDataBoolean(boolean px){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=_APP_ID;
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      /*send request*/
      HTTPClient http;
     
    
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

void YoupiLabEsp32::retrieveInformation(String TERMINAL_ID){

  String post_url = "https://iot.youpilab.com/api/terminal/?TERM=";
  //ok good
  post_url+=TERMINAL_ID;
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

void YoupiLabEsp32::countData(){

    String post_url = "https://iot.youpilab.com/api/data/count?APP_ID=";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;

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

void YoupiLabEsp32::retrieveAllData(String start, String end){

    String post_url = "https://iot.youpilab.com/api/data/pull?APP_ID=";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;
    post_url +="&start=";
    post_url +=start;
    post_url +="&end=";
    post_url +=end;

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
void YoupiLabEsp32::getInformationForTerminal(){

    String post_url = "https://iot.youpilab.com/api/data/count?APP_ID=";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;
      
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
}

void YoupiLabEsp32::executeTerminalTask(String TERMINAL, String TASK_ID, String RESPONSE_OF_EXECUTION){

    String post_url = "https://iot.youpilab.com/api/terminal/response/?TERM=";
    //ok good
    post_url+=TERMINAL;
    post_url +="&TASK_ID=";
    post_url +=TASK_ID;
    post_url +="&RESP=";
    post_url +=RESPONSE_OF_EXECUTION;
    
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
}

void YoupiLabEsp32::sendFeedback(){

    String post_url = "https://iot.youpilab.com/api/controls/executed?APP_ID";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;

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
}
