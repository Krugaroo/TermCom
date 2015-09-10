# TermCom

## Description:
A simple project containing a list and macros of terminal commands, such as colouring and control characters.

A terminal is a program to send and receive serial data from embedded devices.
An example of this is the "Serial Monitor" in Arduino, but PuTTy and TeraTerm are also commonly used.
Some of these terminals support commands so you can, for instance, change the colour of the text, make the computer beep,
tell the computer to print, change the cursor position and resize the window. You can even ask the computer to give you the mouse position.

These commands are useful for debugging or getting feedback from your project: If something is good print it in green, if something requires your attention maximize the window or beep the computer, and if you are waiting for something display the progress in the progress bar.

ARDUINO'S "SERIAL MONITOR" SUPPORTS VERY LITTLE OF THESE COMMANDS. TO MAKE FULL USE OF THESE COMMANDS, DOWNLOAD AND USE A FULL TERMINAL, EG. TERATERM OR PUTTY.
 
This file contains defines and macros for commands:
- Text/Highlight Colour codes 
- Text Formatting/Blinking codes
- Commands to clear screen, backspace, enter, beep computer etc.
- Commands to control and get the cursor position.
- Commands to minimize, maximize, resize, move, title and restore the terminal window.
- Commands to send terminal contents to printer, echo typed input and copy text to clipboard (for pasting).
- Macros to show progress as a percentage or progress bar.
 
## How to use
The Arduino folder contains a library that can be added to the Arduino IDE. It contains a demo that demonstrates all the commands.

For all other platforms the Generic folder can be used. THe code is written in C and there is no hardware/platform dependence, therefore it should work out of the box.

## Copyright & License

Copyright 2015 Krugaroo 

License: MIT License

Copyright (c) 2015 Michael Kruger, Krugaroo Interactive Technology

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
