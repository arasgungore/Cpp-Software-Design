#include "ConferenceTicket.h"
#include "Discounted.h"
#include "Taxed.h"
#include <cstdlib>

int main()
{
   // 20% discount, 15% tax: (499*0.8)*1.15 = 459.08
   Item item( Taxed( 0.15, Discounted(0.2, ConferenceTicket{ "Core C++", Money{499} } ) ) );

   Money const totalPrice = item.price();

   // ...

   return EXIT_SUCCESS;
}