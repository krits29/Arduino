int buzzerpin = 5;

void setup() 
{
  Serial.begin(9600);
  pinMode(buzzerpin,OUTPUT);
}

void loop() 
{
  char c = 'a';
  if(Serial.available())
  {
    c = Serial.read();
    if(c=='a')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(2272/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(2272/2);
        digitalWrite(buzzerpin, HIGH);
      }
    }
    else if(c=='b')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(2028/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(2028/2);
        digitalWrite(buzzerpin, HIGH);
      }
    }
    else if(c=='c')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(1912/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(1912/2);
        digitalWrite(buzzerpin, HIGH);
      }
    } 
    else if(c=='d')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(3400/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(3400/2);
        digitalWrite(buzzerpin, HIGH);
      } 
    }
    else if(c=='e')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(3038/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(3038/2);
        digitalWrite(buzzerpin, HIGH);
      }
    }
    else if(c=='f')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(2864/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(2864/2);
        digitalWrite(buzzerpin, HIGH);
      }
    }
    else if(c== 'g')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(2550/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(2550/2);
        digitalWrite(buzzerpin, HIGH);
      }
    }
    else if(c== 'C')
    {
      for(int i = 0; i<200; i++)
      {
        digitalWrite(buzzerpin, HIGH);
        delayMicroseconds(3830/2);
        digitalWrite(buzzerpin, LOW);
        delayMicroseconds(3830/2);
        digitalWrite(buzzerpin, HIGH);
      }
    }
  }
}

