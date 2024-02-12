#include "Calculator.h"
#include "Add.h"
#include "Subtract.h"
#include <cstdlib>
#include <memory>
#include <utility>

int main()
{
   Calculator calculator{};

   auto op1 = std::make_unique<Add>( 3 );
   auto op2 = std::make_unique<Add>( 7 );
   auto op3 = std::make_unique<Subtract>( 4 );
   auto op4 = std::make_unique<Subtract>( 2 );

   calculator.compute( std::move(op1) );  // Computes 0 + 3, stores and returns 3
   calculator.compute( std::move(op2) );  // Computes 3 + 7, stores and returns 10
   calculator.compute( std::move(op3) );  // Computes 10 - 4, stores and returns 6
   calculator.compute( std::move(op4) );  // Computes 6 - 2, stores and returns 4

   calculator.undoLast();  // Reverts the last operation,
                           // stores and returns 6

   int const res = calculator.result();  // Get the final result: 6

   // ...

   return EXIT_SUCCESS;
}