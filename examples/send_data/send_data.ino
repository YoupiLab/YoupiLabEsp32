#include <YoupiLabEsp32.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";
int pho_resistance= A0;
String APP_ID     = "esp91ce0";  // Equipment APP ID
String APP_KEY    = "c19071d5";  // Equipment Key

YoupiLabEsp32  esp(APP_ID,APP_KEY);
void setup(){
  Serial.begin(9600);
  esp.veriyAndConnectToWifi(ssid,password);
  pinMode(pho_resistance, INPUT);
}

void loop(){
   float po = analogRead(pho_resistance);
   Serial.println(po);
   if(esp.sendDataFloat(po)==1){
        Serial.println("Envoie reussi");
   } //send float data to our iot platform (https://iot.youpilab.com) 
    if(esp.sendDataFloat(po)==0){
        Serial.println("Echec d'envoie ");
   } 
}
