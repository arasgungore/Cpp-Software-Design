#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
 public:
   Shape() = default;

   virtual ~Shape() = default;

   virtual void draw() const = 0;
};

#endif