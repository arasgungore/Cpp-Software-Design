#ifndef SWAPPABLE_H
#define SWAPPABLE_H

#include <utility>

template< typename Derived >
struct Swappable
{
   friend void swap( Derived& lhs, Derived& rhs )
   {
      using std::swap;  // Enable ADL
      swap( lhs.get(), rhs.get() );
   }
};

#endif