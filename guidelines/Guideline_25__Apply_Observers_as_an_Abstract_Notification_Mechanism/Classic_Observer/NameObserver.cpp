#include "NameObserver.h"

void NameObserver::update( Person const& person, Person::StateChange property )
{
   if( property == Person::forenameChanged ||
       property == Person::surnameChanged )
   {
      // ... Respond to changed name
   }
}