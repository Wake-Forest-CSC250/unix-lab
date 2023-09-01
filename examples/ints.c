#include <stdio.h>

int main(void)
{
    int x;

    printf("Give me an x: ");
    scanf("%d", &x);
    printf("I will compute x * x = %d\n", x*x);
    printf("No!");

    return 0;
}
