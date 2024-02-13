#ifndef INTEGRAL_ARITHMETIC_H
#define INTEGRAL_ARITHMETIC_H

#include "Addable.h"
#include "Subtractable.h"

template< typename Derived >
struct IntegralArithmetic
   : public Addable<Derived>
   , public Subtractable<Derived>
{};

#endif