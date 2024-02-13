#include "Distances.h"
#include <cstdlib>
#include <iostream>

int main()
{
   auto const m1 = Meter<long>{ 100 };
   auto const m2 = Meter<long>{  50 };

   auto const m3 = m1 + m2;  // Compiles and results in 150 meters

   std::cout << "\n m3  = " << m3 << "m\n\n";

   return EXIT_SUCCESS;
}
