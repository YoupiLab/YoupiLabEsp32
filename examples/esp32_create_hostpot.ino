#include <YoupiLabEsp32.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";

//create your Objet iot https://iot.youpilab.com/
String APP_ID     = "esp91ce0";  // Equipment APP ID
String APP_KEY    = "c19071d5";  // Equipment Key
YoupiLabEsp32  esp(APP_ID,APP_KEY);
void setup(){
  Serial.begin(9600);
  
  esp.createPointAccess(ssid,password); //create hostpot
  
}

void loop(){

}
