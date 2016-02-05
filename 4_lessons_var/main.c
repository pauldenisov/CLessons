#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    a=12;
    b=9;

    printf("A=%d, B=%d\n", a, b);
    c=a;
    a=b;
    b=c;

    printf("A=%d, B=%d\n", a, b);
    return 0;
}
