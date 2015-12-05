/*
* Name: TermCom.h
* Author: Michael Kruger
* Brief:
*
* A terminal is a program to send and receive serial data from embedded devices.
* An example of this is the "Serial Monitor" in Arduino, but PuTTy and TeraTerm are also commonly used.
* Some of these terminals support commands so you can, for instance, change the colour of the text, make the computer beep,
* tell the computer to print, change the cursor position and resize the window. You can even ask the computer to give you the mouse position.
*
* These commands are useful for debugging or getting feedback from your project: If something is good print it in green, if something requires 
* your attention maximize the window or beep the computer, and if you are waiting for something display the progress in the progress bar.
*
* ARDUINO'S "SERIAL MONITOR" SUPPORTS VERY LITTLE OF THESE COMMANDS. TO MAKE FULL USE OF THESE COMMANDS, DOWNLOAD AND USE A FULL TERMINAL, EG. TERATERM OR PUTTY.
* 
* This file contains defines and macros for commands:
* - Text/Highlight Colour codes 
* - Text Formatting/Blinking codes
* - Commands to clear screen, backspace, enter, beep computer etc.
* - Commands to control and get the cursor position.
* - Commands to minimize, maximize, resize, move, title and restore the terminal window.
* - Commands to send terminal contents to printer, echo typed input and copy text to clipboard (for pasting).
* - Macros to show progress as a percentage or progress bar.
*
* Copyright 2015 Krugaroo Technology
* More Info: www.krugaroo.com#openSource/TermCom
*
* License: MIT License
*
* Copyright (c) 2015 Michael Kruger, Krugaroo Interactive Technology
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#ifndef H_TERM_COM
#define H_TERM_COM

/**************************************
 * INTERNAL DEFINES, MACROS & ENUMS 
 **************************************/

/* To support the progress bar and percentage printf is needed */
#define TERM_INCLUDE_PRINTF

/**************************************
 * INCLUDE FILES
 **************************************/
 
#ifdef TERM_INCLUDE_PRINTF
#include <stdio.h>
#endif

/**************************************
 * EXTERNAL DEFINES, MACROS & ENUMS 
 **************************************/

/* Remove formatting */ 
#define TERM_RESET   "\x1b[0m"

/* Change the colour of text after to specified colour */
#define TERM_COL_BLACK          "\x1b[30m"
#define TERM_COL_RED            "\x1b[31m"
#define TERM_COL_GREEN          "\x1b[32m"
#define TERM_COL_YELLOW         "\x1b[33m"
#define TERM_COL_BLUE           "\x1b[34m"
#define TERM_COL_MAGNETA        "\x1b[35m"
#define TERM_COL_CYAN           "\x1b[36m"
#define TERM_COL_WHITE          "\x1b[37m"

/* Change the background colour of text after to specified colour */
#define TERM_HIGHLIGHT_BLACK    "\x1b[40m"
#define TERM_HIGHLIGHT_RED      "\x1b[41m"
#define TERM_HIGHLIGHT_GREEN    "\x1b[42m"
#define TERM_HIGHLIGHT_YELLOW   "\x1b[43m"
#define TERM_HIGHLIGHT_BLUE     "\x1b[44m"
#define TERM_HIGHLIGHT_MAGNETA  "\x1b[45m"
#define TERM_HIGHLIGHT_CYAN     "\x1b[46m"
#define TERM_HIGHLIGHT_WHITE    "\x1b[47m"

#define TERM_COL_GOOD    TERM_COL_GREEN
#define TERM_COL_WARN    TERM_COL_YELLOW
#define TERM_COL_BAD		 TERM_COL_RED

/* Call this Macro with the message to colour message to either good, warning or bad */
#define TERM_GOOD(msg) TERM_COL_GOOD msg TERM_RESET
#define TERM_WARN(msg) TERM_COL_WARN msg TERM_RESET
#define TERM_BAD(msg)  TERM_COL_BAD  msg TERM_RESET

/* Make the text following bold, faint, italic or underline*/
#define TERM_BOLD        "\x1b[1m"
#define TERM_FAINT       "\x1b[2m"
#define TERM_ITALIC      "\x1b[3m"
#define TERM_UNDERLINE   "\x1b[4m"

/* Inverts the background and text colour */
/* Writing TERM_INVERT and TERM_UNINVERT  
   alternatively flashes the screen.      */
#define TERM_INVERT      "\x1b[?5h"
#define TERM_UNINVERT    "\x1b[?5l"

/* Useful Commands */
#define TERM_BACKSPACE   "\x08"
#define TERM_ENTER       "\r\n"
#define TERM_RETURN      "\r"
#define TERM_CLEAR       "\x1b[2J \x1b[;H" //clear the entire screen
#define TERM_BEEP        "\a\r\n" //plays a bell sound on computer

