
#include<LiquidCrystal.h>  // include the liquid crystal library for the LCD 

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
// initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
 int randomNumberArray[27];
 


void setup() {
lcd.begin(16,2);   // set up the LCD's number of columns and rows:
}
 
void loop() { 
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);

  for (int i=0;i<27;i++)
  {
    radomNumberArray[i]=random(9); //random number generator between 0&9 that is stored in arrayb index
    lcd.print(randomNumberArray[i]);
    lcd.scrollDisplayLeft(); //enables scrolling of display to the left
    lcd.print(" ");
    delay(250);
    }

}
