/*
  The following sketch is using setPower function to set dimming value from 0 to 100%

  Dimmer is connected to following pins:
  D5 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user
  
*/

#include <RBDdimmerSAMD21.h>//

dimmerLampSAMD21 dimmer(4); //initialase port for dimmer: name(PinNumber);

void setup() {
  SerialUSB.begin(9600);
  dimmer.begin(NORMAL_MODE, OFF); //dimmer initialisation: name.begin(MODE, STATE) 
  SerialUSB.println("--- Simple dimmer example ---");
  dimmer.setPower(50); // setPower(0-100%);
  dimmer.setState(ON); // setState(ON/OFF);

}
void loop() {
   SerialUSB.println("1");
  //Serial.print("Dimmer state: ");
  //Serial.println(dimmer.getState());
  delay(1000);
}
