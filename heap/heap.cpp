#include <iostream>
#include <vector>
#include "heap.h"

#define memerror  "Out of memory, program terminated."
#define ptrerror  "Invalid pointer, program terminated."

struct location
{
    void *heap_location;
    unsigned char status;
}__attribute__((packed));

std::vector<struct location> record;

static void print_memerror(void)
{
    std::puts(memerror);
    std::exit(0x1);
}

static void print_ptrerror(bool __found)
{
    if(__found == false)
    {
        std::puts(ptrerror);
        std::exit(0x2);
    }
}


void *heap::malloc(std::size_t __size)
{
    struct location location;
    void *heap_ptr = std::malloc(__size);
    if(heap_ptr != nullptr)
    {
        location.status = __alloc;
        location.heap_location = heap_ptr;
        record.push_back(location);
    }
    else
    {
        print_memerror();
    }
    return heap_ptr;
}


void *heap::realloc(void *__prev, std::size_t __size)
{   
    if(__prev == nullptr)
    {
        return heap::malloc(__size);
    }
    bool found = false;    
    void *heap_ptr =  std::realloc(__prev, __size);
    if(heap_ptr != nullptr)
    {
        for(std::size_t i = record.size(); i > 0; )
        {
            i --;
            if(record[i].heap_location == __prev)
            {
                found = true;
                record[i].status = __alloc;
                record[i].heap_location = heap_ptr;
                break;
            }
        }
    }
    else
    {
        print_memerror();
    }
    print_ptrerror(found);
    return heap_ptr;
}


void *heap::calloc(std::size_t __nmemb, std::size_t __size)
{
    struct location location;
    void *heap_ptr = std::calloc(__nmemb, __size);
    if(heap_ptr != nullptr)
    {
        location.status = __alloc; 
        location.heap_location = heap_ptr;
        record.push_back(location); 
    }
    else
    {
        print_memerror();
    }
    return heap_ptr;
}


void heap::free(void *__add)
{
    if(__add == nullptr)
    {
        return;
    }
    bool found = false;
    for(std::size_t i = record.size(); i > 0; )
    {
        i --;
        if((record[i].heap_location == __add) && record[i].status == __alloc)
        {
            found = true;
            record[i].status = __freed;
            std::free(record[i].heap_location);
            break;
        }
    }
    print_ptrerror(found);
}


void heap::tear_down(void)
{
    if(record.empty())
    {
        return;
    }
    for(std::size_t i = record.size(); i > 0; )
    {
        i --;
        if(record[i].status == __alloc)
        {
            std::free(record[i].heap_location);
        }
    }
}


void tear_down(void)
{
    heap::tear_down();
}

