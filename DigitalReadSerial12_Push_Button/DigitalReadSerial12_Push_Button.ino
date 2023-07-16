/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/

// digital pin 12 has a pushbutton attached to it. Give it a name:
int pushButton=12;
int LED=3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(LED, OUTPUT);  //set pin 3 as output pin
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  if (buttonState==HIGH)
  {
    digitalWrite(LED, HIGH); //turn LED on when pushbutton is pressed
    Serial.print("Pushbutton is pressd, value is : ");  //prints on serial monitor
    Serial.println(buttonState);
  }
  else
  {
    digitalWrite(LED,LOW); //turns off LED when pushbutton is released
  }

  delay(1);        // delay in between reads for stability
}
