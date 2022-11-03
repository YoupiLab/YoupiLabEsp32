## Table of Contents
1. Presentation of YoupiLab Iot
2. General information about the YoupiLabEsp32 library
3. Installation in the Arduino IDE
4. Uses of our library YoupiLabEsp32

1. Presentation of YoupiLab Iot
YoupiLab Iot (https://iot.youpilab.com/) provides hosted services in the cloud that allow you to monitor and control your remote objects.
***
2. General information about the YoupiLabEsp32 library
The ESP32 module is an integrated and certified all-in-one Wi-Fi/Bluetooth solution that provides not only a wireless radio, but also an embedded processor with interfaces to enable connection to various devices. The processor actually offers two processing cores whose operating frequencies can be independently controlled between 80 megahertz (MHz) and 240 MHz.
3. Installation in the Arduino IDE
* To install the ESP32 board in your Arduino IDE, follow these next instructions:

In your Arduino IDE, go to File> Preferences
* Enter https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json into the "Additional Boards Manager URLs" field as shown in the figure below. Then, click the "OK" button:

* Note: if you already have the ESP8266 boards URL, you can separate the URLs with a comma as follows:

http://arduino.esp8266.com/stable/package_esp8266com_index.json,https://dl.espressif.com/dl/package_esp32_index.json, 
Open the Boards Manager. Go to Tools > Board > Boards Manager...

* Search for ESP32 and press install button for the "ESP32 by Espressif Systems":

* That's it. It should be installed after a few seconds.
*to test the ESP32 board to your computer. With your Arduino IDE open, follow these steps:

1. Select your Board in Tools > Board menu (in my case it's the DOIT ESP32 DEVKIT V1)

4. Uses of our YoupiLabEsp32 library 
To use our YoupiLabEsp32 you will have to download on github other additional library. 
 WiFiAP
 HTTPClient

Go to the tools folder and import the different libraries into your Arduino IDE. Go to the examples folder. You will see the example codes of the use of the library.

YoupiLabEsp32 esp(APP_ID,APP_KEY); //allows you to create an instance of an object called esp. APP_ID, and APP_KEY are the identifiers of the object created on the iot platform (https://iot.youpilab.com/).
esp.VeriyToConnectWifi(ssid,password); //this method connects you to a wifi and makes sure that the esp8266 has been connected to the wifi.
esp.sendDataFloat(data, APP_ID, APP_KEY); //sends float data to our platform in real time. 
esp.dynamicExecution(led1); //This method will allow for example to turn on or off a lamp.

esp.createPointAccess(ssid,password); //create an esp32 hostpot

esp.createServer(ssid,password); //create a web server with esp32

if you are a beginner don't hesitate to visit this link https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/



## functions
     int veriyAndConnectToWifi(char* ssid, char* password); //allows to connect to a wifi

      void checkMyAdressIp(); // //allows to check your ip adress

      int createPointAccess(char* ssid, char* password);  //allows to create access point to a wifi

      int createServer(char* ssid, char* password);  //allows to create server to a wifi

      int sendDataFloat(float px); //send a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataIntegger(int px); //send a int data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataString(String px); //send a String data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataBoolean(boolean px);//boolean a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int executeAnAction(int led); //execute an action return 1 in case of success and 0 in case of failure

      void retrieveInformation(String TERMINAL_ID);

      void countData();

      void retrieveAllData(String start, String end);

      void getInformationForTerminal();

      void sendFeedback();

      void executeTerminalTask(String TERMINAL, String TASK_ID, String RESPONSE_OF_EXECUTION);





