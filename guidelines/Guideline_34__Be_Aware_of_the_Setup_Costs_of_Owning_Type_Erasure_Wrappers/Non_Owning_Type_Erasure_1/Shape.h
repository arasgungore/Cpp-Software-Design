#ifndef SHAPE_H
#define SHAPE_H

#include <memory>

class ShapeConstRef
{
 public:
   template< typename ShapeT, typename DrawStrategy >
   ShapeConstRef( ShapeT& shape, DrawStrategy& drawer )
      : shape_{ std::addressof(shape) }
      , drawer_{ std::addressof(drawer) }
      , draw_{ []( void const* shapeBytes, void const* drawerBytes ){
           auto const* shape = static_cast<ShapeT const*>(shapeBytes);
           auto const* drawer = static_cast<DrawStrategy const*>(drawerBytes);
           (*drawer)( *shape );
        } }
   {}

 private:
   friend void draw( ShapeConstRef const& shape )
   {
      shape.draw_( shape.shape_, shape.drawer_ );
   }

   using DrawOperation = void( void const*,void const* );

   void const* shape_{ nullptr };
   void const* drawer_{ nullptr };
   DrawOperation* draw_{ nullptr };
};

#endif