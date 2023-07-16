//******************************************
//ESP8266 Access Point to Control 3 LEDs
//******************************************

//Include wifi libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//  html string with html code for user interface
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

//set AP details
const char* ssid = "ESP8266_AP";
const char* password = "Pass@ESP8266_AP";
IPAddress IPaddr (192, 168, 168, 168); //default ip = 192.168.4.1
IPAddress IPmask(255, 255, 255, 0);
ESP8266WebServer server(80);

//handleRoot() function displays html text on web browser
void handleRoot()
{
  server.send(200, "text/html", html); //send the html text to browser
}

//Control red LED
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

//Control orange LED
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

//Control Green LED
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

//Setup code to run once
void setup()
{
  pinMode(RedLED, OUTPUT);
  pinMode(OrangeLED, OUTPUT); 
  pinMode(GreenLED, OUTPUT); 
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");

  //get AP Ip
  WiFi.softAP(ssid);
  WiFi.softAPConfig(IPaddr, IPaddr, IPmask);
  IPAddress myIP = WiFi.softAPIP();
  Serial.println("AP IP address: ");
  Serial.println(myIP); //default ip = 192.168.4.1

  //urls to manipulate LEDs
  server.on("/", handleRoot);
  server.on("/redledon", redledon);
  server.on("/redledoff", redledoff);
  server.on("/orangeledon", orangeledon);
  server.on("/orangeledoff", orangeledoff);
  server.on("/greenledon", greenledon);
  server.on("/greenledoff", greenledoff);
  server.begin();
  Serial.println("HTTP server started");
  Serial.println("Execute http://192.168.168.168 on your browser to control the LEDs");

}

//loop to run continuously
void loop()
{
  server.handleClient(); //maintains communication between server(microcontroller) & client(web browser)
}

//Connect to WIFi and Search WIFI IP:  http://192.168.168.168 on browser to control LEDs.