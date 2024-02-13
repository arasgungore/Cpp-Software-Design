#ifndef NAME_OBSERVER_H
#define NAME_OBSERVER_H

#include "Observer.h"
#include "Person.h"

class NameObserver : public Observer<Person,Person::StateChange>
{
 public:
   void update( Person const& person, Person::StateChange property ) override;
};

#endif