#ifndef TAXED_H
#define TAXED_H

#include "Money.h"
#include "PricedItem.h"
#include <utility>

template< double taxRate, PricedItem Item >
class Taxed : private Item  // Using inheritance
{
 public:
   template< typename... Args >
   explicit Taxed( Args&&... args )
      : Item{ std::forward<Args>(args)... }
   {}

   Money price() const {
      return Item::price() * ( 1.0 + taxRate );
   }
};

#endif