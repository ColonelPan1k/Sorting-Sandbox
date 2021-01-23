/*
 * This is another test program to go along with Timer.c
 * It's probably not good but it's bogosort so what does 
 * it matter. 
 *
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
isSorted(int* data, int len){
        for (int i = 0; i < len - 1; ++i){
                if (!(data[i] < data[i + 1])){
                        return 0;
                }
        }
        return 1;
}

void
shuffle(int* data, int len){
        // i = current position in array
        // shufflePos = position to swap with i
        for (int i = 0; i < len; ++i){
                int shufflePos = rand() % len;
                
                int temp = data[i];
                data[i] = data[shufflePos];
                data[shufflePos] = temp;
        }
}

void
bogosort(int* data, int len){

        while(!(isSorted(data, len))){
                shuffle(data, len);
	}
}
