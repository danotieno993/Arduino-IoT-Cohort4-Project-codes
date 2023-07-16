/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
const int RedLed=9;
const int BlueLed=10;
const int YellowLed=11;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);

  pinMode(RedLed,OUTPUT);
  pinMode(BlueLed,OUTPUT);
  pinMode(RedLed,OUTPUT);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){  //if key is pressed, key is printed & LEDs should light
    Serial.println(key);

    switch(key)
    {
      case '1':
      digitalWrite(RedLed,HIGH);
      delay(1000);
      break;

      case '2':
      digitalWrite(BlueLed,HIGH);
      delay(1000);
      break;

      Case '3':
      digitalWrite(YellowLed,HIGH);
      delay(1000);
      break;

      case '0':  //Turn off all LEDs
      digitalWrite(RedLed,LOW);
      digitalWrite(BlueLed,LOW);
      digitalWrite(YelloLed,LOW);
      delay(1000);
      break;
     }
  }
}
