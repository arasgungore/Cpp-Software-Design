#include "ConferenceTicket.h"
#include "CppBook.h"
#include "Discounted.h"
#include "Taxed.h"
#include <cstdlib>
#include <memory>

int main()
{
   // 7% tax: 19*1.07 = 20.33
   std::unique_ptr<Item> item1(
      std::make_unique<Taxed>( 0.07,
         std::make_unique<CppBook>( "Effective C++", Money{19} ) ) );

   // 20% discount, 19% tax: (999*0.8)*1.19 = 951.05
   std::unique_ptr<Item> item2(
      std::make_unique<Taxed>( 0.19,
         std::make_unique<Discounted>( 0.2,
            std::make_unique<ConferenceTicket>( "CppCon", Money{999} ) ) ) );

   Money const totalPrice1 = item1->price();  // Results in 20.33
   Money const totalPrice2 = item2->price();  // Results in 951.05

   // ...

   return EXIT_SUCCESS;
}