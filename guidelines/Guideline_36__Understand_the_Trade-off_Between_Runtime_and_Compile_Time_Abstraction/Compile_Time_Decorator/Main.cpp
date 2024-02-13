#include "ConferenceTicket.h"
#include "Discounted.h"
#include "Taxed.h"
#include <cstdlib>

int main()
{
   // 20% discount, 15% tax: (499*0.8)*1.15 = 459.08
   Taxed<0.15,Discounted<0.2,ConferenceTicket>> item{ "Core C++", Money{499} };

   Money const totalPrice = item.price();  // Results in 459.08

   // ...

   return EXIT_SUCCESS;
}