#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"
#include <string>

class Sheep : public Animal
{
 public:
   explicit Sheep( std::string name ) : name_{ std::move(name) } {}

   void makeSound() const override;
   std::unique_ptr<Animal> clone() const override;  // Prototype design pattern

 private:
   std::string name_;
};

#endif