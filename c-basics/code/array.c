#include <stdio.h>

/* count digits, white space, others */
int main(void)
{
    int c, i, nwhite, nother;
    /* declares ndigit to be an array of 10 integers
     * in C, like in Java, array subscripts always start at zero;
     * a subscript can be any integer expression
     */
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        /* is c a digit? */
        if (c >= '0' && c <= '9')
            /* the numeric value of that digit is: c - '0'
             * because in all cases, a machine's character set
             * has consecutive increasing values 
             * for characters '0' to '9'. 
             */
            ++ndigit[c-'0'];
        /* is c a white space (blank, tab, or newline)? */
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        /* any other characters */
        else
            ++nother;
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}
