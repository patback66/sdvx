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

