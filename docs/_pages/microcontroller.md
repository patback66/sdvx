---
layout: page
title: The Microcontroller and Wiring
permalink: programming/microcontroller/
subtitle: Choosing a Microcontroller and Wiring the Controller
---

## The Brains

The microcontroller is the brain of the arcade controller. It receives the inputs
and can send outputs such as turning on LEDs and sending signals to the computer.
There are many different microcontrollers that may be used for the controller, but
there are a few requirements that will determine what microcontroller to use.
For this controller, we need:

  - 5V tolerance
  - At least 11 inputs
  - Outputs for each led on each button
  - HID input ability

HID input ability is the key component for this microcontroller. A Human Input
Device (HID) allows interaction with a computer in a predetermined manner. For our
purposes, this means sending inputs to the computer as if the controller were
a keyboard and mouse. The microcontroller found to most easily have this ability
was the [Arduino Leondardo](https://www.arduino.cc/en/Main/ArduinoBoardLeonardo).

The Arduino Leonardo is cheap and easily accessible and has access to the well
supported Arduino library. Arduino provides open source references so you may purchase
a third-party device made to Arduino Leonardo specifications.

## Wiring

You will want to attach your Arduino to a point on the frame to prevent it from
being moved around and disconnecting. This may be done either before or after wiring.

You will need to wire each ground and input to the Arduino Leonardo along with
any power needed. Ports may differ depending on final source code, but the
provided ports will map to the programming provided for this controller.

Crimping a connector to the end of a wire will allow for easy connection and disconnection
for the microswitches on the buttons. Be sure to read the specifications for each
component to ensure you are making the correct connections. An incorrect connection
on an encoder may destroy the encoder. It may also be beneficial to label
inputs where they are connected to the Arduino for ease of diagnosing issues.

(1) Wire all grounds to a common ground on the Arduino. You may daisy-chain the wire
to reduce the amount of wire needed.

(2) Wire the inputs to the provided ports for each button:

|Input |  Input Port | LED Port|
|------|-------------|---------|
|START |  4          | 5       |
|BTN A |  6          | 7       |
|BTN B |  8          | 9       |
|BTN C |  10         | 11      |
|BTN D |  12         | 13      |
|FX L  |  A0         | A1      |
|FX R  |  A2         | A3      |

![Wiring Grounds](../../assets/img/IMG_20160810_191852 (1).jpg)

(3) Wire the power pins for each encoder to V+

(4) Wire the data pins for encoders to ports:

|Encoder | Pin A | Pin B|
|--------|-------|------|
|Left    | 0     | 1    |
|Right   | 2     | 3    |

![Wired Controller](../../assets/img/IMG_20161204_191332.jpg)

(5) Attach the USB cable to the Arduino. Thread it through the cutout and tape in
place to prevent it from being pulled out.

(6) You may temporarily attach the bottom plate at this point. You may still need
access during programming to debug issues.

## Next Steps

The controller is almost complete! It just needs to be programmed and you can
begin using it.

[Next Section](/programming/code)

[comment]: <> (536 Words)
