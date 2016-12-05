---
layout: page
title: Writing the Code
permalink: programming/code/
subtitle: Writing the Code
---

## Introduction

The Arduino has pull-up resistors connected to each input. This allows the Arduino
to sense when a circuit is open or closed - when a button is pressed or not pressed.
This information can be accessed programmatically and can be used to process information.

Programming the Arduino is based on the C programming language. This is useful as
almost every tool can carry over and syntax remains the same. The one difference
are the functions: setup and loop.

The functions are Arduino built-in and provide the main control structure. When
the Arduino is powered on, it executes everything in the setup function then
proceeds to excecute loop. Loop executes continuously until it is stopped programmatically
or the Arduino loses power. This is where the main processing will take place.

## Inputs and Outputs

Each button or encoder will act as an input. When a button changes states (pressed or not pressed)
the Arduino will process this information and send an output to the computer
as a keyboard or mouse command. It may also turn on and off LEDs based on the
button state.

In the main loop, for each button, the Arduino checks the state of the button.
If the button is pressed, then send a signal to the computer as pressed keyboard key.
It should also turn on the LED for the corresponding button.

When the button is not pressed, the LED should be turned off and the keyboard key
should be released.

## Sample Code

The code provided is a functioning example. It provides the necessary basic functionality
of the controller. It uses the following libraries, which must be installed:

  - Mouse.h
  - Keyboard.h
  - Encoder.h
  - SoftPWM.h

The code may be modified to fit your own needs. There are also nonfunctioning
additional examples contained to control the lights on the controller. These
may be expanded upon to allow animations to be played on the controller.

[Example Source](https://github.com/patback66/sdvx/blob/master/code/sdvx.ino.ino)

```C
// You will need the SoftPWM and Encoder libraries, available from
// the teensy website. Google!

// Edit the fade time to your liking.
// Edit the pins and keys if you use different ones.
// ENCODER PINS MUST BE 0, 1, 2, 3 FOR BEST PERFORMANCE
// Everything else can go wherever.

#include <Mouse.h>
#include <Keyboard.h>
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>
#include <SoftPWM.h>

#define DELAY     1  // Delay per loop in ms
#define FADE_TIME 200

long oldPositionL  = -999;
long oldPositionR  = -999;
long idle = 1000;

typedef struct {
Encoder enc;
char axis;
} encoder_t;

#define ENCODER_COUNT 2

/*encoder_t encoders[ENCODER_COUNT] = {
{Encoder(0, 1), 'x'},
{Encoder(3,2), 'y'}
};*/

Encoder EncL(0, 1);
Encoder EncR(2, 3);

bool enabled = false;

typedef struct {
uint8_t switchPin;
uint8_t lightPin;
char key;
} switch_t;

#define SWITCH_COUNT 7

switch_t switches[SWITCH_COUNT] = {
{4, 5, KEY_RETURN}, // START
{6, 7, 'd'}, // A
{8, 9, 'f'}, // B
{10, 11, 'j'}, // C
{12, 13, 'k'}, // D
{A0, A1, 'c'}, // FX L
{A2, A3, 'm'}, // FX R
};

long switchOnTime[] = {0,0,0,0,0,0,0};

void setup()
{
SoftPWMBegin(SOFTPWM_NORMAL);
for (int i = 0; i < SWITCH_COUNT; i++) {
  pinMode(switches[i].switchPin, INPUT_PULLUP);
  pinMode(switches[i].lightPin, OUTPUT);
  SoftPWMSet(switches[i].lightPin, 0);
  SoftPWMSetFadeTime(switches[i].lightPin, 0, FADE_TIME);
}

Keyboard.begin();
Mouse.begin();
}

void loop() {
//press start to enable after plugging in
if (!enabled && digitalRead(switches[0].switchPin) == LOW)
  enabled = true;

if (enabled) {
  for (int i = 0; i < SWITCH_COUNT; i++) {
    if (digitalRead(switches[i].switchPin) == LOW) {
      Keyboard.press(switches[i].key);
      Serial.write(switches[i].key);
      Serial.write("\n");
      SoftPWMSet(switches[i].lightPin, 255);
      idle = 0;
    } else {
      Keyboard.release(switches[i].key);
      SoftPWMSet(switches[i].lightPin, 0);
      idle++;
    }
  }
  /*for(int i=0; i < ENCODER_COUNT;i++) {
    long encVal = encoders[i].enc.read();
    if(encVal != 0) {
      Serial.write("\n");
      if(encoders[i].axis == 'x'){
        Serial.write("Left enc moving\n");
        Mouse.move(encVal,0,0);
      } else {
        Mouse.move(0,encVal,0);
      }
      if(encVal>=0)
        Serial.write("pos\n");
      else
        Serial.write("neg\n");


      encoders[i].enc.write(0);
    }
    }*/
  long newPositionL = EncL.read();
  long newPositionR = EncR.read();
  Serial.write(newPositionR);
  Serial.write("\n");

  if (newPositionL != oldPositionL) {
    Mouse.move(newPositionL - oldPositionL, 0, 0);
    oldPositionL = newPositionL;
  }

  if (newPositionR != oldPositionR) {
    Mouse.move(0, newPositionR - oldPositionR, 0);
    oldPositionR = newPositionR;
  }
}
if(idle >= 1000) {
  //doIdle();
  //Serial.write("Doing idle\n");
}
delay(DELAY);
}

void doIdle(){
//switches 1-4 ABCD

//switch 0 START
if((idle / 250) == 0)
  SoftPWMSet(switches[0].lightPin, 255);
//switch 5,6 FX
if((idle / 250) == 0) {
  if((idle / 500) == 0) {
    SoftPWMSet(switches[5].lightPin, 255);
    SoftPWMSet(switches[6].lightPin, 0);
  } else {
    SoftPWMSet(switches[5].lightPin, 0);
    SoftPWMSet(switches[6].lightPin, 255);
  }
}
}
```
## Programming the Arduino

To program the Arduino:

(1) Open the Arduino IDE

(2) Select your Arduino

(3) Open the file for the source code.

(4) Compile and upload

## Using Your controller

Each button is mapped to a different keyboard input. The knobs are mapped to
mouse X and Y movement. This allows the controller to be used on virtually any
computer without having to find drivers.

Press the start button to allow the controller to begin sending information to
your computer. This acts as a failsafe should wiring or programming be incorrect.
If the Arduino were to send key presses immediately, it could potentially send
inputs continuously, blocking the ability to work on your computer and reprogram
the Arduino.

## Troubleshooting

### Key presses aren't received

  Double check all wiring and inputs in the code.

### It caught on fire

  Don't cross bare wires.

## End

At this point, the controller should be functionally complete. For some, this might
be all that's needed. For others, the controller working might mean more features
are still needed. My future feature list includes:

  - Art in between the top and middle plates to provide a nice look
  - Dampeners on the encoders to reduce spin speed
  - LED strip, animations

Make the controller your own, and enjoy your work. Don't sweat the small mistakes.
Don't forget, the process was fun too!

Thanks for reading!

[comment]: <> (958 Words)
