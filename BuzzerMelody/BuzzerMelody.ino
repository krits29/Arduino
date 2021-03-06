int BuzzerPin = 5;

  int c = 3830;
  int d = 3400;
  int e = 3038;
  int f = 2864;
  int g = 2550;
  int a = 2272;
  int b = 2028;
  int C = 1912;
  int R = 0;

int melody[] = {C, b, g, C, b, e, C, c, g, a, C, C, b, g, C, b, e, C, c, g, a, C, C, b, g, C, b, e, C, c, g, a, C};
int beats[] = {16, 16, 8, 8, 16, 16, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 16, 16, 8, 8, 16, 16, 8, 8, 16, 16, 16, 16, 8, 8}; 


int MaxTonesInMelody = 12; // melody array length, for use in for loop

//set overall tempo
long oneBeatInMicroseconds = 20000;

//set length of pause between notes
int pause = 1000;
 
void setup() 
{  
  pinMode(BuzzerPin, OUTPUT);
}

int currentNote = 0;

long durationToPlayNote = 0;

void loop() 
{
  //find the current note
  //calculate how long to play it
  //play it and then move to the next note

  durationToPlayNote = beats[currentNote] * oneBeatInMicroseconds;      

  if(melody[currentNote] > 0)
  {                                                                    
  for(long i = 0; i < durationToPlayNote; i += melody[currentNote])
  {
    digitalWrite(BuzzerPin, HIGH);
    delayMicroseconds(melody[currentNote]/2);
    digitalWrite(BuzzerPin, LOW);
    delayMicroseconds(melody[currentNote]/2);
  }
  }
  else
  {
    delayMicroseconds(1000);
  }
  
  currentNote++;
  if(currentNote >+ MaxTonesInMelody)
  {
    currentNote = 0;
  }  
}


