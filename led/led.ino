#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <Keypad.h>
#include <SoftwareSerial.h>
#define buzzer 13
SoftwareSerial mySerial();
int pir =11;
int screenOffMsg =0;
String password="1111";
String tempPassword;
boolean activated = false; // State of the alarm
boolean isActivated;
boolean activateAlarm = false;
boolean alarmActivated = false;
boolean enteredPassword; // State of the entered password to stop the alarm
boolean passChangeMode = false;
boolean passChanged = false;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keypressed;
//define the cymbols on the buttons of the keypads
char keyMap[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A5,A4,A3,A2}; //Row pinouts of the keypad
byte colPins[COLS] = {A1,A0,9,10}; //Column pinouts of the keypad
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(2,3,4,5,7,8); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

void setup() { 
  lcd.begin(16,2); 
  analogWrite(6,70);
  Serial.begin(9600);
 // mySerial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  
     if (activateAlarm){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Alarm is ON");
     activateAlarm = false;
     alarmActivated = true;
  }
 
    if (alarmActivated == true){
      int PIR = digitalRead(11);
      if (PIR==HIGH)
      {
        tone(buzzer, 1000); // Send 1KHz sound signal 
        delay(1000);                  
        Serial.print("ATD +917014922669;\r");//Phone number you want to call
        delay(7000);
        Serial.print("ATH;\r");
        Serial.println("AT+CMGF=1"); // set the SMS mode to text
        Serial.write("AT+CMGS=");
        Serial.write(34); //ASCII of "
        Serial.write("+917014922669");
        Serial.write(34);
        Serial.write(13);
        Serial.write(10);
      
        Serial.println("ALERT"); //this is the message to be sent
        delay(2500);
        Serial.write(26);
        Serial.write(13);
        Serial.write(10);//Ascii code of ctrl+z to send the message
       // delay(500);
        for(int n=1;n<=3;n++)
        {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("     ALERT  ");
        delay(500);
        lcd.clear();
        delay(500);
        }
        enterPassword();
}
 }
  if (!alarmActivated) {
    if (screenOffMsg == 0 ){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("A - Activate");
      lcd.setCursor(0,1);
      lcd.print("B - Change Pass");
      screenOffMsg = 1;
    }
    keypressed = myKeypad.getKey();
     if (keypressed =='A'){        //If A is pressed, activate the alarm
      tone(buzzer, 1000, 200);
      activateAlarm = true; 
digitalWrite(13,HIGH);
    }
    else if (keypressed =='B') {
      lcd.clear();
      digitalWrite(13,HIGH);
      int i=1;
      tone(buzzer, 2000, 100);
      tempPassword = "";
      lcd.setCursor(0,0);
      lcd.print("Current Password");
      lcd.setCursor(0,1);
      lcd.print(">");
      passChangeMode = true;
      passChanged = true;    
      while(passChanged) {      
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
         tempPassword += keypressed;
         lcd.setCursor(i,1);
         lcd.print(keypressed);
         i++;
         tone(buzzer, 2000, 100);
        }
      }
      if (i > 5 || keypressed == '#') {
        tempPassword = "";
        i=1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Current Password");
        lcd.setCursor(0,1);
        lcd.print(">"); 
      }
      if ( keypressed == '*') {
       i=1;
      // tone(buzzer, 2000, 100);
     if (password == tempPassword) {
          tempPassword="";
          Serial.println(keypressed);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Set New Password");
          lcd.setCursor(0,1);
          lcd.print(">");
          while(passChangeMode) {
            keypressed = myKeypad.getKey();
            if (keypressed != NO_KEY){
              if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
                  keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
                  keypressed == '8' || keypressed == '9' ) {
                tempPassword += keypressed;
                lcd.setCursor(i,1);
                lcd.print(keypressed);
                i++;
                tone(buzzer, 2000, 100);
              }
            }
            if (i > 5 || keypressed == '#') {
              tempPassword = "";
              i=1;
              tone(buzzer, 2000, 100);
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Set New Password");
              lcd.setCursor(0,1);
              lcd.print(">");
            }
            if ( keypressed == '*') {
              
             //tone(buzzer, 2000, 100);
             i=1;
              password = tempPassword;
              passChangeMode = false;
              passChanged = false;
              screenOffMsg = 0;
              digitalWrite(13,HIGH);
            }            
          }
        }
      }
    }
   }
 }
}
void enterPassword() {
  int k=5;
  int m=0;
  tempPassword = "";
  activated = true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" *** ALARM ***");
  lcd.setCursor(0,1);
  lcd.print("Pass>");
      while(activated) {
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
          tempPassword += keypressed;
          lcd.setCursor(k,1);
          lcd.print(keypressed);
          k++;
          Serial.println(keypressed);
          
        }
      }
      if (k > 9 || keypressed == '#') {
        tempPassword = "";
        k=5;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" *** ALARM *** ");
        lcd.setCursor(0,1);
        lcd.print("Pass>");
      }
      if ( keypressed == '*') {
        if ( tempPassword == password ) {
          activated = false;
          alarmActivated = false;
          noTone(buzzer);
          digitalWrite(13,LOW);
          screenOffMsg = 0; 
        }
        else if (tempPassword != password) {
          m++;
          lcd.setCursor(0,1);
          lcd.print("LOL! WRONG");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(" *** ALARM *** ");
          lcd.setCursor(0,1);
          lcd.print("Pass>");
          if(m>2)
          {
             int countdown = 5; // 5 seconds count down before activating the alarm
             while (countdown != 0) {
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("ACCESS DENIED");
             lcd.setCursor(0,1);
             lcd.print("Wait For ");
             lcd.setCursor(9,1);
             lcd.print(countdown);
             lcd.setCursor(10,1);
             lcd.print("Sec");
             countdown--;
             delay(1000);
           }
      enterPassword();

         }
       }
     }    
   }
 }
