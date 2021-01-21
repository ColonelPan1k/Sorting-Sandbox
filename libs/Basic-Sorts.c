#include <stdio.h>
#include "Common.h"

void
insertionSort(int* arr, int len){
        int i,j;

        for (int i = 0; i < len - 1; ++i){
                int min = i;

                for (j = i + 1; j < len; ++j){
                        if (arr[j] < arr[min]){
                                min = j;
                        }
                }

                if (min != i){
                        swap(&arr[i], &arr[min]);
                }
        }
}
// This is a test
