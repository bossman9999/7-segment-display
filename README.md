# 7-Segment Display Counter

A button-controlled counter using an LSHD-5503 7-segment display and Arduino Mega.

## How it works
A pushbutton is connected to the Arduino Mega. Each time the button is pressed,
the counter increments by 1 and displays the new digit on the 7-segment display.
Once it reaches 9 it resets back to 0 and keeps counting.

## Components
- Arduino Mega
- LSHD-5503 7-segment display
- 7x 1kΩ resistors
- 1x pushbutton

## Wiring
- Segments A-G → Mega pins 7,6,4,3,2,8,9
- Button → Mega pin 25
- CC pins → GND
