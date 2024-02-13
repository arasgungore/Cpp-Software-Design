#ifndef ITEM_H
#define ITEM_H

#include "Money.h"

class Item
{
 public:
   virtual ~Item() = default;
   virtual Money price() const = 0;
};

#endif