#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "DrawStrategy.h"
#include <memory>
#include <utility>

class Circle : public Shape
{
 public:
   using DrawCircleStrategy = DrawStrategy<Circle>;

   explicit Circle( double radius, std::unique_ptr<DrawCircleStrategy> drawer )
      : radius_( radius )
      , drawer_( std::move(drawer) )
   {
      /* Checking that the given radius is valid and that
         the given 'std::unique_ptr' is not a nullptr */
   }

   void draw( /*some arguments*/ ) const override
   {
      drawer_->draw( *this /*, some arguments*/ );
   }

   double radius() const { return radius_; }

 private:
   double radius_;
   std::unique_ptr<DrawCircleStrategy> drawer_;
};

#endif