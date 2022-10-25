Facilitate the use of the esp32 card.
This library has been designed to help embedded system developers to go faster in the realization of their products.

Prerequisites
1- Installation of the Arduino IDE
2- Go to the link https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/#more-30772 and follow the different steps to install the board in Arduino.
3- In case there is a bug, make sure to download and install the libraries such as.
WiFi.h
WiFiAP.h
WebServer.h
HTTPClient.h

To use this library you will have to import in your project:
1. Import the library YoupilabLibraryEsp32. YoupilabLibraryEsp32 esp(APP_ID,APP_KEY);
2. Initialize an object of type YoupilabLibraryEsp32 which receives in parameter APP_ID, and APP_KEY, of the device created on the Youpilab iot platform. 
3. To connect to a wifi and check if the device has been connected use the VeriyToConnectWifi() method;
example: esp.VeriyToConnectWifi(ssid,password);
