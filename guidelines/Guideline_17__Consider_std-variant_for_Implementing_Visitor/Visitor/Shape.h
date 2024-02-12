#ifndef SHAPE_H
#define SHAPE_H

#include "Circle.h"
#include "Square.h"
#include <variant>

using Shape = std::variant<Circle,Square>;

#endif