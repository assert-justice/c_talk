#ifndef D_ARRAY
#define D_ARRAY
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_SIZE 8
#define GROW_RATE 2

typedef struct dArray
{
    size_t length;
    size_t capacity;
    int64_t* data;
} dArray;

static int64_t* allocate(size_t capacity){
    return (int64_t*)calloc(capacity, sizeof(int64_t));
}

static void initArray(dArray* arr){
    arr->length = 0;
    arr->capacity = INITIAL_SIZE;
    arr->data = allocate(INITIAL_SIZE);
}

static void freeArray(dArray* arr){
    free(arr->data);
}

static void pushArray(dArray* arr, int64_t val){
    if(arr->length == arr->capacity){
        // change capacity
        size_t newCapacity = arr->capacity * GROW_RATE;
        int64_t* newData = allocate(newCapacity);
        memcpy(newData, arr->data, arr->capacity * sizeof(uint64_t));
        free(arr->data);
        arr->data = newData;
        arr->capacity = newCapacity;
    }
    arr->data[arr->length] = val;
    arr->length++;
}

static int64_t popArray(dArray* arr){
    if(arr->length == 0){
        return 0;
    }
    arr->length--;
    return arr->data[arr->length + 1];
}

static void printArray(dArray* arr){
    // if(arr->length == 0){
    //     return;
    // }
    size_t i;
    if(arr->length > 0){
        for (i = 0; i < arr->length - 1; i++)
        {
            printf("%I64i, ", arr->data[i]);
        }
        printf("%I64i\n", arr->data[arr->length - 1]);
    }
    printf("len: %I64i, capacity: %I64i\n", arr->length, arr->capacity);
    // printf("%I64i\nlen: %I64i, capacity: %I64i\n", arr->data[i], arr->length, arr->capacity);
}

#endif