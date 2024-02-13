#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
 public:
   explicit Circle( double radius )
      : radius_( radius )
   {
      /* Checking that the given radius is valid */
   }

   double radius() const { return radius_; }
   Point  center() const { return center_; }

   // ... No implementation of the draw() member function anymore

 private:
   double radius_;
   Point center_{};
};

#endif