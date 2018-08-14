# LedVisualizer

This project allows you to input an audio file live into an arduino. It should read in the frequency and convert it into a voltage which allows you to see the audio as a sine wave. A good representation of this would be like the sound wave shown in soundcloud. Based on the frequency it should respond with a certain color allowing you to visualize the sound wave on the LED strip. 

Attached are the two circuit diagrams used to create the frequency to voltage converter as well as the code used to control the led strip. Currently the volume values are a bit buggy since amplitude is positive and negative so I will be updating it as it goes on. I am also trying to add in multiple LED strips based on the frequency from bass, mid, or treble.

I also plan on designing a PCB board for the circuit I used to make it cleaner and easier to reproduce.

Parts used:

Arduino Uno: https://www.amazon.com/Devbattles-Arduino-Uno-Microcontroller-ATmega328/dp/B01L21Y916/ref=sr_1_1_sspa?ie=UTF8&qid=1533921893&sr=8-1-spons&keywords=arduino+uno+-+r3&psc=1

LED Strips: https://www.amazon.com/gp/product/B018X04ES2/ref=oh_aui_detailpage_o02_s00?ie=UTF8&psc=1

Notes:
LED strip requires a 5V power supply:
https://www.amazon.com/gp/product/B01LXN7MN3/ref=oh_aui_detailpage_o01_s00?ie=UTF8&psc=1

Circuit requires a 12V power supply:
https://www.amazon.com/gp/product/B01GD4ZQRS/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1

Youtube Video that inspired me:
https://www.youtube.com/watch?v=lU1GVVU9gLU
