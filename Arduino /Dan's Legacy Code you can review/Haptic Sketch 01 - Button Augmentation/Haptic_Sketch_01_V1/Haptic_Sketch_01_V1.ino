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
Adafruit_DRVL2605 drv0 = Adafruit_DRVL2605(0);
Adafruit_DRVL2605 drv1 = Adafruit_DRVL2605(1);
Adafruit_DRVL2605 drv2 = Adafruit_DRVL2605(2);
//Adafruit_DRVL2605 drv3 = Adafruit_DRVL2605(3);
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
//  tcaselect(3);  if(!drv3.begin())  {  Serial.println("Ooops, DRV 03 not detected detected ... Check your wiring!");  }
         
}

/**************************************************************************/

void setup()
{ 
  Serial.begin(115200);
  Serial.println("Haptic Sketch 01"); 
  Serial.println("by: TU Delft Pi-Touch Group"); 
  Serial.println("Version No: 0.1");
  Serial.println("Board Required: Arduino Uno");

  tcainit();
  
// Initialize DRVs
    drv.begin();
//  drv0.begin();
//  drv1.begin();
//  drv2.begin();
  Serial.println("DRV2605L's Initialized");
  
    
//  drv3.begin();
//    Serial.println("Initialized DRV2605L");

// Select ERM or LRA
//        drv0.selectLibrary(6);  
//        drv1.selectLibrary(6);
//        drv2.selectLibrary(6); 
//  Serial.println("Press 1 for ERM, Press 2 for LRA");
//  while (true)
//  {
//    if (Serial.available() > 0) 
//    {            // remain here until told to break
//      if (Serial.read() == '1')
//      {               
//        drv0.selectLibrary(2);  
//        drv1.selectLibrary(2);
//        drv2.selectLibrary(2);  
////        drv3.selectLibrary(2);
//        Serial.println("ERM Selected");
//      }
//      else
//      {
//        Serial.println("LRA Selected"); 
//        drv0.selectLibrary(6);  
//        drv1.selectLibrary(6);
//        drv2.selectLibrary(6);  
////        drv3.selectLibrary(6); 
//
//
//      }
//    }
//  }
// I2C trigger by sending 'go' command 
    drv.setMode(DRV2605_MODE_INTTRIG); 
//   drv0.setMode(DRV2605_MODE_INTTRIG); 
//   drv1.setMode(DRV2605_MODE_INTTRIG);
//   drv2.setMode(DRV2605_MODE_INTTRIG); 
////   drv3.setMode(DRV2605_MODE_INTTRIG);

Serial.println("Setup Complete");
Serial.println();
}

/**************************************************************************/


 /**************************************************************************/
void effecttest()
{
  tcaselect(0); //Select desired multiplexer port
    drv.useLRA(); 
    drv.setWaveform(0, 24); 
    drv.setWaveform(1, 0); 
    drv.go();
//    drv0.setWaveform(0, strongclick); 
//    drv0.setWaveform(1, strongclick);
//    drv0.setWaveform(2, strongclick);
//    drv0.setWaveform(3, strongclick); 
//    drv0.setWaveform(4, strongclick); 
//    drv0.setWaveform(5, 0); 
//    drv0.useLRA();
//    drv0.go();

  tcaselect(1); //Select desired multiplexer port
//    drv1.useLRA(); 
//    drv1.setWaveform(0, 24); 
////  drv1.setWaveform(1, 24);
////  drv1.setWaveform(2, 24);
////  drv1.setWaveform(3, 24); 
////  drv1.setWaveform(4, 24); 
//    drv1.setWaveform(1, 0); 
//    drv1.go();

  tcaselect(2); //Select desired multiplexer port
//    drv2.setWaveform(0, 1); 
//    drv2.setWaveform(1, 1);
//    drv2.setWaveform(2, 1);
//    drv2.setWaveform(3, 1); 
//    drv2.setWaveform(4, 1); 
//    drv2.setWaveform(5, 0); 
//    drv2.useLRA();
//    drv2.go();

    delay(5000);
    
    Serial.println("Effect Test Complete");
    Serial.println("Check Wiring if No Vibrations Occur");

}

/**************************************************************************/

void loop()
{ 
effecttest();
delay(1000);

}
