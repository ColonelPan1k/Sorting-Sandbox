/*
 * --**==| Sorting Sandbox |==**--
 * This is a program to play around with and compare
 * different sorting algorithms.
 * 
 */

/* 
 * What are the necessary components? 
 * 1. Random array generation
 * 2. Command line argument parsing with getopt
 * 3. a fork/exec/wait part for timing each function,
 *    - Create two forks for each sorting function
 *    - after each fork returns, there should be some time
 *      comparison
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int* generateArray(int len){
        srand(time(NULL));
        int* arr = (int*)malloc(sizeof(int) * len);

        for(int i = 0; i < len; ++i){
                arr[i] = rand();
        }

        return arr;
}

int main(int argc, char** argv){

        /* Command line arguments
         * 
         * [Sort -c X Y] - Compare two sorting algorithms
         * -s N - Generate an array of N elements to use in the sorting
         * : means required arguments, :: means optional arguments
         * what about something requiring two arguments?
         * getopt and argp - check out both
         */
        

        return 0;
}

