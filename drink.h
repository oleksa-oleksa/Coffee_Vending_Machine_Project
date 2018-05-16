#ifndef DRINK_H
#define DRINK_H

#include "userchoice.h"
#include "opticalsensor.h"
#include "proximitysensor.h"
#include "dc_motor.h"
#include "temperatursensor.h"
#include "waterheater.h"
#include "flowmeter.h"
#include "brewgroup.h"
#include "milkmaker.h"
#include "rfid_scanner.h"

class Drink
{
   private:
      UserChoice drinkSpecs;
      OpticalSensor filllevel[4];
      ProximitySensor cupsensor;
      DC_Motor motor;
      TemperaturSensor temperature;
      Waterheater heater;
      Flowmeter flow;
      Brewgroup brew;
      Milkmaker milk;
      RFID_Scanner rfid;
   public:
      Drink();
      ~Drink();
      Drink getinstance(DrinkType type);
      void brewDrink(int extraSugar, int extraMilk);
};

#endif
