#include "Circle.h"
#include "Square.h"
#include "Shape.h"
#include "OpenGLDrawStrategy.h"
#include <memory>
#include <vector>

int main()
{
   using Shapes = std::vector<std::unique_ptr<ShapeConcept>>;

   using CircleModel = ShapeModel<Circle,OpenGLDrawStrategy>;
   using SquareModel = ShapeModel<Square,OpenGLDrawStrategy>;

   Shapes shapes{};

   // Creating some shapes, each one
   //   equipped with an OpenGL drawing strategy
   shapes.emplace_back(
      std::make_unique<CircleModel>(
         Circle{2.3}, OpenGLDrawStrategy(/*...red...*/) ) );
   shapes.emplace_back(
      std::make_unique<SquareModel>(
         Square{1.2}, OpenGLDrawStrategy(/*...green...*/) ) );
   shapes.emplace_back(
      std::make_unique<CircleModel>(
         Circle{4.1}, OpenGLDrawStrategy(/*...blue...*/) ) );

   // Drawing all shapes
   for( auto const& shape : shapes )
   {
      shape->draw();
   }

   return EXIT_SUCCESS;
}
