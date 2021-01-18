/*
 * --**==| Sorting Sandbox |==**--
 * This is a program to play around with and compare
 * different sorting algorithms.
 * 
 */


#include "../libs/Common.h"
#include "../libs/Insertion-Sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int*
generateArray(int len){
        srand(time(NULL));
        int* arr = (int*)malloc(sizeof(int) * len);

        for(int i = 0; i < len; ++i){
                arr[i] = rand();
        }

        putchar('\n');

        return arr;
}

/* Test Function */
void
printArray(int* arr, int len){
        for (int i = 0; i < len; ++i){
                printf("%i ", arr[i]);
        }
}

int main(int argc, char** argv){

        int* arr = generateArray(50);

        insertionSort(arr, 50);

        printArray(arr, 50);
        
                        
        
        return 0;
}

