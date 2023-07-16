#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <DHT.h>

DHT my_sensor(D3, DHT11);

float temperature, humidity;



void setup() {

Serial.begin(115200);
my_sensor.begin();

}

void loop() {
humidity = my_sensor.readHumidity();
temperature = my_sensor.readTemperature();

Serial.print("Temperature: ");
Serial.print(temperature);
Serial.print(" °C ;  Humidity: ");
Serial.print(humidity);
Serial.println("%");

delay(2000);

}