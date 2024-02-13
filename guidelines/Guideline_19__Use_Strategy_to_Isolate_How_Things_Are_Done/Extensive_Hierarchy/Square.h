#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include "Shape.h"

class Square : public Shape
{
 public:
   explicit Square( double side )
      : side_( side )
   {
      /* Checking that the given side length is valid */
   }

   double side  () const { return side_; }
   Point  center() const { return center_; }

   // ... No implementation of the draw() member function anymore

 private:
   double side_;
   Point center_{};
};

#endif