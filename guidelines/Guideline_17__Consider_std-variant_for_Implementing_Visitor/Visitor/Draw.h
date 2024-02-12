#ifndef DRAW_H
#define DRAW_H

#include "Circle.h"
#include "Square.h"
//#include /* some graphics library */

class Draw
{
 public:
   void operator()( Circle const& c ) const
   {
      /* ... Implementing the logic for drawing a circle ... */
   }
   void operator()( Square const& s ) const
   {
      /* ... Implementing the logic for drawing a square ... */
   }
};

#endif