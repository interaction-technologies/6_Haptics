#include <Wire.h>
#include "Adafruit_DRV2605.h"
#define TCAADDR 0x70

// **********************************//
// ** Example code: *****************//
// ** Drives 4 vibration motors *****//
// ** by using the I2C multiplexer.**//
// ** Uncomment one of the effects **//
// ** in the loop to run it. ********//
// **********************************//

// Name drivers
 Adafruit_DRV2605 drv0;  
 Adafruit_DRV2605 drv1;
 Adafruit_DRV2605 drv2;  
 Adafruit_DRV2605 drv3;
 
// Select Ports on Multiplexer
void tcaselect(uint8_t i) 
{ if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission(); 
  Wire.begin(); 
}

void setup()
{ Serial.begin(9600);
  Serial.println("DRV test"); 
  Serial.println("");
  drv0.begin();
  drv1.begin();
  drv2.begin();
  drv3.begin();

// Choose Library 1-5 for ERM and 6 for LRA    
   drv0.selectLibrary(6);  
   drv1.selectLibrary(6);
   drv2.selectLibrary(6);  
   drv3.selectLibrary(6);


// I2C trigger by sending 'go' command 
   drv0.setMode(DRV2605_MODE_INTTRIG); 
   drv1.setMode(DRV2605_MODE_INTTRIG);
   drv2.setMode(DRV2605_MODE_INTTRIG); 
   drv3.setMode(DRV2605_MODE_INTTRIG);
  
} 

// Set effects
  uint8_t effect0 = 88;
  uint8_t effect1 = 123;
 
void loop()
{ 
  while(effect0 <= effect1){
    
// *************************************************** //
// ** Play multiple waveforms on motor goes up to 8 ** //
// *************************************************** //

//  tcaselect(4); //Select desired multiplexer port
//  drv1.useLRA(); 
//  drv1.setWaveform(0, 24); 
//  drv1.setWaveform(1, 24);
//  drv1.setWaveform(2, 24);
//  drv1.setWaveform(3, 24); 
//  drv1.setWaveform(4, 24); 
//  drv1.setWaveform(5, 0); 
//  drv1.go();
//  delay(1000);

// ***************************************** //
// ** Uncomment the delays to ************** //
// ** Play brushing effect accros fingers ** //
// ***************************************** //

//  Serial.print("Effect port5: #"); Serial.println(effect0); 
//  tcaselect(5);                   // Select I2C multiplexer port
//  drv0.useLRA();                  // Uncomment to switch from default ERM to LRA
//  drv0.setWaveform(0, effect0);   // play effect 
//  drv0.setWaveform(1, 0);         // end waveform
//  drv0.go();                      // play the effect! 
//
//  delay(100);
//  
//  tcaselect(4);
//  drv1.useLRA(); 
//  drv1.setWaveform(0, effect0);   
//  drv1.setWaveform(1, 0); 
//  drv1.go();   
//
//  delay(100);
//    
//  tcaselect(3);
//  drv2.useLRA(); 
//  drv2.setWaveform(0, effect0);  
//  drv2.setWaveform(1, 0);   
//  drv2.go(); 
// 
//  delay(100);
//  
//  tcaselect(2);
//  drv3.useLRA(); 
//  drv3.setWaveform(0, effect0);  
//  drv3.setWaveform(1, 0);   
//  drv3.go(); 
//
//// wait a bit
//  delay(2000);

// ******************************** //
// Increase effect number by one ** //
// ******************************** //

// effect0++;

}
