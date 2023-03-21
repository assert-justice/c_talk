#ifndef D_ARRAY
#define D_ARRAY
#include <stdlib.h>
// #include <stdint.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_SIZE 8
#define GROW_RATE 2

typedef struct dArray
{
    size_t length;
    size_t capacity;
    int* data;
} dArray;

static int* allocate(size_t capacity){
    return (int*)calloc(capacity, sizeof(int));
}

static void initArray(dArray* arr){
    arr->length = 0;
    arr->capacity = 0;
    arr->data = NULL;// allocate(INITIAL_SIZE);
}

static void freeArray(dArray* arr){
    if(arr->data != NULL) free(arr->data);
}

static void pushArray(dArray* arr, int val){
    if(arr->length == arr->capacity){
        // change capacity
        size_t newCapacity = arr->capacity == 0 ? INITIAL_SIZE : arr->capacity * GROW_RATE;
        int* newData = allocate(newCapacity);
        memcpy(newData, arr->data, arr->capacity * sizeof(int));
        free(arr->data);
        arr->data = newData;
        arr->capacity = newCapacity;
    }
    arr->data[arr->length] = val;
    arr->length++;
}

static int popArray(dArray* arr){
    if(arr->length == 0){
        return 0;
    }
    arr->length--;
    return arr->data[arr->length + 1];
}

static void printArray(dArray* arr){
    size_t i;
    if(arr->length > 0){
        for (i = 0; i < arr->length - 1; i++)
        {
            printf("%i, ", arr->data[i]);
        }
        printf("%i\n", arr->data[arr->length - 1]);
    }
    int cap = (int)arr->capacity;
    int len = (int)arr->length;
    printf("len: %i, capacity: %i\n", len, cap);
}

#endif