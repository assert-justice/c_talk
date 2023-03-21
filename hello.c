#include <stdio.h>
#include "d_array.h"

int main(){
    dArray arr;
    initArray(&arr);
    // pushArray(&arr, 0);
    size_t i;
    size_t loops = 20;
    for (i = 0; i < loops; i++)
    {
        pushArray(&arr, i);
    }
    for (i = 0; i < loops; i++)
    {
        popArray(&arr);
    }
    arr.length = loops;
    printArray(&arr);
    freeArray(&arr);
    // int nums[] = {3, 5, 6, 11, 2};
    // for(int i = 0; i < 5; i++){
    //     printf("%i\n", nums[i]);
    // }
    return 0;
}