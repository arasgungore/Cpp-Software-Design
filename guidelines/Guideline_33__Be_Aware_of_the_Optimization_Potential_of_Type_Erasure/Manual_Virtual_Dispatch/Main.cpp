#include "Circle.h"
#include "Square.h"
#include "Shape.h"
#include <cstdlib>

int main()
{
   // Create a circle as one representative of a concrete shape type
   Circle circle{ 3.14 };

   // Create a drawing strategy in form of a lambda
   auto drawer = []( Circle const& c ){ /*...*/ };

   // Combine the shape and the drawing strategy in a 'Shape' abstraction
   // This constructor call will instantiate a 'detail::OwningShapeModel' for
   // the given 'Circle' and lambda types
   Shape shape1( circle, drawer );

   // Draw the shape
   draw( shape1 );

   // Create a copy of the shape by means of the copy constructor
   Shape shape2( shape1 );

   // Drawing the copy will result in the same output
   draw( shape2 );

   return EXIT_SUCCESS;
}