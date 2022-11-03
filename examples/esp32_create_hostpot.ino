#include <YoupiLabEsp32.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";

YoupiLabEsp32  esp(APP_ID,APP_KEY);
void setup(){
  Serial.begin(9600);
  
  esp.createPointAccess(ssid,password); //create hostpot with esp 32
  
}

void loop(){

}
