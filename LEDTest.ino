//For HSV color, it will do a full 360 in a certain amount of time
//to represet the hue factor, saturation is based on frequency
//and brightness is controlled by volume
#include "FastLED.h"

#define NUM_LEDS 300 //Number of LEDS in strip
#define DATA_PIN 6 //Pin to transfer data to led strip
#define updateLEDS 8 //distance between each strand of led

CRGB ledsTreb[NUM_LEDS]; //129 - 171 //Set up block of memory for storing and
CRGB ledsMid[NUM_LEDS];  //171 - 213 //manipulating led data
CRGB ledsBass[NUM_LEDS]; //213 - 255

int bright;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A4, INPUT);
   
  //This tells the library theres a strand of Neopixels at pin 6
  //The strip will use the led array and has NUM_LEDS leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(ledsTreb, NUM_LEDS);
  bright = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
    
  //leds[0] = CRGB::White; FastLED.show(); delay(30);
  //leds[0] = CRGB::Black; FastLED.show(); delay(30);
  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--)
  {
    ledsTreb[i] = ledsTreb[i - updateLEDS];
  }

  //Serial.println(analogRead(A4));
  int full = analogRead(A4);
  //Serial.println(full);

  if(full > 1000)
  {
//    if(bright == 1)
//    {
//      bright = bright - 0.2; //each LED should be darker then last
//    } 
    bright = 1;
  }
  else
  {
    bright = 0;
  }

  int freq = analogRead(A0);
  Serial.println(freq);
  
  //freq = freq + 122 //This part is to tune to certain freq color

  CHSV newColor((freq+97)%255, 255, 255*bright);
  CRGB ledColor;

  hsv2rgb_rainbow(newColor, ledColor);
  //Serial.println(ledColor[0]);
  Serial.print(ledColor[0]);
  Serial.print(' ');
  Serial.print(ledColor[1]);
  Serial.print(' ');
  Serial.println(ledColor[2]);
  for(int i = 0; i < updateLEDS; i++)
  {
    ledsTreb[i] = CRGB(ledColor[0], ledColor[1], ledColor[2]);
  }

  FastLED.show();

  //if(bright == 0)
  //{
    //bright = 1;
  //}
  
  delay(1);
}








