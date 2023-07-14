/*
 * 1 pour entier
 * 2 pour nombre à virgule
 * 3 pour string
 */
#include <YoupiLabESP32.h>


const char* ssid =  "Mon_Wifi";//
const char* password = "1234567890";//
int pho_res = A0;
String d;
String APP_ID     = "espc8123";  // Equipment APP ID
String APP_KEY    = "6033f31f";  // Equipment Key
YoupiLabESP32  esp32(APP_ID, APP_KEY);
void setup() {
  Serial.begin(9600);
  //Connexion au Wi-Fi
  if (esp32.veriyAndConnectToWifi(ssid, password) == 1) {
    Serial.println("Connexion reussi");
  }
 
  pinMode(pho_res, INPUT);
}

void loop() {

int lummiere=analogRead(pho_res);//lecture et recuperation du niveau de lumiere
float n1=23.03 ;//nombre a virgule
float n2=3.14;//nombre a virgule
 d="YoupiLab";//string
 
  //pour envoyer des données sur la plateforme
  if (esp32.send_Data(4, 1, lummiere, 3, d, 2, n1, 2, n2) == 1) {
    Serial.println("Envoie reussi");
  }

Serial.print("countData=");
String n_data=esp32.countData();//Compter le nombre de donnée dans l'equipement
Serial.println(n_data);
delay(5000);


}
