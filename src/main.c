/*
 * --**==| Sorting Sandbox |==**--
 * This is a program to play around with and compare
 * different sorting algorithms.
 * 
 */




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#include "libs/Common.h"
#include "libs/Basic-Sorts.h"
#include "libs/bogosort.h"

/* Generate an array of length len
 * filled with random numbers */
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

int*
arrCopy(int* arr, int len){
        int* cpyArray = (int*)calloc(1, sizeof(int)* len);
        memcpy(cpyArray, arr, sizeof(int) * len);

        return cpyArray;
}

void
printArray(int* arr, int len){
        for (int i = 0; i < len; ++i){
                printf("%i ", arr[i]);
        }
        putchar('\n');
}

time_t
runSort(void (*sortFun)(int*, int), void (*sortFun2)(int*, int), int* arr, int len){

        int* cpyArr = arrCopy(arr, len);
        
        pid_t parent = getpid();
        pid_t pid = fork();


        if (pid == -1){
                printf("Error: Failed to fork\n");
                return -1;
                
        } else if (pid > 0){

                time_t start = time(NULL);
                (*sortFun)(arr, len);
                time_t end = time(NULL);

                printf("Sort1 Time: %ld sec\n", end - start);

                wait(NULL);
                
        } else {
        
                time_t start = time(NULL);
                (*sortFun2)(cpyArr, len);
                time_t end = time(NULL);

                printf("Sort2 Time: %ld sec\n", end - start);
        }
}

int
main(int argc, char** argv){

        int arrLen = 100000;
        int* arr = generateArray(arrLen);

        printf("Sort1: bubbleSort\nSort2: insertionSort\n");

        runSort(bubbleSort, insertionSort, arr, arrLen);
        

        
        return 0;
}

