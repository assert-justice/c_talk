#include <stdio.h>

int main(){
    int a = 5;
    int* ap = &a;
    int b = *ap;
    printf("%i\n", a);
    printf("%p\n", ap);
    a++;
    printf("%i\n", b);
    printf("%i\n", *ap);
    return 0;
}