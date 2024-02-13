#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "DrawStrategy.h"
#include <memory>
#include <utility>

class Square : public Shape
{
 public:
   using DrawSquareStrategy = DrawStrategy<Square>;

   explicit Square( double side, std::unique_ptr<DrawSquareStrategy> drawer )
      : side_( side )
      , drawer_( std::move(drawer) )
   {
      /* Checking that the given side length is valid and that
         the given 'std::unique_ptr' is not a nullptr */
   }

   void draw( /*some arguments*/ ) const override
   {
      drawer_->draw( *this /*, some arguments*/ );
   }

   double side() const { return side_; }

 private:
   double side_;
   std::unique_ptr<DrawSquareStrategy> drawer_;
};

#endif