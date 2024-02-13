#ifndef DRAW_H
#define DRAW_H

#include "AbstractVisitor.h"
#include "Visitor.h"
#include "Circle.h"
#include "Square.h"

class Draw : public AbstractVisitor
           , public Visitor<Circle>
           , public Visitor<Square>
{
 public:
   void visit( Circle const& c ) const override
      { /* ... Implementing the logic for drawing a circle ... */ }
   void visit( Square const& s ) const override
      { /* ... Implementing the logic for drawing a square ... */ }
};

#endif