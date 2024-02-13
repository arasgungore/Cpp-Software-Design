#ifndef SUBTRACTABLE_H
#define SUBTRACTABLE_H

template< typename Derived >
struct Subtractable
{
   friend Derived& operator-=( Derived& lhs, Derived const& rhs ) {
      lhs.get() -= rhs.get();
      return lhs;
   }

   friend Derived operator-( Derived const& lhs, Derived const& rhs ) {
      return Derived{ lhs.get() - rhs.get() };
   }
};

#endif