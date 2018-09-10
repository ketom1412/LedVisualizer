# LedVisualizer

This project allows you to input an audio file live into an arduino. It should read in the frequency and convert it into a voltage which allows you to see the audio as a sine wave. A good representation of this would be like the sound wave shown in soundcloud. Based on the frequency it should respond with a certain color allowing you to visualize the sound wave on the LED strip. 

Attached are the resources for circuit diagrams used to create the frequency to voltage converter as well as the code used to control the led strip. I've gotten the circuit to read in volume from 0-1023 which is what the analog pins read to and used these values to animate the light strip from light to no light. 

Update to base project:
I have added in four 1k potentiometers to control the animation, color tune, color spectrum, and brightness of the lights. The animation means that how often am I letting the LEDS light up, colot tune means you can alter the colors live, and brightness to control how bright the LEDS are. The color spectrum is in the comments, it essentially limits the lights to certain values based on the position of the pot. I map them all to 0-255 so I can use them in the built in functions. I am also adding in a switch so that I can use the low pass filter and non low pass filter volume control. I do this since I have noticed that some songs have a better light show from the bass frequency controling the animation then when I use the full frequency. 

I have also attached a video of a demo of the working project!

I have created a PCB for my project using this site: https://easyeda.com/
It's pretty straight forward and its relatively cheap to print out.

Next Steps:
I will be making a mobile app that will allow you to control the settings of the strip.

Note:
I won't be adding in the full circuit diagram since I believe if you want to reproduce this project its important to understand how this circuit works. This involves looking at the resources provided, researching, and testing it out.

Parts used:

Arduino Uno: https://www.amazon.com/Devbattles-Arduino-Uno-Microcontroller-ATmega328/dp/B01L21Y916/ref=sr_1_1_sspa?ie=UTF8&qid=1533921893&sr=8-1-spons&keywords=arduino+uno+-+r3&psc=1

LED Strips: https://www.amazon.com/gp/product/B018X04ES2/ref=oh_aui_detailpage_o02_s00?ie=UTF8&psc=1

LED strip requires a 5V power supply:
https://www.amazon.com/gp/product/B01LXN7MN3/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1

Circuit requires a 12V power supply:
https://www.amazon.com/gp/product/B01GD4ZQRS/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1

Circuit requires 12V power supply:
http://mathscinotes.com/2014/03/a-simple-frequency-to-voltage-converter/


Other Resources:

http://www.szynalski.com/tone-generator/

https://www.teachmeaudio.com/mixing/techniques/audio-spectrum/
