#include <Wire.h>

int x = 0;
void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600); 
}
void loop() {//while(Serial.available()>0){
 // int x=Serial.read();
 

  Wire.beginTransmission(8); // transmit to device #9
  Wire.write(1);              // sends x 
  Wire.endTransmission();    // stop transmitting
  //x++; // Increment x
  //if (x > 5) x = 0; // `reset x once it gets 6
  //delay(500);
}

