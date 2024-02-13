#ifndef DENSE_VECTOR_H
#define DENSE_VECTOR_H

#include <cmath>
#include <numeric>
#include <ostream>

template< typename Derived >
struct DenseVector
{
   constexpr Derived&       derived()       noexcept { return static_cast<Derived&>(*this); }
   constexpr Derived const& derived() const noexcept { return static_cast<Derived const&>(*this); }

   constexpr size_t size() const noexcept { return derived().size(); }

   decltype(auto) operator[]( size_t index )       noexcept { return derived()[index]; }
   decltype(auto) operator[]( size_t index ) const noexcept { return derived()[index]; }

   decltype(auto) begin()       noexcept { return derived().begin(); }
   decltype(auto) begin() const noexcept { return derived().begin(); }
   decltype(auto) end()         noexcept { return derived().end(); }
   decltype(auto) end()   const noexcept { return derived().end(); }
};

template< typename Derived >
std::ostream& operator<<( std::ostream& os, DenseVector<Derived> const& vector )
{
   size_t const size( vector.size() );

   os << "(";
   for( size_t i=0UL; i<size; ++i ) {
      os << " " << vector[i];
   }
   os << " )";

   return os;
}

template< typename Derived >
decltype(auto) l2norm( DenseVector<Derived> const& vector )
{
   using T = typename Derived::value_type;
   return std::sqrt( std::inner_product( std::begin(vector), std::end(vector)
                                       , std::begin(vector), T{} ) );
}

#endif