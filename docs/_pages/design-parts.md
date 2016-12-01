---
layout: page
title: The Parts
permalink: design/design-parts/
subtitle: Find the parts you need.
---
## Getting the Parts

Once you have a mostly complete design, you can begin purchasing parts. Purchasing
early will be important, especially if parts are being shipped from China. The
design also can not be finished until you can take accurate measurements of your actual
parts.

### Choosing Parts

For a budget build, the cheapest parts available will have to suffice. Sites
such as eBay, Aliexpress, and Amazon will provide what you need. Chinese buttons
and other components will be acceptable, but for the true arcade quality you will
want to purchase identical, high-quality parts.

### The Buttons

picture here

For the Sound Voltex controller, you will need a total of 7 buttons. Other controllers
will use different sizes, styles, and numbers of buttons. The four large buttons for
Sound Voltex are 60mm square buttons. The next two smaller FX buttons are rectangular
50 x 33 mm buttons. The final button, the start button, is a 33 mm square button.

Sanwa manufactures the actual arcade buttons, which can be purchased through a site
such as Rakuten. These buttons have the best quality and longest life span along with
the true arcade feel. Unfortunately these buttons can also become quite expensive. Instead,
the example controller was built using cheaper Chinese clones purchased from aliexpress.
For the large buttons, I purchased a set of [clones](http://www.aliexpress.com/item/high-quality-4pcs-lot-Square-60-60mm-Lighted-Buttons-Illuminated-Push-Button-with-Micro-switch-for/32611880107.html?spm=2114.30010308.3.86.ifPWcm&ws_ab_test=searchweb201556_8,searchweb201602_2_10057_10056_10055_10049_10017_405_404_10059_407_10058_10040,searchweb201603_2&btsid=194be6a8-445e-43ae-bf17-e058790d6af4) from Aliexpress.
From the same site, I purchased a pack of [buttons](http://www.aliexpress.com/item/9x-Arcade-Beatmania-IIDX-DIY-Kit-Parts-LED-Light-Illuminated-Rectangular-Buttons/32654141915.html?spm=2114.30010308.3.2.MPUfbB&ws_ab_test=searchweb201556_8,searchweb201602_2_10017_405_404_301_407_406_10040,searchweb201603_2&btsid=49678139-a03d-4cc6-b940-93b38f89f956) typically used for Beatmania
that match the dimensions of the Sound Voltex buttons.

Each of the buttons holds a microswitch, the signaling part of the button. The
microswitch will complete an electrical circuit when pressed, allowing the microcontroller
to sense a button press or release. The buttons also come with holders for LEDs
that can be wired to light up when the button is depressed.

### The Encoders

picure here

Encoders are an important part of the Sound Voltex controller but may not be applicable
for other controllers. Rotary encoders spin and send signals to indicate how much
a shaft has turned. Sound Voltex has dampeners on the encoders to reduce the speed
at which knobs can be spun, but this contoller was built without dampeners in order
to simplify the process.

When looking at encoders, the accuracy is specified with a number, such as 48 PR.
This means that the encoder will recognize 48 points in a full rotation of a shaft.
Other controllers built with low accuracy encoders have had issues due to the jumpiness
and low precision brought on by the encoders. Here, a 600 PR [rotary encoder](http://www.aliexpress.com/item/high-quality-4pcs-lot-Square-60-60mm-Lighted-Buttons-Illuminated-Push-Button-with-Micro-switch-for/32611880107.html?spm=2114.30010308.3.86.ifPWcm&ws_ab_test=searchweb201556_8,searchweb201602_2_10057_10056_10055_10049_10017_405_404_10059_407_10058_10040,searchweb201603_2&btsid=194be6a8-445e-43ae-bf17-e058790d6af4) was used,
but that has also had issues with oversensitivity. Given these results, a 360 PR
rotary controller is recommended.

The encoder will also need a knob to attach to the shaft. Aluminum volume knobs
tend to give a nice feel and typically are manufactured to size that would fit
most shafts on rotary encoders. I purchased a set of [knobs](http://www.ebay.com/itm/2pc-30mmDIAx22-Aluminum-STEREO-VOLUME-CONTROL-KNOB-/291152811579?hash=item43ca0f563b) from eBay, though
there are many other replacements for it.

Each encoder has a different pinout or wiring pattern. Be extra careful when checking
diagrams and your parts. Wiring an encoder incorrectly may damage or entirely destroy
the encoder.

### The Microcontroller Board

Each controller will need a control board to read the inputs from the buttons.
The inputs will be processed and sent to the computer where the game is running.
In this case, an Arduino Leonardo was preferred due to its ability to function
as a Human Input Device (HID) such as a keyboard and mouse. More information on
microcontroller choice is available in the [Programming section.]()

### Extras

Depending on how much you want to accomplish with your controllers, there may
be additional parts you may need. I chose a strip of addressable LEDs in order
to allow for additional lighting and animations. Some controllers may need special
components such as knobs, speakers, joysticks, etc. These should be easy enough
to find through the same avenues as the other arcade controller parts although
additional research may be necessary.

### Bill of Materials

Depending on where you shop and what parts you may already have on hand, a
custom controller can be very budget friendly. Provided is a the bill of materials
used for this controller. Not all parts may be exactly what you need. They can
be interchanged depending on the needs of each controller, but should be able to
serve as a baseline for beginning to look at parts.

<iframe src="https://docs.google.com/spreadsheets/d/e/2PACX-1vQvnWBINLMrBfX94r46zBTR1-ts8DfYVbqX9WgPWMxWYQKORk-0Gt12GwH3pfWc_rtqO9r4PYzPw9JT/pubhtml?gid=0&amp;single=true&amp;widget=true&amp;headers=false"></iframe>

## Next Steps

Once you have received your parts, it's time to finalize the design and get manufacturing!
Inspect your parts and ensure that they function before beginning anything else.
Broken parts will make later steps more difficult should issues arise. In addition,
getting familiar with how each part will mount to the plates will be useful. Take
accurate measurements of the dimensions for each mounting point and you'll be
ready to finish your design.

[Next Section](../../design/design-final)
