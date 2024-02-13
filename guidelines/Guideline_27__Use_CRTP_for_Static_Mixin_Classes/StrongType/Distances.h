#ifndef DISTANCES_H
#define DISTANCES_H

#include "IntegralArithmetic.h"
#include "Printable.h"
#include "StrongType.h"
#include "Swappable.h"

template< typename T >
using Meter = StrongType<T,struct MeterTag,IntegralArithmetic,Printable,Swappable>;

template< typename T >
using Kilometer = StrongType<T,struct KilometerTag,IntegralArithmetic,Printable,Swappable>;

#endif