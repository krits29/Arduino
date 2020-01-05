int ledpin = 8;

void setup() 
{
  pinMode(ledpin, OUTPUT);

}

void loop() 
{
  digitalWrite(ledpin, HIGH); // HIGH - 5Volts
  delay(200);
  digitalWrite(ledpin, LOW); // LOW - 0volts
  delay(200);

}
