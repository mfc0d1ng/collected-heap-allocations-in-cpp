#ifndef HEAP_H
#define HEAP_H

class heap
{
public:
    
    heap(){};
    ~heap(){}; 

    /* Allocate SIZE bytes of memory. */
    static void *malloc(std::size_t __size);

    /* Re-allocate the previously allocated block in PREV, making the new block SIZE bytes long. */
    static void *realloc(void *__prev, std::size_t __size); 
 
    /* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
    static void *calloc(std::size_t __nmemb, std::size_t __size);

    /* Free a block allocated by `heap::malloc', `heap::realloc' or `heap::calloc'.  */
    static void free(void *__add);

    /* Show the starting addresses of all the allocated memory blocks. */
    static void show_record(void);

    /* Return the number of the memory blocks allocated by `heap::malloc', `heap::realloc' or `heap::calloc'. */
    static std::size_t count(void);

    /* Erase NB of the last memory blocks allocated by `heap::malloc', `heap::realloc' or `heap::calloc'. */
    static void erase(std::size_t __nb);

    /* Free all the memory allocated by `heap::malloc', `heap::realloc' or `heap::calloc'. */
    static void tear_down(void);

};

#endif
