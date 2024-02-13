#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H

#include "DenseVector.h"
#include <array>
#include <initializer_list>

template< typename T, size_t Size >
class StaticVector
   : public DenseVector< StaticVector<T,Size> >
{
 public:
   using value_type     = T;
   using iterator       = typename std::array<T,Size>::iterator;
   using const_iterator = typename std::array<T,Size>::const_iterator;

   StaticVector() = default;
   StaticVector( std::initializer_list<T> init )
   {
      std::copy( std::begin(init), std::end(init), std::begin(values_) );
   }

   size_t size() const noexcept { return values_.size(); }

   T&       operator[]( size_t index )       noexcept { return values_[index]; }
   T const& operator[]( size_t index ) const noexcept { return values_[index]; }

   iterator       begin()       noexcept { return values_.begin(); }
   const_iterator begin() const noexcept { return values_.begin(); }
   iterator       end()         noexcept { return values_.end(); }
   const_iterator end()   const noexcept { return values_.end(); }

   // ... Many numeric functions

 private:
   std::array<T,Size> values_;
};

#endif