/* Commands to control the cursor */
#define TERM_CURSOR_SET(x,y)           "\x1b["x";"y"H" //set cursor position
#define TERM_CURSOR_BLOCK              "\x1b[1 q"      //set cursor style to block
#define TERM_CURSOR_UNDERLINE          "\x1b[3 q"      //set cursor style to underlined
#define TERM_CURSOR_VERTICAL           "\x1b[5 q"      //set cursor style to vertical
#define TERM_CURSOR_COORD_CLICK(on)    (on)? "\x1b[?1000h" : "\x1b[?1000l"   //mouse track on CLICK 

/* Pass the captured string and a TERM_mouseData type to this macro
   to decode the data into the mouseX and mouseY */
#define TERM_INTERPRET_MOUSE_REPORT(string,data)   if(strlen((const char*)string)>=6 &&  string[0]==0x1B  &&  \
                                                      string[1]=='['                 && string[2]=='M'    &&  \
                                                      (string[3]=='#' || string[3]==0x20)                 &&  \
                                                      string[4]>=0x21  &&  string[5]>=0x21)                   \
                                                   {                                                          \
                                                    data.valid = 1;                                           \
                                                    data.mouseX = (string[4]-0x21);                           \
                                                    data.mouseY = (string[5]-0x21);                           \
                                                   }                                                          \
                                                   else                                                       \
                                                   {                                                          \
                                                    data.valid = 0;                                           \
                                                   }                                                          \

/* Commands to control the window of the terminal */
#define TERM_WIN_MINIMIZE       "\x1b[2;;t"
#define TERM_WIN_RESTORE        "\x1b[9;0;t"
#define TERM_WIN_SIZE(x,y,w,h)  "\x1b[3;"x";"y"t\x1b[8;"h";"w"t" //move the window to x,y and size it w and h, columns and lines
#define TERM_WIN_MAXIMIZE       "\x1b[9;1;t"
#define TERM_WIN_TITLE(title)   "\x1b]0;" title "\x1b\\"  //give the window a title

/* Useful utilities */
#define TERM_COPY(data)         "\x1b]52;;" data "\x1b\\" //copies the given data to the clipboard (data is base64)
#define TERM_PRINT              "\x1b[0i"     //prompts the user to print the screen to the printer!
#define TERM_ECHO_ON             "\x1b[12l"   //see everything typed in the terminal
#define TERM_ECHO_OFF            "\x1b[12h"   //stop seeing everything typed in the terminal

/* These macros are only supported if printf is included */
#ifdef TERM_INCLUDE_PRINTF

  /* Shows a percentage that stays on the same spot, call when updating percentage
     Do not write any serial output in between.
     The first parameter is a function to call that writes strings to the serial.
     Requires 10 bytes on stack   */
  #define TERM_PERCENT(func, per)        {                                 \
                                          char lvBuff[10]={0};             \
                                          sprintf(lvBuff,"\r%3d %%",per);  \
                                          func(lvBuff);                    \
                                        }
  
  /* Shows a progress bar that fills up second parameter is total steps.
     Third parameter is amount that is done.
     Do not write any serial output in between.
     The first parameter is a function to call that writes strings to the serial.
     Requires 60 bytes on stack and has max 50 steps   */  
  #define TERM_PROGRESS(func, total, done) {                                                                                          \
                                          int i=0;                                                                                    \
                                          char lvBuff[60]={0};                                                                        \
                                          if(total<=50 && done<=total) {                                                              \
                                          lvBuff[0] = '\r';                                                                           \
                                          for(i=1;i<=done;i++){lvBuff[i]='#';}                                                        \
                                          for(i=1;i<=(total-done);i++){lvBuff[done+i]='-';}                                           \
                                          sprintf((char *)(lvBuff+total+1),"%2d/%2d",done,total);                                     \
                                          func(lvBuff); }                                                                             \
                                        }
#else
  #define TERM_PERCENT(func,per)        
  #define TERM_PROGRESS(func,total,done)       
#endif

/**************************************
 * TYPE DEFINITIONS
 **************************************/
 
typedef struct{
 bool valid;
 int mouseX;
 int mouseY;
} TERM_mouseData;
 
/**************************************
 * INTERFACES
 **************************************/
 
 /* NONE */
 
/**************************************
 * PUBLIC FUNCTION PROTOTYPES
 **************************************/

 /* NONE */
 
/**************************************
 * VARIABLE DECLARATIONS
 **************************************/

 /* NONE */
 
#endif //H_TERM_COM