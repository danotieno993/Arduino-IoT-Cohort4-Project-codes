/*
 Interface Hitachi HD44780 driver 16x2 LCD

  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
 	 * ends to +5V and ground
  	 * wiper to LCD VO pin (pin 3)
  * LED Cathod - Ground
  * LED Anode - +5V through 330 ohms R
*/
//include libraries
#include <LiquidCrystal.h>

//Intialization
int dt = 500; //delay
const int rs=12, e=11, d4=5, d5=4, d6=3, d7=2; //initialize LCD pins connected to Arduino
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);  //identify pins which are connecting on LCD


// setup code to run once
void setup()
{
  Serial.begin(9600); //initial serial communication @9600bits/sec baud rate
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.

  // Print on LCD
  lcd.setCursor(15, 0);  
  lcd.print("I am IOT");
  lcd.setCursor(15, 1); //set cursor at column 16, row 2
  lcd.print("A Member of IOT Group 2!");
  
}

//loop to run continously
void loop()
{
  // scroll one position at a time to the left for the entire string length (19)
  for (int positionCounter = 0; positionCounter < 19; positionCounter++) 
  {
    lcd.scrollDisplayLeft();
    delay(dt);  // wait for 0.5 second:
  }
  // Print on Serial Monitor in every loop.
    Serial.println("I am IOT. A Member of IOT Group 2!");
    delay(dt);  // wait for 0.5 second:
  
}

