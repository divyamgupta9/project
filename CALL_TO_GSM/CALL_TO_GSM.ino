void setup()
{
  Serial.begin(9600);  //Baud rate of the GSM Module 
  delay(1000);                  
  Serial.print("ATD +917014922669;\r");//Phone number you want to call
 // delay(5000);
 // Serial.print("ATH;\r");
}
void loop()
{
}
