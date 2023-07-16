// This program is to turn on and off the LEDS within the 7 segment LED(Common Anode) using for loop

//identifying the pins
const int ledPinA=2;
const int ledPinB=3;
const int ledPinC=4;
const int ledPinD=5;
const int ledPinE=6;
const int ledPinG=7;
const int ledPinF=8;

void setup() {
  
  // Setting up the pins to be an output using for loop
  
  for(int i=2;i<9;i++)
  {
    pinMode(i,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

 // for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }
 delay(1000);

//For Common Anode LED, individual cathods must beconnected to LOW signal in order to turn on the LEDs while common Anode conneted to 5V supply
 //display 0
 digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinC,LOW);
 digitalWrite(ledPinD,LOW);
 digitalWrite(ledPinE,LOW);
 digitalWrite(ledPinF,LOW);

delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }
  
//display 1; LED B&C will be on
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinC,LOW);

delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }
  
//display 2

digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinD,LOW);
 digitalWrite(ledPinE,LOW);
 digitalWrite(ledPinG,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }

  //display 3
 digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinC,LOW);
 digitalWrite(ledPinD,LOW);
 digitalWrite(ledPinG,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }

  //display 4
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinC,LOW);
 digitalWrite(ledPinF,LOW);
 digitalWrite(ledPinG,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }

    //display 5
 digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinC,LOW);
 digitalWrite(ledPinD,LOW);
 digitalWrite(ledPinF,LOW);
 digitalWrite(ledPinG,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }

      //display 6
 digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinC,LOW);
 digitalWrite(ledPinD,LOW);
 digitalWrite(ledPinE,LOW);
 digitalWrite(ledPinF,LOW);
 digitalWrite(ledPinG,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }
        //display 7
 digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinC,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }
        //display 8
 digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinC,LOW);
 digitalWrite(ledPinD,LOW);
 digitalWrite(ledPinE,LOW);
 digitalWrite(ledPinF,LOW);
 digitalWrite(ledPinG,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }
       //display 9
 digitalWrite(ledPinA,LOW);
 digitalWrite(ledPinB,LOW);
 digitalWrite(ledPinC,LOW);
 digitalWrite(ledPinF,LOW);
 digitalWrite(ledPinG,LOW);

 delay(1000);

// for loop to turn off the 7 segement LEDs  
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
  }
}
