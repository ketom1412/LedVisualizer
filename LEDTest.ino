#include "FastLED.h"

#define NUM_LEDS 300 //Number of LEDS in strip
#define DATA_PIN 6 //Pin to transfer data to led strip for left
#define updateLEDS 5 //distance between each strand of led

CRGB ledsLeft[NUM_LEDS]; //Set up block of memory for storing and
                         //manipulating led data

//Check which color range, mod values
int States[8] = {0, 8, 22, 89, 60, 84, 81, 45}; 
int Incr[8] = {0, 0, 17, 39, 95, 128, 174, 210}; 
//Normal, Red, Orange-Yellow, Yellow-LightBlue, Green-Blue, LightBlue-Lavender, Blue-Pink, Pink-Red

int bright;
int vol;
int col;
int sta;
int light;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
   
  //This tells the library theres a strand of Neopixels at pin 6
  //The strip will use the led array and has NUM_LEDS leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(ledsLeft, NUM_LEDS);
  
  bright = 1;
  vol = 0;
  col = 0;
  sta = 0;
  light = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  vol = (analogRead(A2))/8 + 133;
  col = (analogRead(A3))/4;
  sta = (analogRead(A1))/128;
  light = (analogRead(A5))/4;

  int full = analogRead(A4);
  int freq = analogRead(A0);

  //Update all leds to be #updateLEDS from before
  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--)
  {
    ledsLeft[i] = ledsLeft[i - updateLEDS];
  }

  if((full + 1)/4 > vol)
  {
    bright = 1;
  }
  else
  {
    bright = 0;
  }

  CHSV newColor;
  if(sta == 0)
  {
    newColor = CHSV((freq+col)%255, 255, 255*bright);//255*bright); 
  }
  else
  {
    newColor = CHSV((freq%States[sta])+Incr[sta], 255, 255*bright);
  }
  //CHSV newColor((freq+col)%255, 255, 255*bright);//255*bright); 
  CRGB ledColor;

  //Convert from HSV to RGB color space
  hsv2rgb_rainbow(newColor, ledColor);

  //Set all the colors in the LED strip up to #updateLEDS
  for(int i = 0; i < updateLEDS; i++)
  {
    ledsLeft[i] = CRGB(ledColor[0], ledColor[1], ledColor[2]);
  }

  FastLED.show();

  //delay(1);
}

//Ouput frequeny and volume values
void outputVal(int freq, int full)
{
  Serial.print("Freq: ");
  Serial.println(freq);
  Serial.print("Volume: ");
  Serial.println(full);
}

//Output color values in RGB 
void outputColor(CRGB ledColor)
{
  Serial.print(ledColor[0]);
  Serial.print(' ');
  Serial.print(ledColor[1]);
  Serial.print(' ');
  Serial.println(ledColor[2]);
}

//Output pot values that control color tune, animation tune, and brightness value
void outputPots(int col, int animation, int brightness)
{
  Serial.print("Color Tune: ");
  Serial.println(col);
  Serial.print("Animation: ");
  Serial.println(animation);
  Serial.print("Brightness Level: ");
  Serial.println(brightness);
}
