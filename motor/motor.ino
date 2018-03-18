int in1=6;
int in2=9;

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  analogWrite(in1,0);
  delay(2000);
  analogWrite(in2,255);
  delay(2000);
  // put your main code here, to run repeatedly:

}
