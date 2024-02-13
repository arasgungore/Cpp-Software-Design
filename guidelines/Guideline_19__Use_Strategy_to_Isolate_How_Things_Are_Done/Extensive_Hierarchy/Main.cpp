#include "OpenGLCircle.h"
#include "OpenGLSquare.h"
#include "DrawAllShapes.h"
#include <cstdlib>
#include <memory>
#include <vector>

int main()
{
   using Shapes = std::vector< std::unique_ptr<Shape> >;

   Shapes shapes{};

   // Creating some shapes
   shapes.emplace_back( std::make_unique<OpenGLCircle>( 2.3 ) );
   shapes.emplace_back( std::make_unique<OpenGLSquare>( 1.2 ) );
   shapes.emplace_back( std::make_unique<OpenGLCircle>( 4.1 ) );

   // Drawing all shapes
   drawAllShapes( shapes );

   return EXIT_SUCCESS;
}
