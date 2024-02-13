#include "Circle.h"
#include "Shape.h"
#include <cstdlib>

int main()
{
   // Create a circle as one representative of a concrete shape type
   Circle circle{ 3.14 };

   // Create a drawing strategy in form of a lambda
   auto drawer = []( Circle const& c ){ /*...*/ };

   // Combine the shape and the drawing strategy in a 'Shape' abstraction
   Shape shape1( circle, drawer );

   // Draw the shape
   draw( shape1 );

   // Create a reference to the shape
   // Works already, but the shape reference will store a pointer
   // to the 'shape1' instance instead of a pointer to the 'circle'.
   ShapeConstRef shaperef( shape1 );

   // Draw via the shape reference, resulting in the same output
   // This works, but only by means of two indirections!
   draw( shaperef );

   // Create a deep copy of the shape via the shape reference
   // This is _not_ possible with the simple non-owning implementation!
   // With the simple implementation, this creates a copy of the 'shaperef'
   // instance. 'shape2' itself would act as a reference and there would be
   // three indirections... sigh.
   Shape shape2( shaperef );

   // Drawing the copy will again result in the same output
   draw( shape2 );

   return EXIT_SUCCESS;
}