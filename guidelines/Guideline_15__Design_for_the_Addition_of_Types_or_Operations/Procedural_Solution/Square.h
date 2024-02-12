#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "Point.h"

class Square : public Shape
{
 public:
   explicit Square( double side )
      : Shape( square )
      , side_( side )
   {
      /* Checking that the given side length is valid */
   }

   double side  () const { return side_; }
   Point  center() const { return center_; }

 private:
   double side_;
   Point center_{};
};

#endif