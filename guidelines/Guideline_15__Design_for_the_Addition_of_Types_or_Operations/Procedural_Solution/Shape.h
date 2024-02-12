#ifndef SHAPE_H
#define SHAPE_H

enum ShapeType
{
   circle,
   square
};

class Shape
{
 protected:
   explicit Shape( ShapeType type )
      : type_( type )
   {}

 public:
   virtual ~Shape() = default;

   ShapeType getType() const { return type_; }

 private:
   ShapeType type_;
};

#endif