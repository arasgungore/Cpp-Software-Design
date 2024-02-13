#ifndef SHAPE_H
#define SHAPE_H

#include <array>
#include <cstdlib>
#include <memory>
#include <utility>


template< size_t Capacity = 32U, size_t Alignment = alignof(void*) >
class Shape
{
 public:
   template< typename ShapeT, typename DrawStrategy >
   Shape( ShapeT shape, DrawStrategy drawer )
   {
      using Model = OwningModel<ShapeT,DrawStrategy>;

      static_assert( sizeof(Model) <= Capacity, "Given type is too large" );
      static_assert( alignof(Model) <= Alignment, "Given type is misaligned" );

      std::construct_at( static_cast<Model*>(pimpl())
                       , std::move(shape), std::move(drawer) );
      // or:
      // auto* ptr =
      //    const_cast<void*>(static_cast<void const volatile*>(pimpl()));
      // ::new (ptr) Model( std::move(shape), std::move(drawer) );
   }

   Shape( Shape const& other )
   {
      other.pimpl()->clone( pimpl() );
   }

   Shape& operator=( Shape const& other )
   {
      // Copy-and-Swap Idiom
      Shape copy( other );
      buffer_.swap( copy.buffer_ );
      return *this;
   }

   Shape( Shape&& other ) noexcept
   {
      other.pimpl()->move( pimpl() );
   }

   Shape& operator=( Shape&& other ) noexcept
   {
      // Copy-and-Swap Idiom
      Shape copy( std::move(other) );
      buffer_.swap( copy.buffer_ );
      return *this;
   }

   ~Shape()
   {
      std::destroy_at( pimpl() );
      // or: pimpl()->~Concept();
   }

 private:
   friend void draw( Shape const& shape )
   {
      shape.pimpl()->draw();
   }

   struct Concept  // The External Polymorphism design pattern
   {
      virtual ~Concept() = default;
      virtual void draw() const = 0;
      virtual void clone( Concept* memory ) const = 0;  // The Prototype design pattern
      virtual void move( Concept* memory ) = 0;
   };

   template< typename ShapeT, typename DrawStrategy >
   struct OwningModel : public Concept
   {
      OwningModel( ShapeT shape, DrawStrategy drawer )
         : shape_( std::move(shape) )
         , drawer_( std::move(drawer) )
      {}

      void draw() const override
      {
         drawer_( shape_ );
      }

      void clone( Concept* memory ) const override
      {
         std::construct_at( static_cast<OwningModel*>(memory), *this );

         // or:
         // auto* ptr = const_cast<void*>(static_cast<void const volatile*>(memory));
         // ::new (ptr) OwningModel( *this );
      }

      void move( Concept* memory ) override
      {
         std::construct_at( static_cast<OwningModel*>(memory), std::move(*this) );

         // or:
         // auto* ptr = const_cast<void*>(static_cast<void const volatile*>(memory));
         // ::new (ptr) OwningModel( std::move(*this) );
      }

      ShapeT shape_;
      DrawStrategy drawer_;
   };

   Concept* pimpl()  // The Bridge design pattern
   {
      return reinterpret_cast<Concept*>( buffer_.data() );
   }

   Concept const* pimpl() const
   {
      return reinterpret_cast<Concept const*>( buffer_.data() );
   }

   alignas(Alignment) std::array<std::byte,Capacity> buffer_;
};

#endif