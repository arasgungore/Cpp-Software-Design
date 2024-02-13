#ifndef SHAPE_H
#define SHAPE_H

#include <cstddef>
#include <memory>

class Shape
{
 public:
   template< typename ShapeT
           , typename DrawStrategy >
   Shape( ShapeT shape, DrawStrategy drawer )
      : pimpl_(
            new OwningModel<ShapeT,DrawStrategy>( std::move(shape)
                                                , std::move(drawer) )
          , []( void* shapeBytes ){
               using Model = OwningModel<ShapeT,DrawStrategy>;
               auto* const model = static_cast<Model*>(shapeBytes);
               delete model;
            } )
      , draw_(
            []( void* shapeBytes ){
               using Model = OwningModel<ShapeT,DrawStrategy>;
               auto* const model = static_cast<Model*>(shapeBytes);
               (model->drawer_)( model->shape_ );
            } )
      , clone_(
            []( void* shapeBytes ) -> void* {
               using Model = OwningModel<ShapeT,DrawStrategy>;
               auto* const model = static_cast<Model*>(shapeBytes);
               return new Model( *model );
            } )
   {}

   Shape( Shape const& other )
      : pimpl_( other.clone_( other.pimpl_.get() ), other.pimpl_.get_deleter() )
      , draw_ ( other.draw_ )
      , clone_( other.clone_ )
   {}

   Shape& operator=( Shape const& other )
   {
      // Copy-and-Swap Idiom
      using std::swap;
      Shape copy( other );
      swap( pimpl_, copy.pimpl_ );
      swap( draw_, copy.draw_ );
      swap( clone_, copy.clone_ );
      return *this;
   }

   ~Shape() = default;
   Shape( Shape&& ) = default;
   Shape& operator=( Shape&& ) = default;

 private:
   friend void draw( Shape const& shape )
   {
      shape.draw_( shape.pimpl_.get() );
   }

   template< typename ShapeT
           , typename DrawStrategy >
   struct OwningModel
   {
      OwningModel( ShapeT value, DrawStrategy drawer )
         : shape_( std::move(value) )
         , drawer_( std::move(drawer) )
      {}

      ShapeT shape_;
      DrawStrategy drawer_;
   };

   using DestroyOperation = void(void*);
   using DrawOperation    = void(void*);
   using CloneOperation   = void*(void*);

   std::unique_ptr<void,DestroyOperation*> pimpl_;
   DrawOperation*  draw_ { nullptr };
   CloneOperation* clone_{ nullptr };
};

#endif