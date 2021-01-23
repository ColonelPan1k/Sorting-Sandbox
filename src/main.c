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
                clock_t start = clock(), diff;

                (*sortFun)(arr, len);

                diff = clock() - start;
                int msec = diff * 100 / CLOCKS_PER_SEC;
                printf("Sort1: %d seconds %d milliseconds\n", msec/1000, msec%1000);

                wait(NULL);
                
        } else {
                printf("Starting array: ");
                printArray(cpyArr, len);

                clock_t start = clock(), diff;
                
                (*sortFun2)(cpyArr, len);

                diff = clock() - start;
                int msec = diff * 1000 / CLOCKS_PER_SEC;

                printf("Sort2: %d seconds %d milliseconds\n", msec/1000, msec%100);
        }
}

/* Copies an array to a new temp array */




int
main(int argc, char** argv){

        int arrLen = 11;
        int* arr = generateArray(arrLen);
        printf("Your starting array: ");
        printArray(arr, arrLen);

        runSort(insertionSort, bogosort, arr, arrLen);
        

        
        return 0;
}

