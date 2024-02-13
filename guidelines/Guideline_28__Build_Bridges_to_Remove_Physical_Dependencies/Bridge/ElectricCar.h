#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#include "Car.h"

class ElectricCar : public Car
{
 public:
   ElectricCar();

   void drive();
   // ...

 private:
   // ...
};

#endif