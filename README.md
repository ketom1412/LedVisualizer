# LedVisualizer

This project allows you to input an audio file live into an arduino. It should read in the frequency and convert it into a voltage which allows you to see the audio as a sine wave. A good representation of this would be like the sound wave shown in soundcloud. Based on the frequency it should respond with a certain color allowing you to visualize the sound wave on the LED strip. 

Attached are the three resources for circuit diagrams used to create the frequency to voltage converter as well as the code used to control the led strip. I've gotten the circuit to read in volume from 0-1023 which is what the analog pins read to and used these values to animate the light strip from light to no light. I have also attached a video of a demo of the working project!

I also plan on designing a PCB board for the circuit I used to make it cleaner and easier to reproduce.

Note:
I won't be adding in the full circuit diagram since I believe if you want to reproduce this project its important to understand how this circuit works. This involves looking at the resources provided and testing it out.

The numbers I added to the volume check and the frequency value is for tuning purposes, since I want certain songs to be a certain color when they're played or I want the animation to have less light. For the volume, the higher the number, the less light display you will have, and for the freq, just search up the HSV color space and add on to it since it goes in a 360 circle. You can play around with these values for however you see fit.

Parts used:

Arduino Uno: https://www.amazon.com/Devbattles-Arduino-Uno-Microcontroller-ATmega328/dp/B01L21Y916/ref=sr_1_1_sspa?ie=UTF8&qid=1533921893&sr=8-1-spons&keywords=arduino+uno+-+r3&psc=1

LED Strips: https://www.amazon.com/gp/product/B018X04ES2/ref=oh_aui_detailpage_o02_s00?ie=UTF8&psc=1

LED strip requires a 5V power supply:
https://www.amazon.com/gp/product/B01LXN7MN3/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1

Circuit requires a 12V power supply:
https://www.amazon.com/gp/product/B01GD4ZQRS/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1

Circuit requires 12V power supply
http://mathscinotes.com/2014/03/a-simple-frequency-to-voltage-converter/

Circuit for volume check:
https://www.instructables.com/id/Arduino-Audio-Input/

Youtube Video that inspired me:
https://www.youtube.com/watch?v=lU1GVVU9gLU


Other Resources:

http://www.szynalski.com/tone-generator/

https://www.teachmeaudio.com/mixing/techniques/audio-spectrum/
