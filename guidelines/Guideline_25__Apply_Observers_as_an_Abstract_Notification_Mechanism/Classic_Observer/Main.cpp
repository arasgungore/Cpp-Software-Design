#include "AddressObserver.h"
#include "NameObserver.h"
#include "Person.h"
#include <cstdlib>

int main()
{
   NameObserver nameObserver;
   AddressObserver addressObserver;

   Person homer( "Homer"     , "Simpson" );
   Person marge( "Marge"     , "Simpson" );
   Person monty( "Montgomery", "Burns"   );

   // Attaching observers
   homer.attach( &nameObserver );
   marge.attach( &addressObserver );
   monty.attach( &addressObserver );

   // Updating information on Homer Simpson
   homer.forename( "Homer Jay" );  // Adding his middle name

   // Updating information on Marge Simpson
   marge.address( "712 Red Bark Lane, Henderson, Clark County, Nevada 89011" );

   // Updating information on Montgomery Burns
   monty.address( "Springfield Nuclear Power Plant" );

   // Detaching observers
   homer.detach( &nameObserver );

   return EXIT_SUCCESS;
}