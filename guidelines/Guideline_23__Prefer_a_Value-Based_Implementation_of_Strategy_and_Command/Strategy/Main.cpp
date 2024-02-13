#include "Circle.h"
#include "Square.h"
#include "OpenGLCircleStrategy.h"
#include "OpenGLSquareStrategy.h"
#include <memory>
#include <vector>

int main()
{
   using Shapes = std::vector<std::unique_ptr<Shape>>;

   Shapes shapes{};

   // Creating some shapes, each one
   //   equipped with the according OpenGL drawing strategy
   shapes.emplace_back(
      std::make_unique<Circle>( 2.3, OpenGLCircleStrategy(/*...red...*/) ) );
   shapes.emplace_back(
      std::make_unique<Square>( 1.2, OpenGLSquareStrategy(/*...green...*/) ) );
   shapes.emplace_back(
      std::make_unique<Circle>( 4.1, OpenGLCircleStrategy(/*...blue...*/) ) );

   // Drawing all shapes
   for( auto const& shape : shapes )
   {
      shape->draw();
   }

   return EXIT_SUCCESS;
}