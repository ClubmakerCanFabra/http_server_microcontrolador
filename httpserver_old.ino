#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//#include "ESP8266_Utils.hpp"

#define WLAN_SSID "ClubMaker"
#define WLAN_PASS "ClubM@ker"

void setup()
{
   Serial.begin(9600);
   
   WifiConnect();
   InitServer();
}

void WifiConnect()
{
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  Serial.print("Connecting to ");
  Serial.print(WLAN_SSID); Serial.println(" ...");

  int times = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(++times); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

WiFiServer server(80);

void HttpClientHandler(Client *c)
{
  
}

void loop()
{
   WiFiClient client = server.available();
   if(client) {
    HttpServer(c);
    Serial.println("New Client.");
   }
}
// https://randomnerdtutorials.com/esp8266-web-server/