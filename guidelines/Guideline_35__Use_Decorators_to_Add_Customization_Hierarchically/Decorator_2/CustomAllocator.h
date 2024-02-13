#ifndef CUSTOM_ALLOCATOR_H
#define CUSTOM_ALLOCATOR_H

#include <cstdlib>
#include <memory_resource>

class CustomAllocator : public std::pmr::memory_resource
{
 public:
   CustomAllocator( std::pmr::memory_resource* upstream )
      : upstream_{ upstream }
   {}

 private:
   void* do_allocate( size_t bytes, size_t alignment ) override
   {
      return malloc( bytes );
   }

   void do_deallocate( void* ptr, [[maybe_unused]] size_t bytes,
                       [[maybe_unused]] size_t alignment ) override
   {
      free( ptr );
   }

   bool do_is_equal(
      std::pmr::memory_resource const& other ) const noexcept override
   {
      return ( this == &other ) ||
             ( dynamic_cast<const CustomAllocator*>( &other ) != nullptr );
   }

   std::pmr::memory_resource* upstream_{};
};

#endif