#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define WLAN_SSID "ClubMaker"
#define WLAN_PASS "ClubM@ker"

WiFiServer server;
bool isServerAviable = false;
void setup()
{
    Serial.begin(9600);
    
    WifiConnect();
    Serial.println("Starting http server");
    server = new WiFiServer(80);
    isServerAviable = true;
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

void loop()
{
    if(isServerAviable == false) {
        return;
    }
    WiFiClient client = server.available();
    if(client) {
        Serial.println("New Client");
    }
}