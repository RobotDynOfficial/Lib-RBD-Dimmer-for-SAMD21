/*
  The following sketch is meant to define the dimming value through the serial port of the controller, 
  using SerialUSB.begin 

  Dimmer is connected to following pins:
  D5 - zero-cross; it's hard-defined because of the use of external interupt 
  dimmerLamp dimmer(4); used to initialize the 4th pin and is defined by the user

   void printSpace() function is used for adding of space after functional data
   void loop()  serial port evaluator, used to register and define values in dimmer.setPower(outVal);
*/

#include <RBDdimmerSAMD21.h>//

dimmerLampSAMD21 dimmer(4); //initialase port for dimmer: name(PinNumber);

int outVal = 0;

void setup() {
  SerialUSB.begin(9600); 
  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 
  SerialUSB.println("Dimmer Program is starting...");
  SerialUSB.println("Set value");
}

void printSpace(int val)
{
  if ((val / 100) == 0) SerialUSB.print(" ");
  if ((val / 10) == 0) SerialUSB.print(" ");
}

void loop() {
  int preVal = outVal;

  if (SerialUSB.available())
  {
    int buf = SerialUSB.parseInt();
    if (buf != 0) outVal = buf;
    delay(200);
  }
  dimmer.setPower(outVal); // setPower(0-100%);

  if (preVal != outVal)
  {
    SerialUSB.print("% lampValue -> ");
    printSpace(dimmer.getPower());
    SerialUSB.print(dimmer.getPower());

  }
  delay(50);

}
