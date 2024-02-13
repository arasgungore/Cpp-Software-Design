#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <iosfwd>

template< typename Derived >
struct Printable
{
   friend std::ostream& operator<<( std::ostream& os, Derived const& d )
   {
      os << d.get();
      return os;
   }
};

#endif