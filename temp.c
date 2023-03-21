#include <stdio.h>

void double_all(int* nums, int len){
    for(int i = 0; i < len; i++){
        nums[i] *= 2;
    }
}

int main(){
    int len = 5;
    int nums[] = {3, 5, 6, 11, 2};
    double_all(nums, len);
    for(int i = 0; i < len; i++){
        printf("%i\n", nums[i]);
    }
    return 0;
}