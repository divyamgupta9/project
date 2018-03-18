#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,7,8);
//void open();//for open the gate//
//void close();//for close the gate//
//void stop();//for stop the gate//

int pir=12;
int mot1=9;
int mot2=6;
int count1=0;//to count person//
void setup()
{
Serial.begin(9600);
lcd.begin(16,2);//lcd no of column and rows(col,row)//
analogWrite(6,40);
lcd.clear();
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
pinMode(13,INPUT);
digitalWrite(13,LOW);
}
void loop()
{
int pirval=digitalRead(pir);//read value high or low//
analogWrite(9,0);
analogWrite(6,0); 
pirval==LOW;//initial state//
lcd.setCursor(0, 0);
lcd.print("closed");
if(pirval==HIGH)//for 1//
{
open();
count1++;//increment in value by 1//
}
if(pirval==LOW)//for 0//
{
stop();
}
lcd.setCursor(0,1);//set curser on(col,row)//
lcd.print("no of person:");
lcd.print(count1);//total person inside//
}
void open()
{
lcd.setCursor(0, 0);
lcd.print("opening door ");
analogWrite(9,255);
analogWrite(6,0);
delay(2000);
lcd.setCursor(0,0);
lcd.print("closing door ");
analogWrite(9,0);
analogWrite(6,255);
delay(2000);
lcd.clear();

lcd.setCursor(0, 0);
lcd.print("closed");
stop();
}




void stop()
{
analogWrite(9,0);
analogWrite(6,0);

}

   
