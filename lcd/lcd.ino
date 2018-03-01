#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
SoftwareSerial mySerial(2,3);
int c;
int led1=13;
int led2=10;
void setup()
{
Serial.begin(9600);
delay(1000);
mySerial.begin(9600);
delay(1000);
pinMode(13,OUTPUT);
(13,LOW);
pinMode(10,OUTPUT);
digitalWrite(10,LOW);
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("enter command");
}
void loop()
{
if(mySerial.available()>0)
{
 // while(my.available())
 // {
  //String ch="";
//ch=Serial.readString();

   c = mySerial.read(); // get first number i.e. if the pin 13 then the 1st number is 1, then multiply to get 10
//  int c2=(Serial.read());
  // delay(1000);
     // int c3=c1+c2;
c=c-48;
mySerial.flush();

//delay(1000);
 // }
///my.print("entered string is=");
//my.println(c);//print the value of t
     //lcd.setCursor(0,1);
        //lcd.clear(0,1);       
lcd.setCursor(0,0);
lcd.print("enter command");
  
switch (c)
{
        case 1: 
        digitalWrite(13,HIGH);
        //lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("on1 ");
        
        break;
       
        case 2:
        digitalWrite(13,LOW);
        lcd.setCursor(0,1);
        lcd.print("off1");
        break;
        
        case 3:         
        digitalWrite(10,HIGH);
        lcd.setCursor(0,1);
        lcd.print("on2 ");
      break;
            
        case 4:          
        digitalWrite(10,LOW);
        lcd.setCursor(0,1);
        lcd.print("off2");
        break; 
        
        default:
        lcd.setCursor(0,1);
        lcd.print("enter valid command");
        }
    }
}
