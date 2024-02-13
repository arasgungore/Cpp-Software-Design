#include "Circle.h"
#include "DrawAllShapes.h"
#include "Square.h"
#include "OpenGLCircleStrategy.h"
#include "OpenGLSquareStrategy.h"
#include <memory>
#include <vector>
#include <cstdlib>

int main()
{
   using Shapes = std::vector<std::unique_ptr<Shape>>;

   Shapes shapes{};

   // Creating some shapes, each one
   //   equipped with the according OpenGL drawing strategy
   shapes.emplace_back(
      std::make_unique<Circle>(
         2.3, std::make_unique<OpenGLCircleStrategy>(/*...red...*/) ) );
   shapes.emplace_back(
      std::make_unique<Square>(
         1.2, std::make_unique<OpenGLSquareStrategy>(/*...green...*/) ) );
   shapes.emplace_back(
      std::make_unique<Circle>(
         4.1, std::make_unique<OpenGLCircleStrategy>(/*...blue...*/) ) );

   drawAllShapes(shapes);

   return EXIT_SUCCESS;
}