#include <iostream>
#include <string>
#include "LPD8806.h"

const numLEDs = 6;
LPD8806 strip(numLEDs);
uint8_t r;
uint8_t g;
uint8_t b;

void initLEDs() {
  r = 0;
  g = 0; 
  b = 0;

  //Initialize for an empty strip
  for(int i=0; i<numLEDs; i++){
    strip.setPixelColor(i,r,g,b);
  }
  strip.show();

}

void displayRed() {
  r = 255;
  g = 0;
  b = 0;
  for(int i=0; i<numLEDs; i++){
    strip.setPixelColor(i,r,g,b);
  }
  strip.show();
}

void displayGreen() {
  r = 0;
  g = 255;
  b = 0;
  for(int i=0; i<numLEDs; i++){
    strip.setPixelColor(i,r,g,b);
  }
  strip.show();

}

void displayBlue() {
  r = 0;
  g = 0;
  b = 255;
  for(int i=0; i<numLEDs; i++){
    strip.setPixelColor(i,r,g,b);
  }
  strip.show();
}

void displayPurple() {
  r = 206;
  g = 84;
  b = 210;

  for(int i=0; i<numLEDs; i++){
    strip.setPixelColor(i,r,g,b);
  }
  strip.show();
}

void cycleLEDs() {
  r = 0; g = 0; b= 0;

  while(1){    
    for (int i=0; i<numLEDs;i++){
      strip.setPixelColor(i,r,g,b);
      r+=5;
      g+=10;
      b+=3;
    }
    strip.show(); //Sets the color values
    delay(100); 
  }  
}

void turnOff() {
  r = 0;
  g = 0;
  b = 0;
 
  for(int i=0; i<numLEDs; i++){
    strip.setPixelColor(i,r,g,b);
  }
  strip.show();

}

int main(int argc, char** argv) {
  if (argc != 2) {
  }
  else {
    std::string input = argv[1];
    std::string str1 = "displayRed";
    std::string str2 = "displayGreen";
    std::string str3 = "displayBlue";
    std::string str5 = "displayPurple";
    std::string str6 = "cycleLEDs";

    initLEDs();

    if (input.compare(str1) == 0)
    {
      displayRed();
    }
    else if (input.compare(str2) == 0)
    {
      displayGreen();
    }
    else if (input.compare(str3) == 0)
    {
      displayBlue();
    }
    else if (input.compare(str5) == 0)
    {
      displayPurple();
    }
    else if (input.compare(str6) == 0)
    {
      cycleLEDs();
    }

  std::cin.ignore();
  turnOff();
  return 0;
  }
}
