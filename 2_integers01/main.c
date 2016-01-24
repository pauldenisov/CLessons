#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Variable declaration */
    int a,b,res;

    /* Variable initialization */
    a=53;
    b=7;

    /* Variable value output */
    printf("A = %d\n", a);
    printf("B = %d\n", b);

    /* Sum operation */
    res=a+b;
    printf("A + B = %d\n", res);

    /* Subtraction operation */
    res=a-b;
    printf("A - B = %d\n", res);

    /* Multiplication operation */
    res=a*b;
    printf("A * B = %d\n", res);

    /* Integer division operation */
    res=a/b;
    printf("A : B = %d\n", res);

    /* ?? operation */
    res=a%b;
    printf("A div B = %d\n", res);

    /* Module (absolute) function */
    res = abs(-10);
    printf("result of module func: %d\n", res);

    /* Square root function */
    res = sqrt(81);
    printf("result of square func: %d\n", res);
    return 0;
}
