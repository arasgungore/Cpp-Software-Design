#ifndef CONFERENCE_TICKET_H
#define CONFERENCE_TICKET_H

#include "Item.h"
#include <string>
#include <utility>

class ConferenceTicket : public Item
{
 public:
   ConferenceTicket( std::string name, Money price )
      : name_{ std::move(name) }
      , price_{ price }
   {}

   std::string const& name() const { return name_; }
   Money price() const override { return price_; }

 private:
   std::string name_{};
   Money price_{};
};

#endif