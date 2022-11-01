#include "YoupiLabEsp32.h"


YoupiLabEsp32::YoupiLabEsp32(String APP_ID, String APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api"){}

YoupiLabEsp32::YoupiLabEsp32(){}

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
void YoupiLabEsp32::VeriyToConnectWifi(char* ssid, char* password){
  delay(200); 
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
      Serial.println("tentative de connexion au wifi");
      Serial.println(ssid);
    delay(200); 
  }
    Serial.println("Connexion resussi !!");
    Serial.println("********** Votre adresse ID*************");
    Serial.print("Votre adresse Ip est : ");
    Serial.println(WiFi.localIP());

}

void YoupiLabEsp32::checkMyAdressIp(){
  Serial.println("********** Votre adresse ID*************");
    Serial.print("Votre adresse Ip est : ");
    Serial.println(WiFi.localIP());
}

//creete reseau wifi un pourt d'acces
void YoupiLabEsp32::createPointAccess(char* ssid, char* password){
    Serial.println("********** Creation du point d'access*************");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);    
    Serial.println(WiFi.softAPIP());
}

void YoupiLabEsp32::createServer(char* ssid, char* password){
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  WiFiServer server(80);
  // Print local IP address and start web server
  Serial.println("Print local IP address and start web server");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}


void YoupiLabEsp32::dynamicExecution(int led1 ){
    /***********recuperation des instructions a executer depuis la plateforme IoT ******/
    String url = "https://iot.youpilab.com/api/controls/get?APP_ID=" + _APP_ID + "&APP_KEY=" + _APP_KEY;
    //String url = "https://test.iot.generalinvasion.com/api";
    HTTPClient http;
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
        Serial.println("Led1 Allumé ");
      }
      else
      {
        digitalWrite(led1, LOW);
        Serial.println("Led1 Eteinte ");
      }
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
      Serial.println(":-(");
    }
}

void YoupiLabEsp32::sendDataFloat(float px, String APP_ID, String APP_KEY){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=APP_ID;
      post_url +="&APP_KEY=";
      post_url +=APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      Serial.println(post_url);
      /*Envoie de la reqette*/
     HTTPClient http;
     http.begin(post_url);
    
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        Serial.println(":-(");
      }
}

void YoupiLabEsp32::sendDataIntegger(int px, String APP_ID, String APP_KEY){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=APP_ID;
      post_url +="&APP_KEY=";
      post_url +=APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      Serial.println(post_url);
      /*Envoie de la reqette*/
     HTTPClient http;
     http.begin(post_url);
    
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        Serial.println(":-(");
      }
}

void YoupiLabEsp32::sendDataBoolean(bool px, String APP_ID, String APP_KEY){

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
  
      post_url+=APP_ID;
      post_url +="&APP_KEY=";
      post_url +=APP_KEY;
      post_url +="&P1=";
      post_url +=px;                        
      Serial.println(post_url);
      /*Envoie de la reqette*/
     HTTPClient http;
     http.begin(post_url);
    
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        Serial.println(":-(");
      }
}

//void YoupiLabEsp32::createAccessBluetooth(String SERVICE_UUID, String CHARACTERISTIC_UUID){
//  Serial.println("Starting BLE work!");
//
//  BLEDevice::init("Long name works now");
//  BLEServer *pServer = BLEDevice::createServer();
//  BLEService *pService = pServer->createService(SERVICE_UUID);
//  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
//                                         CHARACTERISTIC_UUID,
//                                         BLECharacteristic::PROPERTY_READ |
//                                         BLECharacteristic::PROPERTY_WRITE
//                                       );
//
//  pCharacteristic->setValue("Hello World says Neil");
//  pService->start();
//  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
//  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
//  pAdvertising->addServiceUUID(SERVICE_UUID);
//  pAdvertising->setScanResponse(true);
//  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
//  pAdvertising->setMinPreferred(0x12);
//  BLEDevice::startAdvertising();
//  Serial.println("Characteristic defined! Now you can read it in your phone!");
//}
