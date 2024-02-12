#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeVisitor.h"

class Shape
{
 public:
   virtual ~Shape() = default;
   virtual void accept( ShapeVisitor const& v ) = 0;
};

#endif