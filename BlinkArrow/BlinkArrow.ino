int ledpin1 = 1;
int ledpin2 = 2;
int ledpin3 = 3;

void setup() 
{
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);

}

void loop() 
{
  digitalWrite(ledpin1, HIGH); 
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  delay(200);
  digitalWrite(ledpin1, LOW); 
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, LOW);
  delay(200);
  digitalWrite(ledpin1, LOW); 
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, HIGH);
  delay(200);
}
