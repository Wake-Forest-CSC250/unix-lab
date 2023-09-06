#include<stdio.h>

int main(void)
{
    /* declare floating point typed variables */
    float single;
    double normal;
    long double extended;

    /* print out their sizes in bytes */
    printf("size of a float value: %zu byte\n", sizeof(single));
    printf("size of a double value: %zu bytes\n", sizeof(normal));
    printf("size of a long double value: %zu bytes\n", sizeof(extended));

    /* floating-point literals are any number with a decimal and/or E (or e) */
    single = 2.0;
    normal = 1e2;
    extended = 1.1E2;

    /* for floating point constants, their type is double, unless suffixed
     * the suffixes f or F indicate a float constant; 
     * l or L indicate a long double. */

    return 0;
}