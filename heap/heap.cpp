#include <iostream>
#include <vector>
#include "heap.h"

#define memerror  "Out of memory, program terminated."
#define ptrerror  "Invalid pointer, program terminated."

static std::vector<void*> record = {};

static void print_memerror(void)
{
    std::puts(memerror);
    std::exit(0x1);
}

static void print_ptrerror(void)
{
    std::puts(ptrerror);
    std::exit(0x2);
}


void *heap::malloc(std::size_t __size)
{
    void *heap_ptr = std::malloc(__size);
    if(heap_ptr != nullptr)
    {
        record.push_back(heap_ptr);
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
    void *heap_ptr = std::realloc(__prev, __size);
    if(heap_ptr != nullptr)
    {
        for(std::size_t i = record.size(); i > 0; )
        {
            if(record[--i] == __prev)
            {
                found = true;
                record[i] = heap_ptr;
                break;
            }
        }
    }
    else
    {
        print_memerror();
    }
    if(found == false)
    {
        print_ptrerror();
    }
    return heap_ptr;
}


void *heap::calloc(std::size_t __nmemb, std::size_t __size)
{
    void *heap_ptr = std::calloc(__nmemb, __size);
    if(heap_ptr != nullptr)
    {
        record.push_back(heap_ptr); 
    }
    else
    {
        print_memerror();
    }
    return heap_ptr;
}


void heap::free(void *__ptr)
{
    if(__ptr == nullptr)
    {
        return;
    }
    bool found = false;
    for(std::size_t i = record.size(); i > 0; )
    {
        if(record[--i] == __ptr)
        {
            found = true;
            std::free(record[i]);
            record[i] = nullptr;
            break;
        }
    }
    if(found == false)
    {
        print_ptrerror();
    }
}


void heap::show_record(void)
{
    if(record.size())
    {
        std::printf("\nYour heap allocations starts at\n%c", '{');
    }
    else
    {
        std::puts("\nNo memory blocks has been allocated.");
    }
    std::size_t i = 0;
    for(std::size_t j = record.size(); i < j; i++)
    {
        if(record[i] != nullptr)
        {
            if(i && i % 4 == 0)
            {
                printf("%s", "\n ");
            }
            std::printf("%p, ", record[i]);
        }
    }
    i ? std::printf("\033[2D%c\n", '}') : 0;
}


std::size_t heap::count(void)
{
    return record.size();
}


void heap::erase(std::size_t __nb)
{
    if(__nb > record.size())
    {
        return;
    }
    std::size_t index = record.size();
    for(std::size_t i = 0; i < __nb; ++i)
    {
        if(record[--index] != nullptr)
        {
            std::free(record[index]); 
        }
    }
    record.resize(index); 
}


void heap::tear_down(void)
{
    for(std::size_t index = record.size(); index > 0; )
    {
        if(record[--index] != nullptr)
        {
            std::free(record[index]); 
        }
    }
}


