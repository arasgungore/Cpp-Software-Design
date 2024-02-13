#ifndef ADDRESS_OBSERVER_H
#define ADDRESS_OBSERVER_H

#include "Observer.h"
#include "Person.h"

class AddressObserver : public Observer<Person,Person::StateChange>
{
 public:
   void update( Person const& person, Person::StateChange property ) override;
};

#endif