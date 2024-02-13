#ifndef PRICED_ITEM_H
#define PRICED_ITEM_H

#include "Money.h"

template< typename T >
concept PricedItem =
   requires ( T item ) {
      { item.price() } -> std::same_as<Money>;
   };

#endif