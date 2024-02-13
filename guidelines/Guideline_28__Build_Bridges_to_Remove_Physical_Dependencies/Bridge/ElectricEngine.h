#ifndef ELECTRIC_ENGINE_H
#define ELECTRIC_ENGINE_H

#include "Engine.h"

class ElectricEngine : public Engine
{
 public:
   void start() override;
   void stop() override;

 private:
   // ...
};

#endif