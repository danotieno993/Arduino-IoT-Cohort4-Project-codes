//******************************************
//ESP8266 Access Point Control of LED
//******************************************

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//user interface HTML code
String html = R"***(
<!DOCTYPE html>
<html>
  <head>    
    <title>SWITCH LED</title>
  </head>
  <body>
    <h1>SWITCH RED LED</h1>
    <p><a href=/redledon>RedLED on</a></p>
    <p><a href=/redledoff>RedLED off</a></p>

    <h1>SWITCH ORANGE LED</h1>
    <p><a href=/orangeledon>OrangeLED on</a></p>
    <p><a href=/orangeledoff>OrangeLED off</a></p>

    <h1>SWITCH GREEN LED</h1>
    <p><a href=/greenledon>GreenLED on</a></p>
    <p><a href=/greenledoff>GreenLED off</a></p>
  </body>
</html>

)***";

//Define pins connected to LEDs
#define RedLED D0
#define OrangeLED D1
#define GreenLED D2

const char* ssid = "ESP8266_AP";
IPAddress IPaddr (192, 168, 168, 168);
IPAddress IPmask(255, 255, 255, 0);
ESP8266WebServer server(80);


void handleRoot()
{
  server.send(200, "text/html", html);
  server.send(200, "text/html", html);
  server.send(200, "text/html", html);
}

//manipulate red LED
void redledon()

{
  digitalWrite(RedLED, 1);
  server.send(200, "text/html", html);
}
void redledoff()
{
  digitalWrite(RedLED, 0);
  server.send(200, "text/html", html);
}

//manipulate orage LED
void orangeledon()
{
  digitalWrite(OrangeLED, 1);
  server.send(200, "text/html", html);
}

void orangeledoff()
{
  digitalWrite(OrangeLED, 0);
  server.send(200, "text/html", html);
}

//manipulate Green LED
void greenledon()
{
  digitalWrite(GreenLED, 1);
  server.send(200, "text/html", html);
}

void greenledoff()
{
  digitalWrite(GreenLED, 0);
  server.send(200, "text/html", html);
}

//===============================================

void setup()
{

  pinMode(RedLED, OUTPUT);
  pinMode(OrangeLED, OUTPUT); 
  pinMode(GreenLED, OUTPUT); 
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid);
  WiFi.softAPConfig(IPaddr, IPaddr, IPmask);

  IPAddress myIP = WiFi.softAPIP();
  Serial.println("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/redledon", redledon);
  server.on("/redledoff", redledoff);
  server.on("/orangeledon", orangeledon);
  server.on("/orangeledoff", orangeledoff);
  server.on("/greenledon", greenledon);
  server.on("/greenledoff", greenledoff);
  server.begin();
  Serial.println("HTTP server started");

}

//===============================================

void loop()
{
  server.handleClient();
}
