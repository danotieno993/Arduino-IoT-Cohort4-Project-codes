// **********************************************
// Send DHT11 sensor data to Things boardcloud cloud
//*************************************************

//************Libraries to Install*************
// Arduino_Json by Arduino --version 0.2.0
// Arduino Thingsboard by ThingsBoard Team -->Version 0.6
// PubSubClient by Nick O'Leary -->Version 2.6
// WiFiEsp by bportaluri ---Version 2.2.2
// Adafruit Unified Sensor by Adafruit -->Version 1.1.9
// DHT sensor library by Adafruit --Version 1.4.4
//*********End of Libraries******************************

//Include Build in lib
#include "DHT.h"
#include <ESP8266WiFi.h>
#include <ThingsBoard.h>

// #define WIFI_AP "Eng. Otieno - M"
// #define WIFI_PASSWORD "Daniel123@#$"
#define WIFI_AP "Eng Otieno - R"
#define WIFI_PASSWORD "5Aim95AnRgb"

#define TOKEN "DKHIAm4iCP3tOtCvdhgn"  //The device access token on thingsbord 

// DHT
#define DHTPIN D4
#define DHTTYPE DHT11

char thingsboardServer[] = "thingsboard.cloud"; //sends the data to thingsboard cloud & not things board local server 

WiFiClient wifiClient;

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

ThingsBoard tb(wifiClient);

int status = WL_IDLE_STATUS;
unsigned long lastSend;

//setup code to run once
void setup()
{
  Serial.begin(115200);  //define the baud rate
  dht.begin();
  delay(10);
  InitWiFi();
  lastSend = 0;
}

void loop()
{
  if ( !tb.connected() ) {
    reconnect();
  }

  if ( millis() - lastSend > 1000 ) { // Update and send only after 1 seconds
    getAndSendTemperatureAndHumidityData();
    lastSend = millis();
  }

  tb.loop();
}

void getAndSendTemperatureAndHumidityData()
{
  Serial.println("Collecting temperature data.");

  // Reading temperature or humidity takes about 250 milliseconds!
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println("Sending data to ThingsBoard....");
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println("°C");

  tb.sendTelemetryFloat("temperature", temperature);
  tb.sendTelemetryFloat("humidity", humidity);
}

//Connect to Wifi
void InitWiFi()
{
  Serial.println("Connecting to WiFi AP ...");
  // attempt to connect to WiFi network

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting to WiFi AP.Please Wait ....");
  }
  Serial.println("Connected to WiFi AP!");
}

//Reconnect to WiFi & Thingsboard
void reconnect() {
  // Loop until we're reconnected
  while (!tb.connected()) {
    status = WiFi.status();
    if ( status != WL_CONNECTED) {
      WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print("Connecting to WiFi AP......");
      }
      Serial.println("Connected to WiFi AP!");
    }
    Serial.print("Connecting to ThingsBoard Cloud .....");
    if ( tb.connect(thingsboardServer, TOKEN) ) {
      Serial.println( "[Connected to Thingsboard Successfully!]" );
    } else {
      Serial.print( "[Connection to thingsboard FAILED!]" );
      Serial.println( " : retrying in 5 seconds]" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}