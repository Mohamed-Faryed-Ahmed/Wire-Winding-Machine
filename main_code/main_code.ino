#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Stepper.h>
#include <Wire.h>
const byte ROWS = 4;
const byte COLS = 4;
const byte ROW_NUM = 4; 
const byte COLUMN_NUM = 4; 
const int stepsPerRevolution = 200;
int count = 0 ;
int rolls = 0 ;
int NUM = 0 ;
//////////////
int pag1 = 0 ;
int pag2 = 0;
int pag3 = 0 ;
int pag4 = 0 ;
int pag5 = 0 ;
int pag6 = 0 ;
int pag7 = 0 ;
//////////////
int tag1 = 0 ;
int tag2 = 0 ;
int tag3 = 0 ;
int tag4 = 0 ;
int tag5 = 0 ;
int tag6 = 0 ;
int tag7 = 0 ;
//////////////
char temp ;
int n = 0;
int v = 0;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
char keys[ROW_NUM][COLUMN_NUM] = {
   {'1', '2', '3', 'A'},
   {'4', '5', '6', 'B'},
   {'7', '8', '9', 'C'},
   {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Keypad num_keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
const int rs = 11, en = 10, d4 = 12, d5 = 13, d6 = A0, d7 = A1;
LiquidCrystal lcd = LiquidCrystal(rs, en, d4, d5, d6, d7);
Stepper myStepper(stepsPerRevolution, A2, A3, A4, A5);

void setup() {
  lcd.begin(16, 2);
  myStepper.setSpeed(180);
  Serial.begin(9600);
}

void loop() {
  main:
  n = 0;
  v = 0;
  NUM = 0 ;
  count = 0;
  rolls = 0;
  lcd.setCursor(2, 0);
  lcd.print("M.F control");
  
  lcd.setCursor(1, 1);
  lcd.print("#:Free / *:Auto");
  
  char customKey = customKeypad.getKey();
/////////////////////////////////////////////////
  if (customKey =='#')
  {
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("                ");
     while (1)
              {
              lcd.setCursor(0, 0);
              lcd.print("To Start Push:A");
              lcd.setCursor(0, 1);
              lcd.print("Main Menu Push:D");
              char customKey = customKeypad.getKey();
              if (customKey =='A')////
              {
              lcd.setCursor(0, 0);
              lcd.print("                ");
              lcd.setCursor(0, 1);
              lcd.print("                ");
              lcd.setCursor(0, 0);
              lcd.print("To stop Push:B");
              lcd.setCursor(0, 1);
              lcd.print("Main Menu Push:D"); 
              while(1){
              //
              //
              contin:
              char customKey = customKeypad.getKey();
              myStepper.step(stepsPerRevolution);       //**//
              rolls++;
              if (customKey =='B')///
              {
              myStepper.step(0);
              lcd.setCursor(0, 0);
              lcd.print("                ");
              lcd.setCursor(0, 1);
              lcd.print("                ");
              lcd.setCursor(0, 0);
              lcd.print(rolls);
              lcd.setCursor(8, 0);
              lcd.print("rolls");
              delay (6000);
              lcd.setCursor(0, 0);
              lcd.print("                ");
              lcd.setCursor(0, 1);
              lcd.print("                ");
              while (1){
              lcd.setCursor(0, 0);
              lcd.print("To Start Push:A");
              lcd.setCursor(0, 1);
              lcd.print("Main Menu Push:D");
              myStepper.step(0);
              char customKey = customKeypad.getKey(); 
              
              if (customKey =='D')//
              {
              myStepper.step(0); 
              lcd.setCursor(0, 0);
              lcd.print("                ");
              lcd.setCursor(0, 1);
              lcd.print("                ");
              goto main;
              }
              else if (customKey =='A')//
              {
              lcd.setCursor(0, 0);
              lcd.print("                ");
              lcd.setCursor(0, 1);
              lcd.print("                ");
              lcd.setCursor(0, 0);
              lcd.print("To stop Push:B");
              lcd.setCursor(0, 1);
              lcd.print("Main Menu Push:D"); 
              goto contin;
              }
              }
              }
              else if (customKey =='D')///
              {
              myStepper.step(0); 
              lcd.setCursor(0, 0);
              lcd.print("                ");
              lcd.setCursor(0, 1);
              lcd.print("                ");
              goto main;
              }
              //
              //
              }
              } 
              else if (customKey =='D')////
              {
              myStepper.step(0); 
              lcd.setCursor(0, 0);
              lcd.print("                ");
              lcd.setCursor(0, 1);
              lcd.print("                ");
              goto main;
              }
              }
  }
  
  ///////////////////////////////////////////////////////
  else if (customKey =='*')
  {
     value:
     n = 0 ;
     v = 0 ;
     NUM = 0 ;
     count = 0;
     rolls = 0;
     pag1 = 0 ;
     pag2 = 0 ;
     pag3 = 0 ;
     pag4 = 0 ;
     pag5 = 0 ;
     pag6 = 0 ;
     pag7 = 0 ;
     tag1 = 0 ;
     tag2 = 0 ;
     tag3 = 0 ;
     tag4 = 0 ;
     tag5 = 0 ;
     tag6 = 0 ;
     tag7 = 0 ;
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 0);
     lcd.print("enter the value");
     lcd.setCursor(0, 1);
     lcd.print("  then push:C ");
     delay (2000);
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("                ");

     while (1)
     {
       char customKey = customKeypad.getKey();
       if (NUM > 0 & customKey == 'C') ////
       {
       lcd.setCursor(0, 0);
       lcd.print("                ");
       lcd.setCursor(0, 1);
       lcd.print("                ");
       while (1)
       {
       A11:
       lcd.setCursor(0, 0);
       lcd.print(rolls);
       lcd.setCursor(8, 0);
       lcd.print("B:stop");
       lcd.setCursor(0, 1);
       lcd.print("Main Menu Push:D");
       
       myStepper.step(stepsPerRevolution);  //**//
       rolls++;
        if (NUM == rolls){
        while (1){
        lcd.setCursor(0, 0);
        lcd.print(rolls);
        lcd.setCursor(8, 0);
        lcd.print("Finsh  ");
        lcd.setCursor(0, 1);
        lcd.print("Main Menu Push:D");
        myStepper.step(0); 
        char customKey = customKeypad.getKey();
        if (customKey == 'D')
        {
        myStepper.step(0); 
        lcd.setCursor(0, 0);
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print("                ");
        goto main;
        }
                           }
                           }                
       char customKey = customKeypad.getKey();  
       if (customKey == 'B')///
       {
       lcd.setCursor(0, 0);
       lcd.print("                ");
       lcd.setCursor(0, 1);
       lcd.print("                ");
       while (1){
       myStepper.step(0);        
       lcd.setCursor(0, 0);
       lcd.print(rolls);
       lcd.setCursor(8, 0);
       lcd.print("A:RUN  ");
       lcd.setCursor(0, 1);
       lcd.print("Main Menu Push:D");
       char customKey = customKeypad.getKey(); 
       if (customKey == 'A') //
       {
       lcd.setCursor(0, 0);
       lcd.print("                ");
       lcd.setCursor(0, 1);
       lcd.print("                ");
       goto A11;
         
       }
       else if (customKey == 'D')//
       {
       myStepper.step(0); 
       lcd.setCursor(0, 0);
       lcd.print("                ");
       lcd.setCursor(0, 1);
       lcd.print("                ");
       goto main;
       }
       }
       }           
       else if(customKey == 'D')///
       {
       myStepper.step(0); 
       lcd.setCursor(0, 0);
       lcd.print("                ");
       lcd.setCursor(0, 1);
       lcd.print("                ");
       goto main;
       }   
       }
       }
       else if (NUM == 0 & customKey == 'C')////
       {
        goto value;
       }
       else if(customKey =='D') ////
       {
         myStepper.step(0); 
         lcd.setCursor(0, 0);
         lcd.print("                ");
         lcd.setCursor(0, 1);
         lcd.print("                ");
         goto main;
       }
       
       temp = num_keypad.getKey();
       if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4' ||temp == '5' || temp == '6' || temp == '7' || temp == '8' || temp == '9') 
       { v = v + 1 ; }
       
       //////////////////////////////
       numbers ();
       //////////////////////////////
       if (v == 1)
      {
        pag1 = count;
        tag1 = pag1 * 1;
      }
      
      if (v == 2)
      {
        pag2 = count;
        tag1 = pag1 * 10 ;
        tag2 = pag2 * 1  ;
      }
      if (v == 3)
      {
        pag3 = count;
        tag1 = pag1 * 100  ;
        tag2 = pag2 * 10  ;
        tag3 = pag3 * 1  ;
      }
      if (v == 4)
      {
        pag4 = count;
        tag1 = pag1 * 1000 ;
        tag2 = pag2 * 100  ;
        tag3 = pag3 * 10  ;
        tag4 = pag4 * 1  ;
      }
      if (v == 5)
      {
        pag5 = count;
        tag1 = pag1 * 10000 ;
        tag2 = pag2 * 1000 ;
        tag3 = pag3 * 100 ;
        tag4 = pag4 * 10 ;
        tag5 = pag5 * 1 ;
      }
      if (v == 6)
      {
        pag6 = count;
        tag1 = pag1 * 100000 ;
        tag2 = pag2 * 10000  ;
        tag3 = pag3 * 1000  ;
        tag4 = pag4 * 100  ;
        tag5 = pag5 * 10  ;
        tag6 = pag6 * 1  ;
      }
      if (v == 7)
      {
        pag7 = count;
        tag1 = pag1 * 1000000 ;
        tag2 = pag2 * 100000  ;
        tag3 = pag3 * 10000  ;
        tag4 = pag4 * 1000  ;
        tag5 = pag5 * 100  ;
        tag6 = pag6 * 10  ;
        tag7 = pag7 * 1 ;
      }
      
       NUM = tag1 + tag2 + tag3 + tag4 + tag5 + tag6 + tag7 ;
       /////////////////////////////////////
       lcd.setCursor(n - 1 , 0);
       lcd.print(count);
       lcd.setCursor(8, 0);
       lcd.print("rolls");
       lcd.setCursor(0, 1);
       lcd.print(" to Run Push:C"); 
    }
}
}



void numbers(){
      if (temp == '1')
       {
         n = n + 1;
         count = 1;
       }
       
       if (temp == '2')
       {
         n = n + 1;
         count = 2;
       }
       if (temp == '3')
       {
         n = n + 1;
         count = 3;
       }
       
       if (temp == '4')
       {
         n = n + 1;
         count = 4;
       }
       if (temp == '5')
       {
         n = n + 1;
         count = 5;
       }
       
       if (temp == '6')
       {
         n = n + 1;
         count = 6;
       }
       if (temp == '7')
       {
         n = n + 1; 
         count = 7;
       }
       
       if (temp == '8')
       {
         n = n + 1;
         count = 8;
       }
       if (temp == '9')
       {
         n = n + 1;
         count = 9;
       }
       
       if (temp == '0')
       {
         n = n + 1;
         count = 0;
       }
}
