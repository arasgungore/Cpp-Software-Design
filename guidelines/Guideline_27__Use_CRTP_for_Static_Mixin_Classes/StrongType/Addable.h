#ifndef ADDABLE_H
#define ADDABLE_H

template< typename Derived >
struct Addable
{
   friend Derived& operator+=( Derived& lhs, Derived const& rhs ) {
      lhs.get() += rhs.get();
      return lhs;
   }

   friend Derived operator+( Derived const& lhs, Derived const& rhs ) {
      return Derived{ lhs.get() + rhs.get() };
   }
};

#endif