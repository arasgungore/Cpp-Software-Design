#include <array>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory_resource>
#include <string>
#include <vector>

int main()
{
   /*
   std::array<std::byte,1000> raw;  // Note: not initialized!
   std::pmr::monotonic_buffer_resource buffer{ raw.data(), raw.size(), std::pmr::null_memory_resource() };
   */

   CustomAllocator custom_allocator{ std::pmr::new_delete_resource() };
   std::pmr::monotonic_buffer_resource buffer{ &custom_allocator };

   std::pmr::vector<std::pmr::string> strings{ &buffer };

   strings.emplace_back( "String longer than what SSO can handle" );
   strings.emplace_back( "Another long string that goes beyond SSO" );
   strings.emplace_back( "A third long string that cannot be handled by SSO" );

   for( const auto& s : strings ) {
      std::cout << std::quoted(s) << '\n';
   }

   return EXIT_SUCCESS;
}