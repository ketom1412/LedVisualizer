#include "FastLED.h"

#define NUM_LEDS 300 //Number of LEDS in strip
#define DATA_PIN 6 //Pin to transfer data to led strip for left
#define OTHER_PIN 5 //Pin to transfer data to led strip for right
#define updateLEDS 8 //distance between each strand of led

CRGB ledsLeft[NUM_LEDS]; //Set up block of memory for storing and
CRGB ledsRight[NUM_LEDS]; //manipulating led data

int bright;
int frequencyPin = 0;
int volumePin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(frequencyPin, INPUT);
  pinMode(volumePin, INPUT);
   
  //This tells the library theres a strand of Neopixels at pin 6
  //The strip will use the led array and has NUM_LEDS leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(ledsLeft, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, OTHER_PIN>(ledsRight, NUM_LEDS);
  bright = 1;
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--)
  {
    ledsLeft[i] = ledsLeft[i - updateLEDS];
    ledsRight[i] = ledsRight[i - updateLEDS];
  }

  int full = analogReadfrequencyPin);
  Serial.println((full+1)/4);//map volume to 0-255

  if((full + 1)/4 > 160)//The value you compare it to is based on preference
  {
    bright = 1;
  }
  else
  {
    bright = 0;
  }

  int freq = analogRead(volumePin);
  
  //The +17 is just for me since i want certain songs to be 
  //of a certain color for certain songs, you can play with it
  CHSV newColor((freq+17)%255, 255, 255* bright); 
  CRGB ledColor;

  //Convert from HSV to RGB color space
  hsv2rgb_rainbow(newColor, ledColor);

  for(int i = 0; i < updateLEDS; i++)
  {
    ledsLeft[i] = CRGB(ledColor[0], ledColor[1], ledColor[2]);
    ledsRight[i] = CRGB(ledColor[0], ledColor[1], ledColor[2]);
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




