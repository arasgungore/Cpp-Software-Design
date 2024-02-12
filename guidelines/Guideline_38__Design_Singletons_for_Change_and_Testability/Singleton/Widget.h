#ifndef WIDGET_H
#define WIDGET_H

#include "PersistenceInterface.h"

class Widget
{
 public:
   Widget( PersistenceInterface* persistence )  // Dependency injection
      : persistence_(persistence)
   {}

   void doSomething( /*some arguments*/ )
   {
      doSomething( get_persistence_interface() /*, some arguments*/ );
   }

   void doSomething( PersistenceInterface* persistence /*, some arguments*/ )
   {
      // ...
      persistence->read( /*some arguments*/ );
      // ...
   }

 private:
   PersistenceInterface* persistence_{};
};

#endif