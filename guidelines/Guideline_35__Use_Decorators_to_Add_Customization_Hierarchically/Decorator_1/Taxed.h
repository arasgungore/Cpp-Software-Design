#ifndef TAXED_H
#define TAXED_H

#include "DecoratedItem.h"

class Taxed : public DecoratedItem
{
 public:
   Taxed( double taxRate, std::unique_ptr<Item> item )
      : DecoratedItem( std::move(item) )
      , factor_( 1.0 + taxRate )
   {
      if( !std::isfinite(taxRate) || taxRate < 0.0 ) {
         throw std::invalid_argument( "Invalid tax" );
      }
   }

   Money price() const override
   {
      return item().price() * factor_;
   }

 private:
   double factor_;
};

#endif