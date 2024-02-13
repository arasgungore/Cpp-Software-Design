#ifndef DISCOUNTED_H
#define DISCOUNTED_H

#include "Money.h"
#include "PricedItem.h"
#include <utility>

template< double discount, PricedItem Item >
class Discounted  // Using composition
{
 public:
   template< typename... Args >
   explicit Discounted( Args&&... args )
      : item_{ std::forward<Args>(args)... }
   {}

   Money price() const {
      return item_.price() * ( 1.0 - discount );
   }

 private:
   Item item_;
};

#endif