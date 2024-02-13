#include "Circle.h"
#include "Shape.h"
#include <cstdlib>

void useShapeConstRef( ShapeConstRef shape )
{
   draw( shape );
}

int main()
{
   // Create a circle as one representative of a concrete shape type
   Circle circle{ 3.14 };

   // Create a drawing strategy in form of a lambda
   auto drawer = []( Circle const& c ){ /*...*/ };

   // Draw the circle directly via the 'ShapeConstRef' abstraction
   useShapeConstRef( { circle, drawer } );

   return EXIT_SUCCESS;
}