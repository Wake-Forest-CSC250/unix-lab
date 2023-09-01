#define _GNU_SOURCE 1
#include <math.h>
#include <stdio.h>

int main(void) 
{
    printf("( 3.14 + 1e10 ) - 1e10 = %.2f\n", (3.14f+1e10f)-1e10f);
    printf("3.14 + ( 1e10  - 1e10 ) = %.2f\n", 3.14f+(1e10f-1e10f));

    return 0;
}
