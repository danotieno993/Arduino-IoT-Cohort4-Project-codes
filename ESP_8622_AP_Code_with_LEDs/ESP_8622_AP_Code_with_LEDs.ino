//===========ESP8266 Access Point==============

//include wifi libraries -------------------------
#include <ESP8266WiFi.h>  //allow 8266 to transmit wifi signal
#include <WiFiClient.h>  //Allow ESp8266 to communicate with the browser
#include <ESP8266WebServer.h>  //create an AP using ESP 8266 microcontroller

// html string with html code for user interface -------------------------

String html = R"***(
<!DOCTYPE html>
<html>
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


// Define the pin led is connected
#define led D2

const char* ssid = "ESP8266_AP";  //AP name
const char* password = "Pass@ESP8266_AP"; 
IPAddress IPaddr(192, 168, 168, 168); //default ip = 192.168.4.1
IPAddress IPmask(255, 255, 255, 0);
ESP8266WebServer server(80);  //a pointer to be used as gateway to browser through port 80

//handleRoot() function displays html text on web browser---------------------------
void handleRoot()  
{
  server.send(200, "text/html", html); //send the html text to browser
}

//Switch on LED -----------------
void ledon()
{
  digitalWrite(led, 1);
  server.send(200, "text/html", html);
}
//Switch off the led---------------
void ledoff()
{
  digitalWrite(led, 0);
  server.send(200, "text/html", html);
}

//Setup code to run once
void setup()
{
  pinMode(led, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point.......");
  //genrate AP IP
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(IPaddr, IPaddr, IPmask);
  IPAddress MyIP = WiFi.softAPIP();
  Serial.print("My AP IP Address: ");
  Serial.println(MyIP); //default ip = 192.168.4.1
  server.on("/",handleRoot);
  server.begin();
  Serial.println("Http server stated");
  Serial.println("Execute http://192.168.168.168 on your browser to control the LEDs")

}

void loop()
{
  server.handleClient();  //maintains communication between server(microcontroller) & client(web browser)
}

//Connect to WIFi and Search WIFI IP:  192.168.168.168 on browser and enter password.