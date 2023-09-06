#include <stdio.h>

int main(void)
{
    int x;
    int m;
    double d;
    char s[] = "Hello World";
    char dest[100];

    x = 145;
    printf("%4d\n", x);     /* > 145 */
    printf("%2d\n", x);     /* >145 */
    printf("%.5d\n", x);    /* >00145 */
    
    d = 12345.6789;
    printf("%15f\n", d);    /* >   12345.678900 */
    printf("%-15f\n", d);   /* >12345.678900    */
    printf("%10.3f\n", d);  /* > 12345.679 */
    printf("%6.7f\n", d);   /* >12345.6789000 */

    printf("%s\n", s);      /* >Hello World */
    printf("%10s\n", s);    /* >Hello World */
    printf("%.10s\n", s);   /* >Hello Worl */
    printf("%-10s\n", s);   /* >Hello World */
    printf("%.15s\n", s);   /* >Hello World */
    printf("%-15s\n", s);   /* >Hello World     */
    printf("%15.10s\n", s); /* >     Hello Worl */
    printf("%-15.10s\n", s);/* >Hello Worl      */

    /* Good to Know: */
    m = 5;
    /* A width or precision may be specified as *, 
     * in which case the value is computed by
     * converting the next argument (which must be an int). 
     */
    printf("%.*s\n", m, s); /* >Hello */

    /* Good to Know: */
    /* The function sprintf does the same conversions 
    * as printf does, but stores the output in a string
    * instead of the standard output, and the string 
    * (which is the first parameter) must be big enough 
    * to receive the result!
    */
    sprintf(dest, "%s!\n", s);
    printf("%s", dest);     /* >Hello World! */

    /* Use %zu for size_t */

    return 0;
}
