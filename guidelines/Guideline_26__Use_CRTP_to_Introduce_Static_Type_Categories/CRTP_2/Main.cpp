#include "DynamicVector.h"
#include "StaticVector.h"
#include <cstdlib>
#include <iostream>

int main()
{
   DynamicVector<int> const a{ 1, 2, 3 };
   StaticVector<int,4UL> const b{ 4, 5, 6, 7 };

   std::cout << "\n"
             << " a = " << a << ", L2-norm = " << l2norm(a) << "\n"
             << " b = " << b << ", L2-norm = " << l2norm(b) << "\n"
             << "\n";

   return EXIT_SUCCESS;
}