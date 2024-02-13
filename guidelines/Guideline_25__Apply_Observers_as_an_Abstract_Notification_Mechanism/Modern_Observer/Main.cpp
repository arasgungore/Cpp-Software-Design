#include "Observer.h"
#include "Person.h"
#include <cstdlib>

void propertyChanged( Person const& person, Person::StateChange property )
{
   if( property == Person::forenameChanged ||
       property == Person::surnameChanged )
   {
      // ... Respond to changed name
   }
}

int main()
{
   using PersonObserver = Observer<Person,Person::StateChange>;

   PersonObserver nameObserver( propertyChanged );

   PersonObserver addressObserver(
      [/*captured state*/]( Person const& person, Person::StateChange property ){
         if( property == Person::addressChanged )
         {
            // ... Respond to changed address
         }
      } );

   Person homer( "Homer"     , "Simpson" );
   Person marge( "Marge"     , "Simpson" );
   Person monty( "Montgomery", "Burns"   );

   // Attaching observers
   homer.attach( &nameObserver );
   marge.attach( &addressObserver );
   monty.attach( &addressObserver );

   // ...

   return EXIT_SUCCESS;
}