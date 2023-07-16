#include <LiquidCrystal.h>

const int rs=12, en =11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16,2);  //identifies LCD columns & rows respectively. Rows:0-1, columns:0-15
}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.setCursor(0,0); //set the curser at 0.0 position 
 lcd.print("Arduino is Fun!");
 delay(500);
}
