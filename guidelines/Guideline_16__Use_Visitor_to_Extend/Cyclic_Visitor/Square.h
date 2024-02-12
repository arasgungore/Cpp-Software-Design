#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
 public:
   explicit Square( double side )
      : side_( side )
   {
      /* Checking that the given side length is valid */
   }

   void accept( ShapeVisitor const& v ) override { v.visit(*this); }

   double side() const { return side_; }

 private:
   double side_;
};

#endif