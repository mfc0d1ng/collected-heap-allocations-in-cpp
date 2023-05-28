#include <iostream>
#include <cstring>
#include "heap.h"


int main(int argc, char *argv[])
{
    char *ptr = (char *)heap::malloc(12);
    memcpy(ptr, "Hello world", 12);

    std::puts(ptr);

    ptr = (char *)heap::realloc(ptr, 20);
    memcpy(ptr, "Hello world, Again.", 20);

    std::puts(ptr);

    ptr = (char *)heap::realloc(ptr, 33);
    memcpy(ptr, "Hello world, Again and Welcome.", 33);

    std::puts(ptr);
    
    for (size_t i = 0; i < 50; i++)
    {
        heap::malloc(25); 
    }

    heap::show_record(); 

    std::cout << "\nYou have allocated " << heap::count() << " memory blocks\n";

    // Try this */
    /* std::free(ptr); */
    /* std::free(heap::malloc(25)); */

    heap::tear_down();

    return EXIT_SUCCESS;
}
