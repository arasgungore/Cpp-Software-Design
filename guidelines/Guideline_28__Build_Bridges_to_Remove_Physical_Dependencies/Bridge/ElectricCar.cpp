#include "ElectricCar.h"
#include "ElectricEngine.h"
#include <iostream>

ElectricCar::ElectricCar()
   : Car{ std::make_unique<ElectricEngine>( /*engine arguments*/ ) }
   // ... Initialization of the other data members
{}

void ElectricCar::drive()
{
   getEngine()->start();
   std::cout << "Driving the 'ElectricCar'...\n";
   getEngine()->stop();
}

// ... Other 'ElectricCar' member functions, primarily using the 'Engine'
//     abstraction, but potentially also explicitly dealing with an
//     'ElectricEngine'.