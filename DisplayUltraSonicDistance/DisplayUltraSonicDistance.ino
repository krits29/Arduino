#include "LedControl.h"

int trigPin = 6;
int echoPin = 7;
int DINPin = 12;
int CLKPin = 11;
int CSPin = 10; 
int numberOfPanels = 1;
int intensity =1;
int panelNumber = 0;

int minDistance = 0;
int maxDistance = 255;
int duration = 0;
int distance = 0;

/*int row1 = 0;
int row2 = 0;
int row3 = 0;                           
int row4 = 0;
int row5 = 0;
int row6 = 0;
int row7 = 0;
int row8 = 0;
int row9 = 0;*/

int one [8][8] = 
{
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
};
int two [8][8] = 
{
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
};
int three [8][8] = 
{
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
};
int four [8][8] = 
{
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
};
int five [8][8] = 
{
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
};
int six [8][8] = 
{
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
};
int seven [8][8] = 
{
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
};
int eight [8][8] = 
{
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
};
int nine [8][8] = 
{
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
};
int ten [8][8] = 
{
  {1, 0, 0, 1, 1, 0, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {1, 0, 0, 1, 1, 0, 0, 0},
};
int big [8][8] =
{
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
};

/*int one [8][8] = 
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};*/
LedControl lc=LedControl(DINPin, CLKPin, CSPin, numberOfPanels);

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
                    
  lc.shutdown(panelNumber, false); //switch on                  
  lc.setIntensity(panelNumber, intensity); //min intesity
  lc.clearDisplay(panelNumber); //clear the display of everything
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
    Serial.print("obstacle observed at about ");
    Serial.println(distance);
  }

  //---------------
   if(distance == 1)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(one[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = one[0][0];
        int row2 = one[1][0];
        int row3 = one[2][0];
        int row4 = one[3][0];
        int row5 = one[4][0];
        int row6 = one[5][0];
        int row7 = one[6][0];
        int row8 = one[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        one[0][j] = one[0][j+1];
        one[1][j] = one[1][j+1];
        one[2][j] = one[2][j+1];
        one[3][j] = one[3][j+1];
        one[4][j] = one[4][j+1];
        one[5][j] = one[5][j+1];
        one[6][j] = one[6][j+1];
        one[7][j] = one[7][j+1];

     
    }
       delay(150); 

        one[0][7] = row1;
        one[1][7] = row2;
        one[2][7] = row3;
        one[3][7] = row4;
        one[4][7] = row5;
        one[5][7] = row6;
        one[6][7] = row7;
        one[7][7] = row8;
   }
   else if (distance == 2)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(two[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = two[0][0];
        int row2 = two[1][0];
        int row3 = two[2][0];
        int row4 = two[3][0];
        int row5 = two[4][0];
        int row6 = two[5][0];
        int row7 = two[6][0];
        int row8 = two[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        two[0][j] = two[0][j+1];
        two[1][j] = two[1][j+1];
        two[2][j] = two[2][j+1];
        two[3][j] = two[3][j+1];
        two[4][j] = two[4][j+1];
        two[5][j] = two[5][j+1];
        two[6][j] = two[6][j+1];
        two[7][j] = two[7][j+1];

     
    }
       delay(150); 

        two[0][7] = row1;
        two[1][7] = row2;
        two[2][7] = row3;
        two[3][7] = row4;
        two[4][7] = row5;
        two[5][7] = row6;
        two[6][7] = row7;
        two[7][7] = row8;
   }
  else if (distance == 3)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(three[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = three[0][0];
        int row2 = three[1][0];
        int row3 = three[2][0];
        int row4 = three[3][0];
        int row5 = three[4][0];
        int row6 = three[5][0];
        int row7 = three[6][0];
        int row8 = three[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        three[0][j] = three[0][j+1];
        three[1][j] = three[1][j+1];
        three[2][j] = three[2][j+1];
        three[3][j] = three[3][j+1];
        three[4][j] = three[4][j+1];
        three[5][j] = three[5][j+1];
        three[6][j] = three[6][j+1];
        three[7][j] = three[7][j+1];

     
    }
       delay(150); 

        three[0][7] = row1;
        three[1][7] = row2;
        three[2][7] = row3;
        three[3][7] = row4;
        three[4][7] = row5;
        three[5][7] = row6;
        three[6][7] = row7;
        three[7][7] = row8;
   }
   else if (distance == 4)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(four[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = four[0][0];
        int row2 = four[1][0];
        int row3 = four[2][0];
        int row4 = four[3][0];
        int row5 = four[4][0];
        int row6 = four[5][0];
        int row7 = four[6][0];
        int row8 = four[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        four[0][j] = four[0][j+1];
        four[1][j] = four[1][j+1];
        four[2][j] = four[2][j+1];
        four[3][j] = four[3][j+1];
        four[4][j] = four[4][j+1];
        four[5][j] = four[5][j+1];
        four[6][j] = four[6][j+1];
        four[7][j] = four[7][j+1];

     
    }
       delay(150); 

        four[0][7] = row1;
        four[1][7] = row2;
        four[2][7] = row3;
        four[3][7] = row4;
        four[4][7] = row5;
        four[5][7] = row6;
        four[6][7] = row7;
        four[7][7] = row8;
   }
   else if (distance == 5)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(five[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = five[0][0];
        int row2 = five[1][0];
        int row3 = five[2][0];
        int row4 = five[3][0];
        int row5 = five[4][0];
        int row6 = five[5][0];
        int row7 = five[6][0];
        int row8 = five[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        five[0][j] = five[0][j+1];
        five[1][j] = five[1][j+1];
        five[2][j] = five[2][j+1];
        five[3][j] = five[3][j+1];
        five[4][j] = five[4][j+1];
        five[5][j] = five[5][j+1];
        five[6][j] = five[6][j+1];
        five[7][j] = five[7][j+1];

     
    }
       delay(175); 

        five[0][7] = row1;
        five[1][7] = row2;
        five[2][7] = row3;
        five[3][7] = row4;
        five[4][7] = row5;
        five[5][7] = row6;
        five[6][7] = row7;
        five[7][7] = row8;
   }
   else if (distance == 6)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(six[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = six[0][0];
        int row2 = six[1][0];
        int row3 = six[2][0];
        int row4 = six[3][0];
        int row5 = six[4][0];
        int row6 = six[5][0];
        int row7 = six[6][0];
        int row8 = six[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        six[0][j] = six[0][j+1];
        six[1][j] = six[1][j+1];
        six[2][j] = six[2][j+1];
        six[3][j] = six[3][j+1];
        six[4][j] = six[4][j+1];
        six[5][j] = six[5][j+1];
        six[6][j] = six[6][j+1];
        six[7][j] = six[7][j+1];

     
    }
       delay(150); 

        six[0][7] = row1;
        six[1][7] = row2;
        six[2][7] = row3;
        six[3][7] = row4;
        six[4][7] = row5;
        six[5][7] = row6;
        six[6][7] = row7;
        six[7][7] = row8;
   }
   else if (distance == 7)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(seven[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = seven[0][0];
        int row2 = seven[1][0];
        int row3 = seven[2][0];
        int row4 = seven[3][0];
        int row5 = seven[4][0];
        int row6 = seven[5][0];
        int row7 = seven[6][0];
        int row8 = seven[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        seven[0][j] = seven[0][j+1];
        seven[1][j] = seven[1][j+1];
        seven[2][j] = seven[2][j+1];
        seven[3][j] = seven[3][j+1];
        seven[4][j] = seven[4][j+1];
        seven[5][j] = seven[5][j+1];
        seven[6][j] = seven[6][j+1];
        seven[7][j] = seven[7][j+1];

     
    }
       delay(150); 

        seven[0][7] = row1;
        seven[1][7] = row2;
        seven[2][7] = row3;
        seven[3][7] = row4;
        seven[4][7] = row5;
        seven[5][7] = row6;
        seven[6][7] = row7;
        seven[7][7] = row8;
   }
   else if (distance == 8)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(eight[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = eight[0][0];
        int row2 = eight[1][0];
        int row3 = eight[2][0];
        int row4 = eight[3][0];
        int row5 = eight[4][0];
        int row6 = eight[5][0];
        int row7 = eight[6][0];
        int row8 = eight[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        eight[0][j] = eight[0][j+1];
        eight[1][j] = eight[1][j+1];
        eight[2][j] = eight[2][j+1];
        eight[3][j] = eight[3][j+1];
        eight[4][j] = eight[4][j+1];
        eight[5][j] = eight[5][j+1];
        eight[6][j] = eight[6][j+1];
        eight[7][j] = eight[7][j+1];

     
    }
       delay(150); 

        eight[0][7] = row1;
        eight[1][7] = row2;
        eight[2][7] = row3;
        eight[3][7] = row4;
        eight[4][7] = row5;
        eight[5][7] = row6;
        eight[6][7] = row7;
        eight[7][7] = row8;
   }
   else if (distance == 9)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(nine[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = nine[0][0];
        int row2 = nine[1][0];
        int row3 = nine[2][0];
        int row4 = nine[3][0];
        int row5 = nine[4][0];
        int row6 = nine[5][0];
        int row7 = nine[6][0];
        int row8 = nine[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        nine[0][j] = nine[0][j+1];
        nine[1][j] = nine[1][j+1];
        nine[2][j] = nine[2][j+1];
        nine[3][j] = nine[3][j+1];
        nine[4][j] = nine[4][j+1];
        nine[5][j] = nine[5][j+1];
        nine[6][j] = nine[6][j+1];
        nine[7][j] = nine[7][j+1];

     
    }
       delay(175); 

        nine[0][7] = row1;
        nine[1][7] = row2;
        nine[2][7] = row3;
        nine[3][7] = row4;
        nine[4][7] = row5;
        nine[5][7] = row6;
        nine[6][7] = row7;
        nine[7][7] = row8;
   }
   else if (distance == 10)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(ten[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = ten[0][0];
        int row2 = ten[1][0];
        int row3 = ten[2][0];
        int row4 = ten[3][0];
        int row5 = ten[4][0];
        int row6 = ten[5][0];
        int row7 = ten[6][0];
        int row8 = ten[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        ten[0][j] = ten[0][j+1];
        ten[1][j] = ten[1][j+1];
        ten[2][j] = ten[2][j+1];
        ten[3][j] = ten[3][j+1];
        ten[4][j] = ten[4][j+1];
        ten[5][j] = ten[5][j+1];
        ten[6][j] = ten[6][j+1];
        ten[7][j] = ten[7][j+1];

     
    }
       delay(150); 

        ten[0][7] = row1;
        ten[1][7] = row2;
        ten[2][7] = row3;
        ten[3][7] = row4;
        ten[4][7] = row5;
        ten[5][7] = row6;
        ten[6][7] = row7;
        ten[7][7] = row8;
   }
   else if (distance > 10)
   {
    for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(big[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = big[0][0];
        int row2 = big[1][0];
        int row3 = big[2][0];
        int row4 = big[3][0];
        int row5 = big[4][0];
        int row6 = big[5][0];
        int row7 = big[6][0];
        int row8 = big[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        big[0][j] = big[0][j+1];
        big[1][j] = big[1][j+1];
        big[2][j] = big[2][j+1];
        big[3][j] = big[3][j+1];
        big[4][j] = big[4][j+1];
        big[5][j] = big[5][j+1];
        big[6][j] = big[6][j+1];
        big[7][j] = big[7][j+1];

     
    }
       delay(175); 

        big[0][7] = row1;
        big[1][7] = row2;
        big[2][7] = row3;
        big[3][7] = row4;
        big[4][7] = row5;
        big[5][7] = row6;
        big[6][7] = row7;
        big[7][7] = row8;
   }
}
