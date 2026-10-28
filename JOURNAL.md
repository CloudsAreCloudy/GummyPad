---
title: "GummyPad"
author: "CloudsAreCloudy"
description: "A wireless macropad using an ESP32, Everything is Lapsed."
created_at: "2026-06-30"
---

# 2026-10-28: Fixed the F3D file and STEP file not being in GitHub

**Total time spent: 1h 15m**

The F3D file and the STEP file were too big to be uploaded, so I used the google drive link's I used last time when I did design review, but I was told to upload it to gh still, using gh desktop since that apparently allows for higher uploads but it still wouldn't let me upload it since it was above 100MB, so I created an assembly in Fusion with all the STEP files since that's lighter (which I didn't know at the time of creating this), and exported the F3Z file and STEP file after that. Although the F3Z file was still over by like mere kb, I was able to get the STEP file at a way smaller size, so I just zipped the F3Z file into 2 different zips with the .001 and .002 thing, and hopefully that's good enough cuz I don't think I can get it under 100MB. I also made the demo video and uploaded that too :D

![image.png](https://cdn.hackclub.com/01a18287-913d-7a3b-a605-a805b5b54315/Screenshot%202026-10-28%20181101.png)

# 2026-10-25: Made the project ready for shipping

**Total time spent: 1h 2m**

The F3D file seems to have corrupted and I had to fix the top plate how I did before to reflect how it is right now, and I also redesigned the knob to make it look better. I updated the readme, added firmware, and pushed to the github repo, I accidentally used another account I was logged into with git so that messed up my contributors but I paused and did some digging until I finally fixed it somehow lol. I think everything is ready to be shipped now FINALLY.

![image.png](https://cdn.hackclub.com/01a173a1-c58d-7ba3-a7ef-551b746473df/image.png)

# 2026-10-24: Designed volume knob and sliced keycaps

**Total time spent: 50m**

I designed the volume knob finally, and then downloaded a keycap model and sliced it along with the volume knob, and some 3D printed screws (which deeeeefinitely didn't immediately fail /s) to try and hold the PCB down. it turned out pretty decent, could be better surely but I think that's more so because the rotary encoder is so close to the top and there's not enough distance. I also sanded the top side of the switches cut out since the keycaps wouldn't fit properly, and also the back to let more light through the case.

![IMG_20261025_004559.jpg](https://cdn.hackclub.com/01a16f57-b719-7629-a1bd-8b112b3b09c9/IMG_20261025_004559.jpg)

# 2026-10-24: Battery wire needed to be resoldered

**Total time spent: 38m**

I think the battery wire was accidentally pulled while turning on the Macropad, which made it take really long or just fail booting up, I'm assuming because it wasn't getting enough power. I resoldered the wire and also redid the glue of the switch, and it seemed to work a lot better.

![image.png](https://cdn.hackclub.com/01a16f55-2623-7610-a577-d675aa347ec5/image.png)

# 2026-10-24: Added the ability to change the brightness of the LED's

**Total time spent: 1h 17m**

I added the ability to change the brightness of the LED's when the rotary encoder and switch 2 is pressed, which activates brightness mode, which changes brightness when rotary encoder is rotated. This took a bit longer because I was trying to do it on my own and use as less help as possible, and then I added a small inactive timer where if there's no rotary encoder input for 5 seconds brightness mode is turned off.

![image.png](https://cdn.hackclub.com/01a16f53-6261-7046-b339-4e62d5ee2f69/image.png)

# 2026-10-24: Added battery management

**Total time spent: 26 Minutes**

I added an inactive period, where if there's no input for about 5 minutes the LED and display turns off to save battery, and if its even longer the ESP32 disconnects BLE too and puts it into a deep sleep, which can be woken by pressing the rotary encoder, although the first input is missed to connecting time. It works pretty well in practice.

![image.png](https://cdn.hackclub.com/01a16f50-ee3f-7385-8994-557f29736e2f/image.png)

# 2026-10-15: Made a lot of progress on the firmware side

**Total time spent: 1 Hour 50 Minutes**

I finally got the rotary encoder button to work, then layers got setup, then I made it display what layer it's on on the display, then setup the macropad to use f13-f24 along with shift, ctrl, and alt to give me 4 possible layers, that way I can just make the macros in some software and I don't have to deal with more code. I did lose a bit of my patience and used claude a bit more here, but this was pretty complicated so I don't mind.

![image.png](https://cdn.hackclub.com/01a13fb1-78df-7cda-921d-caecbe0b5498/image.png)

# 2026-10-15: Rotary encoder now works!

**Total time spent: 30 Minutes**

I bent the pins of the EC11 (The KY-040 uses the EC11) so the rotary encoder can sit closer to the PCB, that way there isn't much of the headers in between the rotary encoder and PCB and hence it hopefully won't move too much. I also had to use a wire to connect GND to the GND pin on the EC11, thankfully the trace doesn't go through any of the resistors that are on the KY040 (I think?) so it works :yay: ![image.png](https://cdn.hackclub.com/01a13f44-ee27-7f7e-b8d6-f9fc244e7e71/image.png)

# 2026-10-14: Fixing the rotary encoder

**Total time spent: 1 hour 22 minutes**

The rotary encoder kept shorting, so I decided to completely desolder everything, and then remove any solder stuck in the holes of the rotary encoder which was really really annoying to do. I'm gonna sacrifice a spare diode to get the rotary encoder working, but I think in the process I might have pulled off a trace of the rotary encoder, I'm hoping its saveable.

![IMG_20261015_052140.jpg](https://cdn.hackclub.com/01a13cd4-de17-75be-a87c-991beafc3527/IMG_20261015_052140.jpg)

# 2026-10-13: https://lapse.hackclub.com/timelapse/cXQJ4FPSVn4V

**Total time spent: 31 Minutes**

Finally wrote all the journal's luckily in some of the lapse recordings I found a single screenshot of the journal from back when this project was in Macondo, and I got to use those to recover my old lost journal's :D

![image.png](https://cdn.hackclub.com/01a135ba-0bc7-7722-a8bd-6b1993830376/image.png)

# 2026-10-13: Rewrote journals lost in the famous incident

**Total time spent: 29 Minutes**

I went through my previous lapses to figure out what I was doing and rewrote the journals from memory, didn't get the chance to finish all of them though.

![image.png](https://cdn.hackclub.com/01a13596-ac51-7239-8af4-332ef9b0837c/image.png)

# 2026-09-25: Soldered on the battery, mounted the display

**Total time spent: 45 Minutes**

I couldn't get the display mounted in any of the previous lapses because the cables were too long and wouldnt fold, so I cut them and made them shorter, and I also had to resolder the battery because the wires detached when the case wasn't printed and the battery was hanging. I mounted the switch too at the bottom, and after the lapse I also mounted the inserts along with some 3D printed screws to hold the PCB in place :D

![IMG_20260925_144357.jpg](https://cdn.hackclub.com/01a0d8b5-8114-735a-b16d-804cef554b21/IMG_20260925_144357.jpg)

# 2026-09-25: Modifying the case

**Total time spent: 21 Minutes**

The case printed and I noticed the ESP32 would not make connection because the case wall was too thick and USB C couldn't go deep enough, so I took a soldering iron and made space around it till it started working.

![image.png](https://cdn.hackclub.com/01a0d8b3-645f-737a-924d-5e1166f6df6e/image.png)

# 2026-09-25: Made some CAD modifications to the case

**Total time spent: 22 Minutes**

I printed the case and found a bunch of issues with it, first of all the PCB was interfering with the 3 mounting holes for the top cover, the tp4056 wouldn't fit in its slot, and I realised the top can just be snap fit with some tight tolerances and it doesn't have to be mounted with screws. I made all the modifications and then sent it off to printing :)

![image.png](https://cdn.hackclub.com/01a0d8b1-de3b-7435-8ab3-f7ed865b1adf/image.png)

# 2026-09-23: FIRMWARE ISN'T THAT BAD

**Total time spent: 1 hour 12 minutes**

OK SO APPARENTLY BLE HID DID WORK IN THE LAST JOURNAL, the only issue was that the library's code I copied had it setup in the ROW2COL orientation, so I just reversed it and it worked :D I then proceeded to try and make the rotary encoder work, ran into some issues with it because it worked fine for volume up but not for volume down, then I went back to the original code I took from the adafruit example, and that would give the direction as 1 and -1, so I made the if statement to run only if the direction was equal to 1 or -1, and it worked! last thing I worked on was the display, I found a website to draw pixels and convert it to a bitmap, and used that to get a really cool graphic on the display :D overall very productive journal

![IMG_20260923_212209.jpg](https://cdn.hackclub.com/01a0cef8-6849-7995-8f14-62f724b10bee/IMG_20260923_212209.jpg)

# 2026-09-23: Back to firmware hell

**Total time spent: 1 Hour 24 Minutes**

[Journal affected by db incident, rewritten from memory]

Setting up BLE HID, I think it works, but the library for the keypad doesn't work and I even had to swap libraries a couple of times. I don't know if it's BLE HID that's acting up or the library, we'll have to see in the next lapse

![image.png](https://cdn.hackclub.com/01a0d999-c21f-7aa8-98dd-16376a36fd71/image.png)

# 2026-09-23: Modified the CAD

**Total time spent: 24 Minutes**

Mainly all that was done in this time was repositioning a mounting screw, adding a hole for the battery switch, and adding a cutout for the ESP32C3 Mini USB C port, and sending it to be printed

![image.png](https://cdn.hackclub.com/01a0d99b-486b-7dae-b94c-26c2619d4942/image.png)

# 2026-09-22: Made the switch to Arduino IDE

**Total time spent: 1 Hour 6 Minutes**

[Journal affected by db incident, rewritten from memory]

I made the switch from circuitpython to Arduino IDE, it was a lot more easier especially for the rotary encoder, unlike the digitalio mess in circuitpython it just worked with the rotaryencoder library, along with that the neopixels and display also were setup, on the display I just kept 1 pixel for now just to see if it works.

![image.png](https://cdn.hackclub.com/01a0d99d-94b7-7e98-bcff-6f1df52ef1b8/image.png)

# 2026-09-21: Trying alternative libraries to get the display to work

**Total time spent: 22 Minutes**

[Journal affected by db incident, rewritten from memory]

I tried some older and less memory intensive libraries to set up the display, but no matter what I tried I still ended up with the error 519 bs

![image.png](https://cdn.hackclub.com/01a0d99f-58eb-7978-83b4-628050aec603/image.png)

# 2026-09-21: The display is so annoying

**Total time spent: 2 Hours 13 Minutes**

[Journal affected by db incident, rewritten from memory]

I tried a bunch of different ways to get the display to work, everything from trying different libraries, displaying different things, disabling the LED's to rule out power issues, initiating the display after the macropad makes connection with the PC, but all of them ended with the same result, error 519.

![image.png](https://cdn.hackclub.com/01a0d9a1-b24f-75fe-b5ed-4fc0ee3752a4/image.png)

# 2026-09-18: Soldered the LEDs

**Total time spent: 1 hour 13 Minutes**

[Journal affected by db incident, rewritten from memory]

I soldered all the LED's and the capacitors to the PCB, and copied an example firmware file to test if they worked :D

![image.png](https://cdn.hackclub.com/01a0d9a3-434e-7c3e-8604-755b8744f951/image.png)

# 2026-09-18: Made the neopixel work :D

**Total time spent: 14 minutes**

[Journal affected by db incident, rewritten from memory]

I wrote some basic neopixel led firmware to test if they were working after soldering 2 of them, I haven't added all the pixels, just 2 where 1 is off and the 2nd one is on, since the 1st one acts like a makeshift setup to get the power exactly how the rest of the LEDs want it.

![image.png](https://cdn.hackclub.com/01a0d9a5-e4bc-746c-9c4b-41acc71d7ce5/image.png)

# 2026-09-18: Soldered more components

**Total time spent: 42 Minutes**

[Journal affected by db incident, rewritten from memory]

I soldered the battery to the tp4056 and to a switch, I did realise while soldering to the PCB that I made the holes a bit too small, but it still works just fine. I also had to desolder the top left switch to be able to comfortably solder the resistor and LED for the 1st stabilizing LED, and then I soldered another one just to see if the LED's work or I'm not soldering them right.

![image.png](https://cdn.hackclub.com/01a0d9a8-275b-7b28-9dbb-d4473c194dbf/image.png)

# 2026-09-18: PCB Arrived!

**Total time spent: 1 hour 10 minutes**

[Journal affected by db incident, rewritten from memory]

The PCB arrived and I soldered on all the switches, diodes, and the rotary encoder. I used the leftover legs of the diodes as makeshift headers for the rotary encoder, it seems to be in place fine, I'm just a little concerned about them shorting when moved around.

![image.png](https://cdn.hackclub.com/01a0d9aa-2b5e-73e3-b67d-4a7363d31fce/image.png)

# 2026-09-13: trying to get layers to work

**Total time spent: 19 Minutes**

[Journal affected by db incident, rewritten from memory]

I tried to research and figure out how to get layers to work on the macropad, but couldn't really find any useful resources/documentation. All the good ones seem to require USB HID

![image.png](https://cdn.hackclub.com/01a0d9ac-41c3-79b8-9b03-d81929a3407f/image.png)

# 2026-09-12: Display works (sort of)

**Total time spent: 47 Minutes**

[Journal affected by db incident, rewritten from memory]
I basically followed a library tutorial to try and get "hi lol" displayed on the display while the BLE thing was going on, and it worked but not consistently, and usually it just shows up on the display as intended but never gets to the advertising stage (runs out of memory).

Lapse link: https://lapse.hackclub.com/timelapse/O0hARteZ3VI_
Lapse link 2: https://lapse.hackclub.com/timelapse/szFN9AEfsrcb

![image.png](https://cdn.hackclub.com/01a1359d-33f4-7b50-8abe-d22b1d888367/image.png)

# 2026-09-12: Rotary Encoder now works!

**Total time spent: 1 Hour 40 Minutes**

[Journal affected by db incident, rewritten from memory]
The rotary encoder library usually used (rotaryio) is apparently not supported on a C3, which is why I had to use digitalio to make it work with a lot of help from claude. I then proceeded to make the button work on my own :D

![image.png](https://cdn.hackclub.com/01a1359f-87c4-7027-8b77-c4c16554fc3f/image.png)

# 2026-09-11: Firmware works with a matrix now

**Total time spent: 1 Hour and 5 Minutes**

Got the macropad working with a matrix setup, I didn't have the PCB yet so I just manually wired up 2 pins together to see if it would register a keypress. I used a library I found from adafruit that helped a lot with setting it up, although I did have to setup a translation for "1" to become "KEYCODE.ONE", etc.

![image.png](https://cdn.hackclub.com/01a135a1-bdb4-71b0-b967-20d66395271d/image.png)

# 2026-09-11: Firmware kind of works

**Total time spent: 49 Minutes**

Trying to get the firmware to work with a matrix and register inputs, following libraries and other issues people had on github. ![image.png](https://cdn.hackclub.com/01a135a6-fd3e-7dcc-9058-dba35939c045/image.png)

# 2026-09-09: Trying to make the firmware work

**Total time spent: 2 Hours 27 minutes**

Flashing the ESP32 with circuitpython, trying some basic firmware from libraries, trying to run KMK only to realise that it won't work since the C3 doesn't have USBHID.

![image.png](https://cdn.hackclub.com/01a135a9-a1a9-7b8d-888d-50371959d021/image.png)

# 2026-09-08: Soldering and Desoldering the headers

**Total time spent: 1 Hour 7 Minutes**

So far I got the ESP32, KY040, Display, Battery, and the TP4056, with the rest of the hardware still on the way.

I started off with soldering the headers onto the ESP32, then the same thing with the display, and then soldering the battery onto the tp4056 and making sure it was charging. I also had to desolder the KY-040's headers because they were 90 degrees for some reason eventhough I needed them to be straight, so I had to desolder them and solder on some dupont wire instead, which either ill use to solder onto the esp32 directly, or use to solder onto the pcb. I also connected the KY-040 to the correct ports on the ESP32 to test the rotary encoder.

![image.png](https://cdn.hackclub.com/01a17409-55bc-7988-b8ac-c1690eda35b6/image.png)
