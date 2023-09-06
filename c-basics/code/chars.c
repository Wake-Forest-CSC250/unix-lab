#include <stdio.h>

/* count characters in input */
int main(void)
{
    double nc;

    /* Did you notice that nothing happens on your terminal 
     * when you input from the keyboard until after you hit enter?
     * Why is that? Perhaps some sort of *buffering* is going on?
     */

    for (nc = 0; getchar() != EOF; ++nc)
        /* The body of this for loop is empty, because all the work 
         * is done in the test and increment parts. But the grammatical 
         * rules of C require that a for statement have a body. The isolated
         * semicolon, called a null statement, is there to satisfy that requirement.
         */
        ;
    /* %.0f suppresses the printing of the decimal point 
     * and the fraction part, which is zero
     */
    printf("%.0f\n", nc);
    return 0;
}
