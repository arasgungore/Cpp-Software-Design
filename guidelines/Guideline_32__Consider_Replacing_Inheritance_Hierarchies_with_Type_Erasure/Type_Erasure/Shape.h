#ifndef SHAPE_H
#define SHAPE_H

#include <memory>
#include <utility>

namespace detail {

class ShapeConcept  // The External Polymorphism design pattern
{
 public:
   virtual ~ShapeConcept() = default;
   virtual void draw() const = 0;
   virtual std::unique_ptr<ShapeConcept> clone() const = 0;  // The Prototype design pattern
};

template< typename ShapeT
        , typename DrawStrategy >
class OwningShapeModel : public ShapeConcept
{
 public:
   explicit OwningShapeModel( ShapeT shape, DrawStrategy drawer )
      : shape_{ std::move(shape) }
      , drawer_{ std::move(drawer) }
   {}

   void draw() const override { drawer_(shape_); }

   std::unique_ptr<ShapeConcept> clone() const override  // The Prototype design pattern
   {
      return std::make_unique<OwningShapeModel>( *this );
   }

 private:
   ShapeT shape_;
   DrawStrategy drawer_;
};

} // namespace detail


class Shape
{
 public:
   template< typename ShapeT
           , typename DrawStrategy >
   Shape( ShapeT shape, DrawStrategy drawer )
   {
      using Model = detail::OwningShapeModel<ShapeT,DrawStrategy>;
      pimpl_ = std::make_unique<Model>( std::move(shape)
                                      , std::move(drawer) );
   }

   Shape( Shape const& other )
      : pimpl_( other.pimpl_->clone() )
   {}

   Shape& operator=( Shape const& other )
   {
      // Copy-and-Swap Idiom
      Shape copy( other );
      pimpl_.swap( copy.pimpl_ );
      return *this;
   }

   ~Shape() = default;
   Shape( Shape&& ) = default;
   Shape& operator=( Shape&& ) = default;

 private:
   friend void draw( Shape const& shape )
   {
      shape.pimpl_->draw();
   }

   std::unique_ptr<detail::ShapeConcept> pimpl_;  // The Bridge design pattern
};

#endif