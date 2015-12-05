#include <termCom.h>

void setup() {
  // put your setup code here, to run once:
  
  /* This demo shows you how to use all the defines for termCom */
  /* To see this in action open the terminal (TeraTerm or PuTTy) open a serial connection */
  /* to the Arduino Com port with the baudrate at 9600bps. */
  /* Make sure to close the COM port with the Arduino (close Serial Monitor)*/
  /* Since the COM port is used to program the Arduino you need to close TeraTerm/PuTTy before uploading a sketch */
  
  /* Instructions for TeraTerm */
  /* Download here: http://en.sourceforge.jp/projects/ttssh2/releases/ */
  /* Open and go to File->New Connection->Serial (COM port choose the Arduino) */
  /* If needed go to Setup->Serial Port and make sure baud rate is 9600bps */
  /* TeraTerm by default should support most commands */
  /* Enable all the commands: Setup->Additional Settings  */
  /* In Control Sequence make sure everything is checked, window title change request is overwrite and clipboard access is read/write*/
  /* In Visual make sure everything is checked */
  
  /* Instructions for PuTTy */
  /* Download here: http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html */
  /* Open and choose connection type Serial (COM port choose the Arduino) and make baud rate 9600bps */
  /* PuTTy by default should support most commands */
  /* Enable all the commands: On the title bar right click ->Change Settings  */
  /* In Terminal Enable Blinking text and in Remote-Controlled printing make sure that None is not selected.  */
  /* In Terminal->Bell make sure None is not selected, you could also choose your own sound file and prevent the bell from being disabled if overused*/
  /* In Terminal->Features make sure nothing is checked*/
  /* In Window make sure resizing is not forbidden */
  /* In Window->Colurs make sure Allow terminal to specify ANSI colours is checked and indicate bolded text by both.*/
  /* In Visual make sure everything is checked */
  
  /* After opening the serial port reset your Arduino to run through the commands */
  /* Note it is quite likely the terminal/computer does not support all these commands. */
  
  /* Open the serial port with the baudrate. Make sure it matches the baudrate chosen in the terminal*/
  Serial.begin(9600);
  
  /* Note the F() for the Serial.print this tells the compiler to put our strings in flash.*/
  /* Normally Serial.print puts it in RAM, however we only have 2kB of RAM so we need to put it in flash*/
  
  /* The next commands will change the text colour */
  Serial.print(F(TERM_COL_BLACK   "This text is BLACK, but you can't see it" TERM_ENTER));
  Serial.print(F(TERM_COL_RED     "This text is RED" TERM_ENTER));
  Serial.print(F(TERM_COL_GREEN   "This text is GREEN" TERM_ENTER));
  Serial.print(F(TERM_COL_YELLOW  "This text is YELLOW" TERM_ENTER));
  Serial.print(F(TERM_COL_BLUE    "This text is BLUE" TERM_ENTER));
  Serial.print(F(TERM_COL_MAGNETA "This text is MAGNETA" TERM_ENTER));
  Serial.print(F(TERM_COL_CYAN    "This text is CYAN" TERM_ENTER));
  Serial.print(F(TERM_COL_WHITE   "This text is WHITE" TERM_ENTER));
  
  /* The next commands will change the background colour (highlight text) */
  Serial.print(F(TERM_HIGHLIGHT_BLACK   "This background is BLACK" TERM_ENTER));
  Serial.print(F(TERM_HIGHLIGHT_RED     "This background is RED" TERM_ENTER));
  Serial.print(F(TERM_HIGHLIGHT_GREEN   "This background is GREEN" TERM_ENTER));
  Serial.print(F(TERM_HIGHLIGHT_YELLOW  "This background is YELLOW" TERM_ENTER));
  Serial.print(F(TERM_HIGHLIGHT_BLUE    "This background is BLUE" TERM_ENTER));
  Serial.print(F(TERM_HIGHLIGHT_MAGNETA "This background is MAGNETA" TERM_ENTER));
  Serial.print(F(TERM_HIGHLIGHT_CYAN    "This background is CYAN" TERM_ENTER));
  Serial.print(F(TERM_HIGHLIGHT_WHITE   "This background is WHITE, but you can't see the text" TERM_ENTER));
  
  /* The reset is used to remove all formatting */
  Serial.print(F(TERM_RESET "The reset removed the white background and formatting!" TERM_ENTER));
  
  /* The next commands are short macros to display good, warning and error messages */
  Serial.print(F(TERM_GOOD("Yes! It worked!") TERM_ENTER));
  Serial.print(F(TERM_WARN("Okay.. We might have a problem!") TERM_ENTER));
  Serial.print(F(TERM_BAD("Oops! Its all lost! :(") TERM_ENTER));
  
  /* The next commands format the text */
  Serial.print(F(TERM_BOLD "This text will BOLDY go where no text went before!" TERM_RESET TERM_ENTER));
  Serial.print(F(TERM_FAINT "This text is FAINT" TERM_RESET TERM_ENTER));
  Serial.print(F(TERM_ITALIC "Mama Mia! This text is ITALIC" TERM_RESET TERM_ENTER));
  Serial.print(F(TERM_UNDERLINE "This text is underlined" TERM_RESET TERM_ENTER));
  
  /* Backspace can be used like normal*/
  Serial.print(F("Oops I made a miste" TERM_BACKSPACE "ake!" TERM_ENTER));
  
  /* Enter can be used like normal*/
  Serial.print(F(TERM_ENTER TERM_ENTER "This text is 2 lines lower!" TERM_ENTER));
  
  /* Return can be used to start at the beginning of the line*/
  Serial.print(F("You will not see this!" TERM_RETURN "Because this part overrides the beginning!" TERM_ENTER));
  
  /*The return can do some cool things. Lets count down and then clear the screen?*/
  Serial.print(F(TERM_WARN("Warning screen is clearing going to be cleared in:") TERM_ENTER));
  
  int countdown = 5;
  while(countdown)
  {
    Serial.print(F(TERM_RETURN)); //go to beginning of line (do not print TERM_ENTER in between!)
    Serial.print(countdown--); //print the countdown and subtract 1 from it with --
    Serial.print(F(" seconds!"));
    delay(1000);
  }
  
  /* Clear the screen */
  Serial.print(F(TERM_CLEAR));
  
  Serial.print(F("The screen is now clean!" TERM_ENTER));
  
  /* Lets make the computer beep, turn up your volume!*/
  Serial.print(F("Beep..." TERM_BEEP ));
  delay(1000);
  Serial.print(F("Beep..." TERM_BEEP ));
  delay(1000);
  Serial.print(F("Beep..." TERM_BEEP ));
  delay(1000);
  
  /*Another count down before we flash the screen*/
  Serial.print(F(TERM_WARN("Warning the screen is going to flash in:") TERM_ENTER));
  
  countdown = 5;
  while(countdown)
  {
    Serial.print(F(TERM_RETURN)); //go to beginning of line (do not print TERM_ENTER in between!)
    Serial.print(countdown--); //print the countdown and subtract 1 from it with --
    Serial.print(F(" seconds!"));
    delay(1000);
  }
  
  countdown = 5;
  while(countdown)
  {
    countdown--;
    Serial.print(F(TERM_INVERT)); //switch text and background colour
    delay(500);
    Serial.print(F(TERM_UNINVERT)); //switch text and background colour
    delay(500);
  }
  
  Serial.print(F(TERM_ENTER));
  
  /* Does not work on PuTTy, works on TeraTerm.*/
  /*The cursor is now a block*/
  Serial.print(F("Cursor is block" TERM_CURSOR_BLOCK TERM_ENTER));
  delay(2000);
  /*The cursor is now a underline*/
  Serial.print(F("Cursor is underline" TERM_CURSOR_UNDERLINE TERM_ENTER));
  delay(2000);
  /*The cursor is now a vertical line*/
  Serial.print(F("Cursor is vertical" TERM_CURSOR_VERTICAL TERM_ENTER));
  delay(2000);
  
  /*The cursor is now a moved to 20,20*/
  Serial.print(F("Cursor is being moved to 20,20" TERM_CURSOR_SET("20","20") "Cursor is moved!" TERM_ENTER));
  delay(2000);
  
  /* Get the mouse position on clicks */
  Serial.print(F("Cursor position will be reported with every click!"));
  Serial.print(TERM_CURSOR_COORD_CLICK(1));
  
  /* Read from the serial port*/
  countdown = 0;
  while(countdown<2000) //2000 x 10ms = 20 seconds
  {
    /* While there is data available read and put into array*/
    int len=0;
    unsigned char lvReply[11] = {0};
    while(Serial.available()>0)
    {
     lvReply[len] = Serial.read();
     len++;
     if(len>=10){break;} //the response should be shorter than 10 chars
    }
 
    
    /* Fetch the coordinates*/
    if(len>0)
    {
      //do the conversion
      TERM_mouseData lvMouseData={0};
      TERM_INTERPRET_MOUSE_REPORT(lvReply,lvMouseData);
 
      /* If the data is valid print it out.*/
      if(lvMouseData.valid)
      {
        Serial.print(TERM_ENTER "Valid Mouse Data" TERM_ENTER);
        Serial.print("Mouse X: ");
        Serial.print(lvMouseData.mouseX, DEC);
        Serial.print(" Mouse Y: ");
        Serial.print(lvMouseData.mouseY, DEC);
      }
    }
    countdown++;
    delay(10); //wait 10 milliseconds
  }
  
  /* Stop getting the mouse position*/
  Serial.print(F("Cursor position no longer reported"));
  Serial.print(TERM_CURSOR_COORD_CLICK(0));

  /* Clear the screen */
  Serial.print(F(TERM_CLEAR));
  
  /* The next commands control the window */
  /* it could be useful for instance if coding and you project needs to tell you something, it can maximize the window to get your attention */
  
  /* Window will minimize*/
  Serial.print(F("Window will minimize.." TERM_ENTER));
  delay(3000);
  Serial.print(F(TERM_WIN_MINIMIZE));
  Serial.print(F("Minimized. Window will maximize..." TERM_ENTER));
  delay(5000);
  /* Window will maximize*/
  Serial.print(F(TERM_WIN_MAXIMIZE));
  Serial.print(F("Maximized. Window will be restored.." TERM_ENTER));
  delay(3000);
  /* Window will be put back to what it was */
  Serial.print(F(TERM_WIN_RESTORE));
  Serial.print(F("Restored. Window will be moved to 150,150 and resized to 100,80..." TERM_ENTER));
  delay(3000);
  /* Window will be moved to 150px top and left and resized to 100 characters wide and 80 characters high*/
  Serial.print(F(TERM_WIN_SIZE("150","150","100","80")));
  /* Change the window title */
  Serial.print(F("Moved. Window Title is now 'My TermComDemo'" TERM_WIN_TITLE("My TermComDemo") TERM_ENTER));
  delay (3000);
  
  Serial.print(F("Do you want to copy 'TermCom' to your clipboard? (enter Y for yes and N for no)!" TERM_ENTER));
  Serial.print(F(TERM_WARN(TERM_BOLD "Warning this will replace anything you copied!!!") TERM_ENTER));
   
  /* Read from the serial port*/
  countdown = 0;
  int answer = 0;
  while(countdown<2000 && answer!=1 && answer!=2 )
  {
    /* if there is data available read and put into array*/
    if(Serial.available())
    {
     unsigned char reply = Serial.read();
     if(reply=='Y')
     {
       answer=1;
     }
     else if(reply=='N')
     {
       answer = 2;
     }
    }
 
    countdown++;
    delay(10);
  }
  
  /* Lets copy some text to the clipboard */
  if(answer==1)
  {
    /*Note data is in base 64! Encode some here: https://www.base64encode.org/ */
    Serial.print(TERM_COPY("VGVybUNvbQ=="));
    Serial.print(F("You can now paste 'TermCom' anywhere" TERM_ENTER));
    delay(5000);
  }
  else
  {
    Serial.print(F("Not Copied!" TERM_ENTER));
    delay(5000);
  }
  
  /* Lets ask the PC to print our messages on the printer */
  Serial.print(F("I will now ask the PC to print the terminal contents." TERM_PRINT TERM_ENTER));
  delay(100);
  
  countdown = 10;
  while(countdown)
  {
    Serial.print(F(TERM_RETURN)); //go to beginning of line (do not print TERM_ENTER in between!)
    Serial.print(F("Continuing in "));
    Serial.print(countdown--); //print the countdown and subtract 1 from it with --
    Serial.print(F(" seconds!"));
    delay(1000);
  }
  
  Serial.print(F(TERM_ENTER));
  
  /* Lets turn Echo On*/
  Serial.print(F(TERM_ECHO_ON "Echo is on. Any keys you press can now be seen..." TERM_ENTER));
  delay(5000);
  /* Lets turn Echo Off*/
  Serial.print(F(TERM_ECHO_OFF TERM_ENTER "Echo is off. Any keys you press will no longer be seen.."  TERM_ENTER));
  delay(5000);
  
  /* Lets make a percentage count*/
  Serial.print(F("The task is being completed:" TERM_ENTER));
  countdown = 0;
  while(countdown<=100)
  {
    /* shows the value as a percentage*/
    TERM_PERCENT(Serial.print,countdown++);
    delay(100);
  }
  
    
  /* Lets make a progress bar*/
  Serial.print(F(TERM_ENTER "The task is being completed:" TERM_ENTER));
  countdown = 0;
  while(countdown<=50)
  {
    /* shows the value as a progress bar*/
    TERM_PROGRESS(Serial.print,50,countdown);
    delay(100);
    countdown++;
  }

  Serial.print(F(TERM_ENTER TERM_GOOD("The demo is Finished! Reset Arduino to run again!") TERM_ENTER));
 
  /* FINISHED */
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
