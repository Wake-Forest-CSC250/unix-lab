#include <stdio.h>

int main(void)
{
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                /* Just like in Java, the break statement causes an immediate exit from the switch. 
                 * Because cases serve just as *labels*, after the code for one case is done, 
                 * execution falls through to the next unless you take explicit action to escape.
                 */
                break;
            /* Falling through cases is a mixed blessing. On the positive side, 
             * it allows several cases to be attached to a single action, as in this example.
             * Falling through from one case to another is not robust, 
             * being prone to disintegration when the program is modified.
             * With the exception of multiple labels for a single computation, 
             * fall-throughs should be used sparingly, and commented.
             */
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            /* As a matter of good form, put a break after the last case (the default here) even though it's
             * logically unnecessary. Some day when another case gets added at the end, this bit of 
             * *defensive programming* will save you.
             * */
            default:
                nother++;
                break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}
