#include "Person.h"

void Person::forename( std::string newForename )
{
   forename_ = std::move(newForename);
   notify( forenameChanged );
}

void Person::surname( std::string newSurname )
{
   surname_ = std::move(newSurname);
   notify( surnameChanged );
}

void Person::address( std::string newAddress )
{
   address_ = std::move(newAddress);
   notify( addressChanged );
}

bool Person::attach( PersonObserver* observer )
{
   auto [pos,success] = observers_.insert( observer );
   return success;
}

bool Person::detach( PersonObserver* observer )
{
   return ( observers_.erase( observer ) > 0U );
}

void Person::notify( StateChange property )
{
   // This formulation makes sure detach() operations
   // can be detected during the iteration
   for( auto iter=begin(observers_); iter!=end(observers_); )
   {
      auto const pos = iter++;
      (*pos)->update(*this,property);
   }
}