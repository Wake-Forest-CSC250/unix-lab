#define _GNU_SOURCE 1
#include <math.h>
#include <stdio.h>

int main(void) 
{
    float a = 0.1;
    float b = 0.2;
    printf ("0.1 + 0.2 = %.8f\n", a + b);

    double a_d = 0.1;
    double b_d = 0.2;
    printf ("0.1 + 0.2 = %.17f\n", a_d + b_d);

    if (a_d + b_d == 0.3)
        printf ("%f + %f == 0.3\n", a_d, b_d);
    else
        printf ("%f + %f != 0.3\n", a_d, b_d);

    printf("Positive infinity: %f\n", INFINITY);
    printf("Not a number: %f\n", NAN);
    printf("The size of a long double: %zu\n", sizeof(long double));

    printf("Single-precision: ( 3.14 + 1e20 ) - 1e20 = %.2f\n", (3.14f+1e20f)-1e20f);
    printf("Double-precision: ( 3.14 + 1e10 ) - 1e10 = %.2f\n", (3.14+1e10)-1e10);
    printf("Single-precision: 3.14 + ( 1e20  - 1e20 ) = %.2f\n", 3.14f+(1e20f-1e20f));
    printf("Double-precision: 3.14 + ( 1e10  - 1e10 ) = %.2f\n", 3.14+(1e10-1e10));

    printf("Single-precision: 1e20 * ( 1e20 - 1e20 ) = %.2f\n", 1e20f*(1e20f-1e20f));
    printf("Double-precision: 1e20 * ( 1e20 - 1e20 ) = %.2f\n", 1e20*(1e20-1e20));
    printf("Single-precision: 1e20 * 1e20 - 1e20 * 1e20 = %.2f\n", 1e20f*1e20f-1e20f*1e20f);
    printf("Double-precision: 1e20 * 1e20 - 1e20 * 1e20 = %.2f\n", 1e20*1e20-1e20*1e20);



    return 0;
}
