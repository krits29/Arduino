#include "LedControl.h"


int DINPin = 12;
int CLKPin = 11;
int CSPin = 10; 
int numberOfPanels = 1;
int intensity =1;
int panelNumber = 0;

int graphicPanel [8][8] = 
{
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
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



//void loop() 
//{
//  lc.setLed(panelNumber, 0, 0, true);
//  delay(500);
//
//  lc.setLed(panelNumber, 1, 0, true);
//  delay(500);
//  
//  lc.setLed(panelNumber, 2, 0, true);
//  delay(500);
//
//  lc.setLed(panelNumber, 3, 0, true);
//  delay(500);
//
//  lc.setLed(panelNumber, 4, 0, true);
//  delay(500);
//
//  lc.setLed(panelNumber, 5, 0, true);
//  delay(500);
//
//  lc.setLed(panelNumber, 6, 0, true);
//  delay(5000);
//
//  lc.setLed(panelNumber, 7, 0, true);
//  delay(500);
//  lc.setLed(panelNumber, 7, 0, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 1, 7, true);
//  delay(500);
//  lc.setLed(panelNumber, 1, 7, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 2, 7, true);
//  delay(500);
//  lc.setLed(panelNumber, 2, 7, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 3, 7, true);
//  delay(500);
//  lc.setLed(panelNumber, 3, 7, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 4, 7, true);
//  delay(500);
//  lc.setLed(panelNumber, 4, 7, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 5, 7, true);
//  delay(500);
//  lc.setLed(panelNumber, 5, 7, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 6, 7, true);
//  delay(500);
//  lc.setLed(panelNumber, 6, 7, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 7, 7, true);
//  delay(500);
//  lc.setLed(panelNumber, 7, 7, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 7, 6, true);
//  delay(500);
//  lc.setLed(panelNumber, 7, 6, false);
//  delay(500);
//
//  lc.setLed(panelNumber, 7, 5, true);
//  delay(500);
//  lc.setLed(panelNumber, 7, 5, false);
//  delay(500);
}
