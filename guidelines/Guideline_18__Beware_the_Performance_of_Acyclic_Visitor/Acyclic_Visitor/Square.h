#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "Visitor.h"

class Square : public Shape
{
 public:
   explicit Square( double side )
      : side_( side )
   {
      /* Checking that the given side length is valid */
   }

   void accept( AbstractVisitor const& v ) override {
      if( auto const* sv = dynamic_cast<Visitor<Square> const*>(&v) ) {
         sv->visit(*this);
      }
   }

   double side() const { return side_; }

 private:
   double side_;
};

#endif