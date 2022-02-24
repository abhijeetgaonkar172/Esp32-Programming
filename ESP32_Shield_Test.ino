#include <Wire.h>
#include <TM1650.h>


TM1650 d;
int timer = 100;           // The higher the number, the slower the timing.
int ledPins[] = {
  16,17,25,26,27,5,18,19,15,2,4
};       // an array of pin numbers to which LEDs are attached

int pinCount = 11;           // the number of pins (i.e. the length of the array)
int potpin = 33;
int ldrpin = 32;
int thermistorpin = 35;
int pot,ldr,thermistor;

void setup() 
{
  Wire.begin(); //Join the bus as master  

  Serial.begin(9600); //Start serial communication at 9600 for debug statements
  Serial.println("ESP 32 Example Code");
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  d.init();

   d.displayOff();
  d.displayString("____");
  d.setBrightness(TM1650_MIN_BRIGHT);
  d.displayOn();
  delay(100);
  char line[] = "ISA";

  d.displayString(line);
  d.setBrightnessGradually(TM1650_MAX_BRIGHT);
  
   
}

void loop() 
{
 
  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], LOW);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], HIGH);

  }

  // loop from the highest pin to the lowest:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
  pot=analogRead(potpin);
  ldr=analogRead(ldrpin);
  thermistor=analogRead(thermistorpin);
  Serial.print("pot= ");
  Serial.println(pot);
  Serial.print("ldr= ");
  Serial.println(ldr);
  Serial.print("thermistor= ");
  Serial.println(thermistor);
  Serial.println();

}
