#ifndef PERSISTENCE_INTERFACE_H
#define PERSISTENCE_INTERFACE_H

class PersistenceInterface
{
 public:
   virtual ~PersistenceInterface() = default;

   bool read( /*some arguments*/ ) const
   {
      return do_read( /*...*/ );
   }
   bool write( /*some arguments*/ )
   {
      return do_write( /*...*/ );
   }

   // ... More database specific functionality

 private:
   virtual bool do_read( /*some arguments*/ ) const = 0;
   virtual bool do_write( /*some arguments*/ ) = 0;
};

PersistenceInterface* get_persistence_interface();
void set_persistence_interface( PersistenceInterface* persistence );

// Declaration of the one 'instance' variable
extern PersistenceInterface* instance;

#endif