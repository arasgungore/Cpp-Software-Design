#ifndef SHAPE_H
#define SHAPE_H

#include "AbstractVisitor.h"

class Shape
{
 public:
   virtual ~Shape() = default;

   virtual void accept( AbstractVisitor const& v ) = 0;
};

#endif