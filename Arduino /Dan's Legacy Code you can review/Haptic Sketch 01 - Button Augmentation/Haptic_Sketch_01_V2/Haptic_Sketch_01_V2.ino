#include <Wire.h>
#include "Adafruit_DRV2605.h"
extern "C" { 
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}

/* This program drives three haptic motors to demonstrate button augmentation effects

  Details
  =======

  Boards
  =====
  SparkFun Redboard
  TUD/Oculus Haptics Shield (Breadboard Version)

  Connections
  ===========
  I2C
  Connect ARD SCL to TCA SCL Pin
  Connect ARD SDA to TCA SDA Pin
  Connect 

  Power
  Connect ARD VDD to ARD 5V DC Rail
  Connect GROUND to common ground

  History
  =======

  2019/MAY/15  - Release Version (DShor) 0.1
*/

/*
  Variables
  =========
  TCAADDR = i2c Address for DRV
*/
#define TCAADDR 0x70
  uint8_t strongclick = 1;
  uint8_t doubleclick = 10;
  uint8_t tripleclick = 12;
  uint8_t softerclick = 20;
  uint8_t sftdblclick = 32;
  

//Name DRV Drivers

Adafruit_DRV2605 drv0;
Adafruit_DRV2605 drv1;
Adafruit_DRV2605 drv2;
Adafruit_DRV2605 drv3;
/**************************************************************************/
void tcaselect(uint8_t i) 
{ 
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission(); 
  Wire.begin(); 
}
/**************************************************************************/
void tcainit()
{
    while (!Serial);
    
    delay(1000);

    Wire.begin();
    
    Serial.println("\nI2C Scanning Ready!");
    
    for (uint8_t t=0; t<8; t++) {
      tcaselect(t);
      Serial.print("TCA Port #"); Serial.println(t);

      for (uint8_t addr = 0; addr<=127; addr++) {
        if (addr == TCAADDR) continue;
      
        uint8_t data;
        if (! twi_writeTo(addr, &data, 0, 1, 1)) {
           Serial.print("Found DRV2605L: I2C 0x");  Serial.println(addr,HEX);
        }
      }
    }
    Serial.println("I2C Scanning Complete");
    Serial.println();
    
  tcaselect(0);  if(!drv0.begin())  {  Serial.println("Ooops, DRV 00 not detected ... Check your wiring!");  }  
  tcaselect(1);  if(!drv1.begin())  {  Serial.println("Ooops, DRV 01 not detected ... Check your wiring!");  }
  tcaselect(2);  if(!drv2.begin())  {  Serial.println("Ooops, DRV 02 not detected ... Check your wiring!");  }
  tcaselect(3);  if(!drv3.begin())  {  Serial.println("Ooops, DRV 03 not detected detected ... Check your wiring!");  }
         
}

/**************************************************************************/

void setup()
{ 
  Serial.begin(115200);
  Serial.println("Haptic Sketch 01"); 
  Serial.println("by: TU Delft Pi-Touch Group"); 
  Serial.println("Version No: 0.2");
  Serial.println("Board Required: Arduino Uno");
  
  pinMode(12, INPUT_PULLUP); // Enable internal pull-up resistor on pin 5
  digitalWrite(12, HIGH);
  
  tcainit();
  
// Initialize DRVs
  drv0.begin();
  drv0.begin();
  drv1.begin();
  drv2.begin();
  drv3.begin();
  Serial.println("DRV2605L's Initialized");

// Select ERM or LRA
   drv0.selectLibrary(6);  
   drv1.selectLibrary(6);
   drv2.selectLibrary(6);
   drv3.selectLibrary(6); 
        

// I2C trigger by sending 'go' command 
   drv0.setMode(DRV2605_MODE_INTTRIG); 
   drv0.setMode(DRV2605_MODE_INTTRIG); 
   drv1.setMode(DRV2605_MODE_INTTRIG);
   drv2.setMode(DRV2605_MODE_INTTRIG); 
   drv3.setMode(DRV2605_MODE_INTTRIG);

Serial.println("Setup Complete");
Serial.println();
}

/**************************************************************************/


 /**************************************************************************/
void effecttest()
{
  tcaselect(0); //Select desired multiplexer port
//    drv0.useLRA(); 
//    drv0.setWaveform(0, 24); 
//    drv0.setWaveform(1, 0); 
//    drv0.go();
    drv0.useLRA();
    Serial.println("Effect StrongClick");
    drv0.setWaveform(0, strongclick); ; 
    drv0.setWaveform(1, 0); 
    drv0.go();

  tcaselect(1); //Select desired multiplexer port
    delay(1000);
    Serial.println("Effect Triple Click");
    drv1.useLRA();
    drv1.setWaveform(0, tripleclick);  
    drv1.setWaveform(1, 0); 
    drv1.go();

  tcaselect(2); //Select desired multiplexer port
    delay(1000);
    Serial.println("Effect Double Click");
    drv1.useLRA();
    drv1.setWaveform(0, doubleclick); 
    drv1.setWaveform(5, 0); 
    drv1.go();;

    delay(1000);
    Serial.println("Effect Test Complete");
    Serial.println("Check Wiring if No Vibrations Occur");

}

/**************************************************************************/

void loop()
{ 
effecttest();
delay(1000);

}
