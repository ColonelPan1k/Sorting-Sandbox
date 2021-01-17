/*
 * Heap library for C
 * https://github.com/kmg731
 *
 * I'm doing this to learn more about heaps and also
 * to go with an implementation of heapsort for a program
 * I'm working on 
 *
 */

#include <stdio.h>

typedef struct heap_t{
        int items[];  
}Heap;

Heap* makeHeap()
