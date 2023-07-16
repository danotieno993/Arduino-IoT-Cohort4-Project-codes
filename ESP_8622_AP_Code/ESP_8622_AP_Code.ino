
//include wifi libraries
#include <ESP8266WiFi.h> 
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//set wifi name & pass
const char* ssid = "ESP8266_AP";
const char* password = "Pass@ESP8266_AP";
ESP8266WebServer server(80);

void handleRoot()
{

  server.send(200, "text/html", "<h1>ESP8266 Controller Test Line</h1>");
  server.send(404, "text/html", "<h4>Server not found</h4>");

}

void setup()
{
  //pinMode(LED, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("configuring accesspoint");
  WiFi.softAP(ssid, password);
  IPAddress MyIP = WiFi.softAPIP();
  Serial.print("My AP IP: ");
  Serial.println(MyIP);
  server.on("/",handleRoot);
  server.begin();
  Serial.println("Http server stated");

}

void loop()
{
  server.handleClient();
  //Serial.println(MyIP);
}


//Search WIFI IP:  192.168.4.1 on browser and enter password. This should be the only availbale network