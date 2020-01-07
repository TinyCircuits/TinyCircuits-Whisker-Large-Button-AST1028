/*
  TinyCircuits Button/Switch Wireling Example Sketch
  This sketch will indicate if the button or switch
  is active or inactive.
  
  Written 30 July 2019
  By Hunter Hykes
  Modified 07 January 2020
  By Hunter Hykes
  
  https://TinyCircuits.com
*/

#include <Wire.h>
#include <Wireling.h>

#if defined (ARDUINO_ARCH_AVR)
#define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#endif

#define WIRELING_PIN A0 // pin corresponds to port (i.e. A0 -> PORT0, A1 -> PORT1, etc.)

#define LED_PIN 10 // For WirelingZero
//#define LED_Pin 13 // For TinyDuino, TinyScreen+, TinyZero, and RobotZero

void setup() {
  SerialMonitorInterface.begin(115200); // start serial communications at 115200 Baud
  
  Wire.begin();     // start I2C communications for Wireling Library
  Wireling.begin(); // needed to reach Wireling ports on RobotZero and Wireling Adapter TinyShield
  
  pinMode(LED_PIN, OUTPUT);     // set the built-in LED pin as an output
  pinMode(WIRELING_PIN, INPUT); // set the pin of the button/switch as an input
  
  delay(500);
}

void loop() {
  // NOTE: switch is active low so '0' is ON
  if(!digitalRead(WIRELING_PIN)) {
    SerialMonitorInterface.println("Active");
    digitalWrite(LED_PIN, HIGH);
    delay(1);
  } else {
    SerialMonitorInterface.println("Inactive");
    digitalWrite(LED_PIN, LOW);
    delay(1);
  }
}
