#include <YoupiLabEsp32.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";
YoupiLabEsp32  esp(APP_ID,APP_KEY);
void setup(){
  Serial.begin(9600);
  //need to connect to wifi
  esp.veriyAndConnectToWifi(ssid,password); //connect esp32 to wifi
  
}

void loop(){

}
