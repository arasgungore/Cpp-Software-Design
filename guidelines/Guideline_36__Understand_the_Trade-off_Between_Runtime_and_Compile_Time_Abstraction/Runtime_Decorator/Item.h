#ifndef ITEM_H
#define ITEM_H

#include "Money.h"
#include <memory>
#include <utility>

class Item
{
 public:
   template< typename T >
   Item( T item )
      : pimpl_( std::make_unique<Model<T>>( std::move(item) ) )
   {}

   Item( Item const& item ) : pimpl_( item.pimpl_->clone() ) {}

   Item& operator=( Item const& item )
   {
      pimpl_ = item.pimpl_->clone();
      return *this;
   }

   ~Item() = default;
   Item( Item&& ) = default;
   Item& operator=( Item&& item ) = default;

   Money price() const { return pimpl_->price(); }

 private:
   struct Concept
   {
      virtual ~Concept() = default;
      virtual Money price() const = 0;
      virtual std::unique_ptr<Concept> clone() const = 0;
   };

   template< typename T >
   struct Model : public Concept
   {
      explicit Model( T const& item ) : item_( item ) {}
      explicit Model( T&& item ) : item_( std::move(item) ) {}

      Money price() const override
      {
         return item_.price();
      }

      std::unique_ptr<Concept> clone() const override
      {
         return std::make_unique<Model<T>>(*this);
      }

      T item_;
   };

   std::unique_ptr<Concept> pimpl_;
};

#endif