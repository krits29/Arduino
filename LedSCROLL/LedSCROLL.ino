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

int graphicPanel [8][8] = 
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
};

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
      if(graphicPanel[i][j] == 1)
      {
        lc.setLed(panelNumber, i, j, true);
      }
      else
      {
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }

        int row1 = graphicPanel[0][0];
        int row2 = graphicPanel[1][0];
        int row3 = graphicPanel[2][0];
        int row4 = graphicPanel[3][0];
        int row5 = graphicPanel[4][0];
        int row6 = graphicPanel[5][0];
        int row7 = graphicPanel[6][0];
        int row8 = graphicPanel[7][0];

    
    for(int j = 0; j <= 6; j++)
    {

        graphicPanel[0][j] = graphicPanel[0][j+1];
        graphicPanel[1][j] = graphicPanel[1][j+1];
        graphicPanel[2][j] = graphicPanel[2][j+1];
        graphicPanel[3][j] = graphicPanel[3][j+1];
        graphicPanel[4][j] = graphicPanel[4][j+1];
        graphicPanel[5][j] = graphicPanel[5][j+1];
        graphicPanel[6][j] = graphicPanel[6][j+1];
        graphicPanel[7][j] = graphicPanel[7][j+1];

     
    }
       delay(175); 

        graphicPanel[0][7] = row1;
        graphicPanel[1][7] = row2;
        graphicPanel[2][7] = row3;
        graphicPanel[3][7] = row4;
        graphicPanel[4][7] = row5;
        graphicPanel[5][7] = row6;
        graphicPanel[6][7] = row7;
        graphicPanel[7][7] = row8;

}





