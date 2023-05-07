#include "Free_Fonts.h" // Include the header file attached to this sketch

#include "SPI.h"
#include "TFT_eSPI.h"

// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();

unsigned long drawTime = 0;

// x = 0 is left, y = 0 is top
// 
int x_topLeft =  0;
int y_topLeft = 50;

int x_topRight =  120;
int y_topRight = 50;

int x_bottomLeft =  0;
int y_bottomLeft = 110;

int x_bottomRight =  120;
int y_bottomRight = 110;

int previousThrottle = 0;
int throttle = 0;

int previousBatt = 0;
int batt = 240;

void setup(void) {

  tft.begin();

  tft.setRotation(3);

  //total resolution ist 135 x 240

  tft.fillScreen(TFT_BLACK);
  
}

void loop() 
{
  delay(10);
  
  tft.setTextColor(TFT_WHITE);

  tft.setCursor(x_topLeft, y_topLeft);    
  tft.setFreeFont(FF6);
  tft.print("U:");
  tft.setCursor(x_topLeft+35, y_topLeft);    
  tft.setFreeFont(FSB24);
  tft.print("0000");

  tft.setTextColor(TFT_RED);
  tft.setCursor(x_topRight+40, y_topRight); //offset becaus it is narrower and 3 digit RPM needs space 
  tft.setFreeFont(FF8);
  tft.print("A");
  tft.setTextColor(TFT_GREEN);
  tft.setCursor(x_topRight+90, y_topRight); //offset becaus it is narrower and 3 digit RPM needs space 
  tft.setFreeFont(FF8);
  tft.print("S");

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(x_bottomLeft, y_bottomLeft);   
  tft.setFreeFont(FF6);
  tft.print("C:");
  tft.setCursor(x_bottomLeft+35, y_bottomLeft);   
  tft.setFreeFont(FSB24);
  tft.print("000");

  tft.setCursor(x_bottomRight+30, y_bottomRight);   
  tft.setFreeFont(FF6);
  tft.print("V:");
  tft.setCursor(x_bottomRight+65, y_bottomRight);    
  tft.setFreeFont(FSB24);
  tft.print("00");

  previousThrottle = throttle;
  
  throttle = (throttle + random(0, 10) - random(0, 8)) % 240;

  if (throttle < previousThrottle) 
  {
    tft.fillRect(throttle, 130, (previousThrottle-throttle), 5, TFT_BLACK);
  }
  else
  {
    tft.fillRect(0, 130, throttle, 5, TFT_RED);
  }

  previousBatt = batt;
  
  batt -= 1;

  if (batt < 0)
  {
    batt = 240;
  }

  if (batt < previousBatt) 
  {
    tft.fillRect(batt, 0, (previousBatt-batt), 5, TFT_BLACK);
  }
  else
  {
    tft.fillRect(0, 0, batt, 5, TFT_BLUE);
  }
  

  //tft.fillScreen(TFT_BLACK);
}


#ifndef LOAD_GLCD
//ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif
