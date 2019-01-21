/*
  The following sketch is meant to to define dimming value through potentiometer,
  The potentiometer values are changing in range from 0 to 1023
  potentiometer values are converted through the map function to values from 0 to 100% and saved in dimmer.setPower(outVal);
  Serial.begin is used to display dimming values 

  Dimmer is connected to following pins:
  D5 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user
  
  void loop()  обработчик потенциометра, вывод информации на серийный порт, задавание значения.
*/
#include <RBDdimmerSAMD21.h>

dimmerLampSAMD21 dimmer(4); //initialase port for dimmer: name(PinNumber);

int outVal = 0;

void setup() {
  SerialUSB.begin(9600);
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
}

void loop() 
{
  outVal = map(analogRead(0), 1, 1024, 100, 0); // analogRead(analog_pin), min_analog, max_analog, 100%, 0%);
  SerialUSB.println(outVal); 
  dimmer.setPower(outVal); // name.setPower(0%-100%)
}
