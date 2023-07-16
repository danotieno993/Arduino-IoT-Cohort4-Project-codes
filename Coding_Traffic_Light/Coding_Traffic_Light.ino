//Coding Traffic Light 

int GreenLED=10;
int YellowLED=11;
int RedLED=12;

void setup() {
  // put your setup code here, to run once:

//make the pins output
pinMode(GreenLED, OUTPUT);
pinMode(YellowLED, OUTPUT);
pinMode(RedLED, OUTPUT);

//initial LEDs as OFF
digitalWrite(GreenLED, LOW);
digitalWrite(YellowLED, LOW);
digitalWrite(RedLED, LOW);

//initial serial communication @9600 baud rate
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

//Yield Mode
digitalWrite(GreenLED, LOW);
digitalWrite(YellowLED, HIGH);
digitalWrite(RedLED, LOW);

Serial.println("Light mode:Yield"); //write output using serial monitor
delay(1000);//Yello LED will be on for 1 second

//Go Mode
digitalWrite(GreenLED, HIGH);
digitalWrite(YellowLED, LOW);
digitalWrite(RedLED, LOW);

Serial.println("Light mode:Go"); //write output using serial monitor
delay(2000);//Green LED will be on for 2 second

//Stop Mode
digitalWrite(GreenLED, LOW);
digitalWrite(YellowLED, LOW);
digitalWrite(RedLED, HIGH);

Serial.println("Light mode:Stop"); //write output using serial monitor
delay(2000);//RED LED will be on for 2 second
}
