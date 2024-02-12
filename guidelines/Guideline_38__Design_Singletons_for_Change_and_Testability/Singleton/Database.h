#ifndef DATABASE_H
#define DATABASE_H

#include "PersistenceInterface.h"

class Database : public PersistenceInterface
{
 public:
   Database() = default;

   // ... Potentially access to data members

   // Make the class immobile by deleting the copy and move operations
   Database( Database const& ) = delete;
   Database& operator=( Database const& ) = delete;
   Database( Database&& ) = delete;
   Database& operator=( Database&& ) = delete;

 private:
   bool do_read( /*some arguments*/ ) const override
   {
      /* Reading from the database */
      return true;
   }

   bool do_write( /*some arguments*/ ) override
   {
      /* Writing to the database */
      return true;
   }

   // ... More database-specific functionality

   // ... Potentially some data members
};

#endif