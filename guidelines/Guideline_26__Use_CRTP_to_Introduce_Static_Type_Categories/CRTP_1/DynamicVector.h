#ifndef DYNAMIC_VECTOR_H
#define DYNAMIC_VECTOR_H

#include "DenseVector.h"
#include <vector>
#include <initializer_list>

template< typename T >
class DynamicVector
   : public DenseVector< DynamicVector<T> >
{
 public:
   using value_type     = T;
   using iterator       = typename std::vector<T>::iterator;
   using const_iterator = typename std::vector<T>::const_iterator;

   DynamicVector() = default;
   DynamicVector( std::initializer_list<T> init )
      : values_( std::begin(init), std::end(init) )
   {}

   size_t size() const noexcept { return values_.size(); }

   T&       operator[]( size_t index )       noexcept { return values_[index]; }
   T const& operator[]( size_t index ) const noexcept { return values_[index]; }

   iterator       begin()       noexcept { return values_.begin(); }
   const_iterator begin() const noexcept { return values_.begin(); }
   iterator       end()         noexcept { return values_.end(); }
   const_iterator end()   const noexcept { return values_.end(); }

   // ... Many numeric functions

 private:
   std::vector<T> values_;
};

#endif