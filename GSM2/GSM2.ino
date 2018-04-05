#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

void setup()
{
  mySerial.begin(115200);               // the GPRS baud rate   
  Serial.begin(9600);                 // the GPRS baud rate   
}

void loop()
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());  

}
