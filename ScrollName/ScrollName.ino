#include "LedControl.h"


int DINPin = 12;
int CLKPin = 11;
int CSPin = 10; 
int numberOfPanels = 1;
int intensity =1;
int panelNumber = 0;

int row1 = 0;
int row2 = 0;
int row3 = 0;                           
int row4 = 0;
int row5 = 0;
int row6 = 0;
int row7 = 0;
int row8 = 0;
int row9 = 0;

int letterK [8][8] = 
{
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 1, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
};

int letterR [8][8] =
{
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
};

int letterI [8][8] =
{
  {0, 1, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 0, 0},
};

int letterT [8][8] =
{
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
}
;

LedControl lc=LedControl(DINPin, CLKPin, CSPin, numberOfPanels);

void setup() 
{
  // put your setup code here, to run once:                      
  lc.shutdown(panelNumber, false); //switch on                  
  lc.setIntensity(panelNumber, intensity); //min intesity
  lc.clearDisplay(panelNumber); //clear the display of everything
}

void loop()
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(letterK[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
        delay(100);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
        delay(100);
      }
    }
  }

  int row1 = letterK[0][0];
  int row2 = letterK[1][0];
  int row3 = letterK[2][0];
  int row4 = letterK[3][0];
  int row5 = letterK[4][0];
  int row6 = letterK[5][0];
  int row7 = letterK[6][0];
  int row8 = letterK[7][0];

  

  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(letterR[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
        delay(75);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
        delay(75);
      }
    }
  }
  /* row1 = letterR[0][0];
   row2 = letterR[1][0];
   row3 = letterR[2][0];
   row4 = letterR[3][0];
   row5 = letterR[4][0];
   row6 = letterR[5][0];
   row7 = letterR[6][0];
   row8 = letterR[7][0];*/
 
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(letterI[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
        delay(75);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
        delay(75);
      }
    }
  }

  /* row1 = letterI[0][0];
   row2 = letterI[1][0];
   row3 = letterI[2][0];
   row4 = letterI[3][0];
   row5 = letterI[4][0];
   row6 = letterI[5][0];
   row7 = letterI[6][0];
   row8 = letterI[7][0]; */ 
  
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(letterT[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
        delay(75);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
        delay(75);
      }
    }
  }

  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(letterI[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
        delay(75);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
        delay(75);
      }
    }
  }

 
       
    
    for(int j = 0; j <= 6; j++)
    {

        letterT[0][j] = letterT[0][j+1];
        letterT[1][j] = letterT[1][j+1];
        letterT[2][j] = letterT[2][j+1];
        letterT[3][j] = letterT[3][j+1];
        letterT[4][j] = letterT[4][j+1];
        letterT[5][j] = letterT[5][j+1];
        letterT[6][j] = letterT[6][j+1];
        letterT[7][j] = letterT[7][j+1];


        letterK[0][j] = letterK[0][j+1];
        letterK[1][j] = letterK[1][j+1];
        letterK[2][j] = letterK[2][j+1];
        letterK[3][j] = letterK[3][j+1];
        letterK[4][j] = letterK[4][j+1];
        letterK[5][j] = letterK[5][j+1];
        letterK[6][j] = letterK[6][j+1];
        letterK[7][j] = letterK[7][j+1];


        letterR[0][j] = letterR[0][j+1];
        letterR[1][j] = letterR[1][j+1];
        letterR[2][j] = letterR[2][j+1];
        letterR[3][j] = letterR[3][j+1];
        letterR[4][j] = letterR[4][j+1];
        letterR[5][j] = letterR[5][j+1];
        letterR[6][j] = letterR[6][j+1];
        letterR[7][j] = letterR[7][j+1];


        letterI[0][j] = letterI[0][j+1];
        letterI[1][j] = letterI[1][j+1];
        letterI[2][j] = letterI[2][j+1];
        letterI[3][j] = letterI[3][j+1];
        letterI[4][j] = letterI[4][j+1];
        letterI[5][j] = letterI[5][j+1];
        letterI[6][j] = letterI[6][j+1];
        letterI[7][j] = letterI[7][j+1];
    
    }
        delay(175); 
        letterK[0][7] = row1;
        letterK[1][7] = row2;
        letterK[2][7] = row3;
        letterK[3][7] = row4;
        letterK[4][7] = row5;
        letterK[5][7] = row6;
        letterK[6][7] = row7;
        letterK[7][7] = row8;
          
        letterR[0][7] = row1;
        letterR[1][7] = row2;
        letterR[2][7] = row3;
        letterR[3][7] = row4;
        letterR[4][7] = row5;
        letterR[5][7] = row6;
        letterR[6][7] = row7;
        letterR[7][7] = row8;

        letterI[0][7] = row1;
        letterI[1][7] = row2;
        letterI[2][7] = row3;
        letterI[3][7] = row4;
        letterI[4][7] = row5;
        letterI[5][7] = row6;
        letterI[6][7] = row7;
        letterI[7][7] = row8;

        letterT[0][7] = row1;
        letterT[1][7] = row2;
        letterT[2][7] = row3;
        letterT[3][7] = row4;
        letterT[4][7] = row5;
        letterT[5][7] = row6;
        letterT[6][7] = row7;
        letterT[7][7] = row8;

        letterI[0][7] = row1;
        letterI[1][7] = row2;
        letterI[2][7] = row3;
        letterI[3][7] = row4;
        letterI[4][7] = row5;
        letterI[5][7] = row6;
        letterI[6][7] = row7;
        letterI[7][7] = row8;

}


