#include<stdio.h>

int main(void)
{
    int a;
    int b;

    a = 5;
    b = -3;
    printf("%d %% %d = %d\n", a, b, a % b);

    a = -5;
    b = 3;
    printf("%d %% %d = %d\n", a, b, a % b);

    return 0;

    /* Take a look at the output of the execution.
     * It turns out that the C standard requires that
     * (a/b) * b + a%b = a 
     * So in the first example, we know that a/b = -1,
     * then (a/b) * b = -3, and a = 5
     * so (-1) * (-3) + a%b = 5, which means that a%b must be 2.
     * */
}
