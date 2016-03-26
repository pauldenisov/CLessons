#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=1;
    int s=1;
    while ( c <= 10 ) {
        while ( s <= c ) {
            printf("* ");
            s=s+1;
        }
        printf("\n");
        c=c+1;
        s=1;
    }
    printf("C is bigger than 10, C=%d",c);
    return 0;
}
