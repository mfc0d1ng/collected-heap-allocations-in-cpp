#ifndef HEAP_H
#define HEAP_H

#define  __freed     0x0
#define  __alloc     0x1

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

    /* Free a block allocated by `malloc', `realloc' or `calloc'.  */
    static void free(void *__add);

    /* Free all the memory blocks in the record. */
    static void tear_down(void);

};

#define _Hardcoded_mode_   0x0
#define _Automatic_mode_   0x1
#define _tear_down_       _Automatic_mode_
#if     _tear_down_  ==   _Automatic_mode_
void tear_down(void) __attribute__((destructor)); 
#endif

#endif
