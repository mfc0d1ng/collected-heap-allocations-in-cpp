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

    /* Free a block allocated by `heap::malloc', `heap::realloc' or `heap::calloc'.  */
    static void free(void *__add);

    /* Free all the memory blocks in the record. */
    static void tear_down(void);

};

#endif
