//************************************************************************
// Large Button Whisker Example
//
// Uses digitalRead to detect when the large button is pressed and report
// to the serial monitor.
//
// Written by Zachary Lee 7/30/19
//************************************************************************

#include <Wire.h>               //I2C Library 
//#include "TinyBoards.h"       //TinyBoards Library - contains default device addresses and useful functions

const int powerPin = 4;         //IO Pin for controlling power to the Mux TinyShield

//const int buttonPin =

float buttonPin = A1;

void setup() {
  Wire.begin();                 //Begin I2C Communication
  SerialUSB.begin(9600);         //Begin Serial Communication and set Baud Rate

  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, HIGH);

  pinMode(buttonPin, INPUT);

  selectPort(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  selectPort(1);
  static int buttonState = 0;
  int prevButtonState = buttonState;
  buttonState = digitalRead(buttonPin);   //Poll Sensor Data

  if (prevButtonState != buttonState) // no need to alert the user if button state remains unchanged
  {
    if (buttonState == LOW)
    {
      SerialUSB.println("Button pressed!");
    }
    else
    {
      // button not currently being pressed
    }
  }
}

void selectPort(int port) {
  Wire.beginTransmission(0x70);   //I2C Multiplexer Address
  Wire.write(0x04 + port);        //Mux Port Select (0 to 3)
  Wire.endTransmission();         //End Communication with Mux
}
