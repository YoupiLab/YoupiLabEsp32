/*
 * 1 pour entier
 * 2 pour nombre à virgule
 * 3 pour string
 */
#include <YoupiLabESP32.h>


const char* ssid =  "Mon_Wifi";//
const char* password = "1234567890";//
String APP_ID     = "espc8123";  // Equipment APP ID
String APP_KEY    = "6033f31f";  // Equipment Key
YoupiLabESP32  esp32(APP_ID, APP_KEY);
int n = 2;
int led1 = 4;
int led2 = 5;
int button1, button2;
void setup() {
  Serial.begin(9600);
  //Connexion au Wi-Fi
  if (esp32.veriyAndConnectToWifi(ssid, password) == 1) {
    Serial.println("Connexion reussi");
  }
  pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
}

void loop() {

 esp32.executeAnAction(n, &button1, &button2);
    Serial.print("button1=");
    Serial.println(button1);
    Serial.print("button2=");
    Serial.println(button2);
    if (button1 == 1) {
      digitalWrite(led1, HIGH);
    } else if (button1 == 0) {
      digitalWrite(led1, LOW);
    }
    if (button2 == 1) {
      digitalWrite(led2, HIGH);
    } else if (button2 == 0) {
      digitalWrite(led2, LOW);
    }

}
