#ifndef PERSON_H
#define PERSON_H

#include "StrongType.h"
#include "Printable.h"
#include "Swappable.h"
#include <string>

using Surname = StrongType<std::string,struct SurnameTag,Printable,Swappable>;

#endif