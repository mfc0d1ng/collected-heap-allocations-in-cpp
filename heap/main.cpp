#include <iostream>
#include "heap.h"


int main(int argc, char *argv[])
{
    char *ptr = (char *) heap::malloc(12);
    memcpy(ptr, "Hello world", 12);

    std::puts(ptr);
    
    ptr = (char *) heap::realloc(ptr, 20);
    memcpy(ptr, "Hello world, Again.", 20);

    std::puts(ptr); 
    return EXIT_SUCCESS;
}
