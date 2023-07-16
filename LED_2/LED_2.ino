// C++ code
//Intialization
int RedLED = 13;
int GreenLED = 11;
int BlueLED = 7;
int dt = 4000;

void setup()
{
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
}

void loop()
{
  digitalWrite(RedLED, HIGH);
  digitalWrite(GreenLED, LOW);
  digitalWrite(BlueLED, LOW);
  delay(dt); #// Wait for dt millisecond(s)
  
  digitalWrite(RedLED, LOW);
  digitalWrite(GreenLED, HIGH);
  digitalWrite(BlueLED, LOW);
  delay(dt);// Wait for dt millisecond(s)
  
  digitalWrite(RedLED, LOW);
  digitalWrite(GreenLED, LOW);
  digitalWrite(BlueLED, HIGH);
  delay(dt); // Wait for dt millisecond(s)
}
