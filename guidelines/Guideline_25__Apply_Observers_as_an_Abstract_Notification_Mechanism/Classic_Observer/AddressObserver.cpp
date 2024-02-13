#include "AddressObserver.h"

void AddressObserver::update( Person const& person, Person::StateChange property )
{
   if( property == Person::addressChanged ) {
      // ... Respond to changed address
   }
}