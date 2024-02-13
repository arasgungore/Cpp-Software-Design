#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <functional>
#include <utility>

class Square : public Shape
{
 public:
   using DrawStrategy = std::function<void(Square const& /*, ...*/)>;

   explicit Square( double side, DrawStrategy drawer )
      : side_( side )
      , drawer_( std::move(drawer) )
   {
      /* Checking that the given side length is valid and that
         the given 'std::function' instance is not empty */
   }

   void draw( /*some arguments*/ ) const override
   {
      drawer_( *this /*, some arguments*/ );
   }

   double side() const { return side_; }

 private:
   double side_;
   DrawStrategy drawer_;
};

#endif