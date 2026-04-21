#include <stdio.h>


int main() {
    int a = 10;
    int b = 20;
    int *p = &a;
    *p = 50;
    p = &b;
    *p = *p * 2;
    printf("%d\n%d",a,b);
    return 0;
}