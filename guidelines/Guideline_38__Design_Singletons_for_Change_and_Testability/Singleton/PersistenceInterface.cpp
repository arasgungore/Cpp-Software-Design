#include "Database.h"

// Definition of the one 'instance' variable
PersistenceInterface* instance = nullptr;

PersistenceInterface* get_persistence_interface()
{
   // Local object, initialized by an 'Immediately Invoked Lambda Expression (IILE)'
   static bool init = [](){
      if( !instance ) {
         static Database db;
         instance = &db;
      }
      return true;  // or false, as the actual value does not matter.
   }();  // Note the '()' after the lambda expression. This invokes the lambda.

   return instance;
}

void set_persistence_interface( PersistenceInterface* persistence )
{
   instance = persistence;
}