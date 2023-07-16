//Initialize 7segment LED pins to be connected to Arduino
const int ledPinA=2;
const int ledPinB=3;
const int ledPinC=4;
const int ledPinD=5;
const int ledPinE=6;
const int ledPinG=7;
const int ledPinF=8;

void setup() {
  // put your setup code here, to run once:
  //set 7 segment LED pins to act as Output
  
  //pinMode(ledPinA,OUTPUT);
  //pinMode(ledPinB,OUTPUT);
  //pinMode(ledPinC,OUTPUT);
  //pinMode(ledPinD,OUTPUT);
  //pinMode(ledPinE,OUTPUT);
  //pinMode(ledPinG,OUTPUT);
 // pinMode(ledPinF,OUTPUT);
 
 //Use for loop to iterate instead

 for(int i=2;i<9;i++)
 {
  pinMode(i,OUTPUT);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
  //For Common Anode LED, individual cathods connected to LOW signal
  //in order to turn on the LEDs while common Anode conneted to 5V supply
 
 //Turns OFF all LEDs for a start as a good practice
 //digitalWrite(ledPinA,HIGH);

 //use for loop

 for(int i=2;i<9;i++)
 {
  digitalWrite(i,HIGH);
 }
 //digitalWrite(ledPinB,HIGH);
 //digitalWrite(ledPinC,HIGH);
 //digitalWrite(ledPinD,HIGH);
 //digitalWrite(ledPinE,HIGH);
 //digitalWrite(ledPinG,HIGH);
 //digitalWrite(ledPinF,HIGH);

 //Then Turn On and Off the LEDs
 
 digitalWrite(ledPinA,LOW); //turn ON LED
 delay(1000);
 digitalWrite(ledPinA,HIGH);  //turns OFF LED

 digitalWrite(ledPinB,LOW); //turn ON LED
 delay(1000);
 digitalWrite(ledPinB,HIGH);  //turns OFF LED

 digitalWrite(ledPinC,LOW); //turn ON LED
 delay(1000);
 digitalWrite(ledPinC,HIGH);  //turns OFF LED

 digitalWrite(ledPinD,LOW); //turn ON LED
 delay(1000);
 digitalWrite(ledPinD,HIGH);  //turns OFF LED

  digitalWrite(ledPinE,LOW); //turn ON LED
 delay(1000);
 digitalWrite(ledPinE,HIGH);  //turns OFF LED

 digitalWrite(ledPinG,LOW); //turn ON LED
 delay(1000);
 digitalWrite(ledPinG,HIGH);  //turns OFF LED

 digitalWrite(ledPinF,LOW); //turn ON LED
 delay(1000);
 digitalWrite(ledPinF,HIGH);  //turns OFF LED
}
