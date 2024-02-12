#include "Sheep.h"
#include <cstdlib>
#include <memory>

int main()
{
   std::unique_ptr<Animal> dolly = std::make_unique<Sheep>( "Dolly" );
   std::unique_ptr<Animal> dollyClone = dolly->clone();

   dolly->makeSound();       // Triggers the first Dolly's beastly sound
   dollyClone->makeSound();  // The clone sounds just like Dolly

   return EXIT_SUCCESS;
}