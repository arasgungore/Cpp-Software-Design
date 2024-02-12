#include "PersistenceInterface.h"
#include "CustomPersistence.h"
#include "Widget.h"
#include <cstdlib>

int main()
{
   CustomPersistence persistence;
   set_persistence_interface( &persistence );

   Widget widget{ get_persistence_interface() };
   widget.doSomething();

   // ...

   return EXIT_SUCCESS;
}