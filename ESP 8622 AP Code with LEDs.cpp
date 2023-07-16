//include wifi libraries
#include <ESP8266WiFi.h> 
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// creating an HTML page

String html = R"***(
  <!DOCTYPE html>
  <head>
  <title>Switching LED</title>
  </head>
  <body>
  <h1>Switch LED</h1>
  <p><a href=/ledon>LED ON</a></p>
  <p><a href=/ledoff>LED OFF</a></p>
  </body>
  </html>

)***";

// Manipulating the LED
#define led D2

const char* ssid = "ESP8266_AP";
const char* password = "Pass@ESP8266_AP";
IPAddress IPaddr(192, 168, 168, 168);
IPAddress IPmask(255, 255, 255, 0);
ESP8266WebServer server(80);

void handleRoot()
{

  server.send(200, "text/html", html);

}

void ledon()
{
  digitalWrite(led, 1);
  server.send(200, "text/html", html);

}

void ledoff()
{
  digitalWrite(led, 0);
  server.send(200, "text/html", html);
}

void setup()
{
  pinMode(led, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("configuring accesspoint");
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(IPaddr, IPaddr, IPmask);
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
}

//Search WIFI IP:  192.168.4.1 on browser and enter password. This should be the only availbale network