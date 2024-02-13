#ifndef SHAPE_H
#define SHAPE_H

#include <functional>
#include <stdexcept>
#include <utility>

class ShapeConcept
{
 public:
   virtual ~ShapeConcept() = default;

   virtual void draw() const = 0;

   // ... Potentially more polymorphic operations
};


template< typename ShapeT
        , typename DrawStrategy >
class ShapeModel : public ShapeConcept
{
 public:
   explicit ShapeModel( ShapeT shape, DrawStrategy drawer )
      : shape_{ std::move(shape) }
      , drawer_{ std::move(drawer) }
   {}

   void draw() const override { drawer_(shape_); }

 private:
   ShapeT shape_;
   DrawStrategy drawer_;
};

#endif