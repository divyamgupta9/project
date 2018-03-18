#include <SoftwareSerial.h>
void esp_8266a();
void esp_8266d();
void esp_8266t();
// LED 
int i;
int ledPin = 13;
int sensor_pin=A0;  // variable for sensor
float sample=0;
float bat_volt =0;     // for temperature

// replace with your channel's thingspeak API key
String apiKey = "XUEYYQLDJU4HRW05";

// connect 2 to TX of Serial USB
// connect 3 to RX of serial USB
SoftwareSerial ser(2,3); // RX, TX

// this runs once
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);    

  // enable debug serial
  Serial.begin(9600); 
  // enable software serial
  ser.begin(9600);
  
  // reset ESP8266
  ser.println("AT+RST");
}


// the loop 
void loop() {
  
  // blink LED on board
  digitalWrite(ledPin, HIGH);   
  delay(200);               
  digitalWrite(ledPin, LOW);
scanf("%d",&i);
  //voltage();
  if(i=1)
  {
    Serial.println("ESP");
    //esp_8266a();
       esp_8266d();
      //    esp_8266t();
    }
}
void esp_8266a()/////////GALTIII
{
  Serial.println("ACTIVATE START");
 // convert to string
  char buf[32];
  String strVolt;
 // String strVolt = dtostrf( bat_volt, 4, 1, buf);
  strVolt=45;
  Serial.print(strVolt);
  Serial.println(" V");
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(strVolt);
  getStr += "\r\n\r\n";
//GET /update?api_key=XUEYYQLDJU4HRW05&field1=76\r\n\r\n
  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(1000);  
  Serial.println("ACTIVATE END");
}

void esp_8266d()
{
  Serial.println("DEACTIVATE START");
 // convert to string
  char buf[32];
  String strVolt;
 // String strVolt = dtostrf( bat_volt, 4, 1, buf);
  strVolt=45;
  Serial.print(strVolt);
  Serial.println(" V");
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field2=";
  getStr += String(strVolt);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(1000);  
  Serial.println("DEACTIVATE END");
}
void esp_8266t()
{
  Serial.println("THIEF START");
 // convert to string
  char buf[32];
  String strVolt;
 // String strVolt = dtostrf( bat_volt, 4, 1, buf);
  strVolt=45;
  Serial.print(strVolt);
  Serial.println(" V");
  // TCP connection
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);
   
  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }
  
  // prepare GET string
  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field3=";
  getStr += String(strVolt);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

  if(ser.find(">")){
    ser.print(getStr);
  }
  else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
    
  // thingspeak needs 15 sec delay between updates
  delay(1000);  
  Serial.println("THIEF END");
}
