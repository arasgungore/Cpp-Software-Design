#include "DrawAllShapes.h"
#include "Draw.h"
#include "Shape.h"

void drawAllShapes( std::vector< std::unique_ptr<Shape> > const& shapes )
{
   for( auto const& shape : shapes )
   {
      shape->accept( Draw{} );
   }
}