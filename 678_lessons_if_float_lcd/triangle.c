#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    printf("c=");
    scanf("%d", &c);

    if (a+c<b)
    {
        printf("impossible triangle");
    }
    else if (a+b<c)
    {
        printf("impossible triangle");
    }
    else if (b+c<a)
    {
        printf("impossible triangle");
    }
    else
    {
        printf("possible");
        if (a==b && a==c)
        {
            printf(" equilateral");
        }
        else if (a!=b && b!=c && a!=c)
        {
            printf(" obtuse");
        }
        else
        {
            printf(" isoceles");
        }
    }
    return 0;
}
