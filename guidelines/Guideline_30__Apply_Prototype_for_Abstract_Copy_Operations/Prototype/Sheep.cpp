#include "Sheep.h"
#include <iostream>

void Sheep::makeSound() const
{
   std::cout << "baa\n";
}

std::unique_ptr<Animal> Sheep::clone() const
{
   return std::make_unique<Sheep>(*this);  // Copy-construct a sheep
}