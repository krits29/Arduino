int trigPin = 6;
int echoPin = 7;

int minDistance = 0;
int maxDistance = 255;
int duration = 0;
float distance = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{ //first we set the trigger pin low so that the sensor gets ready to send out a signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  //set it high for 10 microseconds - this tells the sensor to start measuring
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  //finally we set it low which finishes sending the signal
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;

  if(distance > minDistance && distance < maxDistance)
  {
    Serial.print("obstacle observed at ");
    Serial.println(distance);
  }

  
}
