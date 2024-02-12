#ifndef DRAW_H
#define DRAW_H

#include "Circle.h"
#include "ShapeVisitor.h"
#include "Square.h"

class Draw : public ShapeVisitor
{
 public:
   void visit( Circle const& c /*, ...*/ ) const override
   {
      // ... Implementing the logic for drawing a circle
   }

   void visit( Square const& s /*, ...*/ ) const override
   {
      // ... Implementing the logic for drawing a square
   }

   // Possibly more visit() functions, one for each concrete shape
};

#endif