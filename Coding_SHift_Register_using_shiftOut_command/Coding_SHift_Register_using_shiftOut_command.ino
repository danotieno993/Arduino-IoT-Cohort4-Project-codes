// this is the code to show numbers 0-9 for 7 segment using shift register common Anode

const int dataPin=8;
const int latchPin=10;
const int clockPin=11;


// the binary numbers of 0-9 are initalized in an array.You get these by adding OB infornt of the Truh table combination
int dataArray[10]={0B00000011,0B10011111,0B00100101,0B00001101,0B10011001,0B01001001,0B01000001,
0B00011111,0B00000001,0B00001001}; 


void setup() {
  // put your setup code here, to run once:
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    for (int index=0; index<10; index++)
    {
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,dataArray[index]);
  digitalWrite(latchPin,HIGH);

  delay(1000);
    }
}
