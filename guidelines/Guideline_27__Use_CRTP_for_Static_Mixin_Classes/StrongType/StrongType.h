#ifndef STRONG_TYPE_H
#define STRONG_TYPE_H

#include <utility>
#include <iostream>

template< typename T, typename Tag, template<typename> class... Skills >
struct StrongType
   : public Skills< StrongType<T,Tag,Skills...> >...
{
 public:
   using value_type = T;

   explicit constexpr StrongType( T const& value ) : value_( value ) {}

   constexpr T&       get()       noexcept { return value_; }
   constexpr T const& get() const noexcept { return value_; }

   void swap( StrongType& other ) {
      using std::swap;
      swap( value_, other.value_ );
   }

 private:
   T value_;
};

template< typename T, typename Tag, template<typename> class... Skills >
std::ostream& operator<<( std::ostream& os, StrongType<T,Tag,Skills...> const& nt )
{
   os << nt.get();
   return os;
}

template< typename T, typename Tag, template<typename> class... Skills >
void swap( StrongType<T,Tag,Skills...>& a, StrongType<T,Tag,Skills...>& b )
{
   a.swap( b );
}

#endif