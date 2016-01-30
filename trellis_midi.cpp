/*************************************************** 
This code uses code provided by the AAdafruit Trellis w/HT16K33
and some code that I added myself. Specifically, I have added
different midi notes which worked for my purposes but may be
changed based on the needs of the user. 

  Designed specifically to work with the Adafruit Trellis 
  ----> https://www.adafruit.com/products/1616
  ----> https://www.adafruit.com/products/1611

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_Trellis.h"

#define MOMENTARY 1
#define LATCHING 0
// set the mode here
#define MODE MOMENTARY 


Adafruit_Trellis matrix0 = Adafruit_Trellis();
//for 1 trellis

// Just one trellis
Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);

// set to however many you're working with here, up to 8
#define NUMTRELLIS 1

#define numKeys (NUMTRELLIS * 16)

// Connect Trellis Vin to 5V and Ground to ground.
// Connect the INT wire to pin #A2 (can change later!)
#define INTPIN A2
// Connect I2C SDA pin to your Arduino SDA line
// Connect I2C SCL pin to your Arduino SCL line
// All Trellises share the SDA, SCL and INT pin! 
// Even 8 tiles use only 3 wires max


void setup() {
  Serial.println("Trellis Demo");
  Serial.begin(115200);

  // INT pin requires a pullup
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  
  // begin() with the addresses of each panel in order
  // I find it easiest if the addresses are in order
  trellis.begin(0x70);  // only one trellis


  // light up all the LEDs in order
  for (uint8_t i=0; i<numKeys; i++) {
    trellis.setLED(i);
    trellis.writeDisplay();    
    delay(100);
  }
  // then turn them off
  for (uint8_t i=0; i<numKeys; i++) {
    trellis.clrLED(i);
    trellis.writeDisplay();    
    delay(50);
  }
}


void loop() {
  delay(30); // 30ms delay is required, dont remove me!
  
  if (MODE == MOMENTARY) {
    // If a button was just pressed or released...
    if (trellis.readSwitches()) {
      // go through every button
      for (uint8_t i=0; i<numKeys; i++) {
  // if it was pressed, turn it on
  if (trellis.justPressed(i)) {
    trellis.setLED(i);//turns on LED

  //Plays different note based on which button pressed:
    if ( i == 0){
      noteOn(144, 37, 127);
    }
    else if (i == 1) {
      noteOn(144, 39, 127);
    }
    else if (i == 2) {
      noteOn(144, 42, 127);
    }
    else if (i == 3) {
      noteOn(144, 44, 127);
    }
    else if (i == 4) {
      noteOn(144, 46, 127);
    }
    else if (i == 5) {
      noteOn(144, 49, 127);
    }
    else if (i == 6) {
      noteOn(144, 51, 127);
    }
    else if (i == 7) {
      noteOn(144, 54, 127);
    }
    else if (i == 8) {
      noteOn(144, 56, 127);
    }
    else if (i == 9) {
      noteOn(144, 58, 127);
    }
    else if (i == 10) {
      noteOn(144, 70, 127);
    }
    else if (i ==11) {
      noteOn(144, 73, 127);
    }
    else if (i == 12) {
      noteOn(144, 75, 127);
    }
    else if (i == 13) {
      noteOn(144, 78, 127);
    }
    else if (i == 14) {
      noteOn(144, 80, 127);
    }
    else if (i == 15) {
      noteOn(144, 82, 127);
    }
    
  

  
  } 
  // if it was released, turn it off
  if (trellis.justReleased(i)) {
    trellis.clrLED(i);
  }
      }
      // tell the trellis to set the LEDs we requested
      trellis.writeDisplay();
    }
  } 
 }

 void noteOn(byte cmd, byte pitch, byte velocity) {
    Serial.write(cmd);
    Serial.write(pitch);
    Serial.write(velocity);
    }

