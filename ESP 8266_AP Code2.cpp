#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESP8266_AP";
const char* password = "One.Touch";
ESP8266WebServer server(80);

void handleRoot()
{

  server.send(200, "text/html", "<h1>ESP8266 Controller Portal</h1>");

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
}

// html code to access the LED on browser

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