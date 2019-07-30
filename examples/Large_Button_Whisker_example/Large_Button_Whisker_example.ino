//************************************************************************
// Large Button Whisker Example
//
// Uses digitalRead to detect when the large button is pressed and report
// to the serial monitor.
//
// Written by Zachary Lee 7/30/19
//************************************************************************

#define buttonPin A0 // corresponds to Port 0. Similarly, Port 1 = A1, Port 2 = A2, Port 3 = A3.

void setup() {
  Wire.begin();                 //Begin I2C Communication
  SerialUSB.begin(9600);         //Begin Serial Communication and set Baud Rate

  pinMode(buttonPin, INPUT);
}

void loop() {
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
