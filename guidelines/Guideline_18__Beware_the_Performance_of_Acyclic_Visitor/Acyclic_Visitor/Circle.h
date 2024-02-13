#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Visitor.h"

class Circle : public Shape
{
 public:
   explicit Circle( double radius )
      : radius_( radius )
   {
      /* Checking that the given radius is valid */
   }

   void accept( AbstractVisitor const& v ) override {
      if( auto const* cv = dynamic_cast<Visitor<Circle> const*>(&v) ) {
         cv->visit(*this);
      }
   }

   double radius() const { return radius_; }

 private:
   double radius_;
};

#endif