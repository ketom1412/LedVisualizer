#include "FastLED.h"

#define NUM_LEDS 300 //Number of LEDS in strip
#define DATA_PIN 6 //Pin to transfer data to led strip for left
#define updateLEDS 5 //distance between each strand of led

CRGB ledsLeft[NUM_LEDS]; //Set up block of memory for storing and
                         //manipulating led data
int bright;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A4, INPUT);
   
  //This tells the library theres a strand of Neopixels at pin 6
  //The strip will use the led array and has NUM_LEDS leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(ledsLeft, NUM_LEDS);
  bright = 1;
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--)
  {
    ledsLeft[i] = ledsLeft[i - updateLEDS];
    //ledsRight[i] = ledsRight[i - updateLEDS];
  }

  int full = analogRead(A4);
  //Serial.println((full+1)/4);//map volume to 0-255

  //160 is good
  //190 is good
  if((full + 1)/4 > 170)//The value you compare it to is based on preference
  {
    bright = 1;
  }
  else
  {
    bright = 0;
  }
  //Serial.println(bright);
  int freq = analogRead(A0);
  
  //The +no is just for me since i want certain songs to be 
  //of a certain color for certain songs, you can play with it
  //100 is good
  //215 is good
  CHSV newColor((freq+155)%255, 255, 255*bright); 
  CRGB ledColor;

  //Convert from HSV to RGB color space
  hsv2rgb_rainbow(newColor, ledColor);
  //outputColor(ledColor);
  for(int i = 0; i < updateLEDS; i++)
  {
    ledsLeft[i] = CRGB(ledColor[0], ledColor[1], ledColor[2]);
  }

  FastLED.show();

  delay(1);
}

void outputVal(int freq, int full)
{
  Serial.print("Freq: ");
  Serial.println(freq);
  Serial.print("Volume: ");
  Serial.println(full);
}

void outputColor(CRGB ledColor)
{
  Serial.print(ledColor[0]);
  Serial.print(' ');
  Serial.print(ledColor[1]);
  Serial.print(' ');
  Serial.println(ledColor[2]);
}
