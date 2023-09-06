#include <stdio.h>

int main(void) 
{
    /* declare integer and char typed variables */
    char mini;
    short small;
    int normal;
    long large;
    long long xlarge;
    unsigned int u_normal;
    unsigned long u_large;

    /* print out their sizes in bytes (machine-specific) 
     * use the %zu format specifier to print the values
     * we will talk about format specifiers in a different code
     * example, but you should have learned something similar
     * in Java already.
     * 
     * sizeof() will return a value of type "size_t"
     */
    printf("size of a char integer: %zu byte\n", sizeof(mini));
    printf("size of a short integer: %zu bytes\n", sizeof(small));
    printf("size of an int integer: %zu bytes\n", sizeof(normal));
    printf("size of a long integer: %zu bytes\n", sizeof(large));
    printf("size of a long long integer: %zu bytes\n", sizeof(xlarge));

    /* integer literals could be represented in different bases */
    small = 45;     /* Base 10 (decimal) contains either a single digit 
                     * between 0 - 9 or multiple digits start from 1 - 9. 
                     */
    normal = 045;   /* Base 8 (octal) starts with 0 and the second digit
                     * must be between 1 - 7.
                     *
                     * TODO: What is this value in decimal?
                     */
    large = 0xA5F6; /* Base 16 (hexadecimal) starts with 0x 
                     * and the remaining digits are 0-9 or A-F
                     *
                     * TODO: What is this value in decimal?
                     */
    
    /* a char literal is any single character within single quotes 
     * a single character can be a single letter, a single number, 
     * a symbol, or a control character.
     * the value of a character constant is the numeric value of 
     * the character in the machine's character set.
     * character constants participate in numeric operations 
     * just as any other integers, but they are most often used 
     * in comparisons with other characters.
     */
    mini = 'A';
    /* in ASCII, the character A's bit pattern is 01000001
     * you should have learned something similar in Java already
     * we will learn more about data representation in the future
     */
    printf("'%c' is also the integer number %d\n", mini, (int) mini);

    /* ways to represent integer constants */
    large =  45L;           /* a long constant is written with a terminal l or L */
    xlarge = 1563ll;        /* you can use ll or LL for a long long constant */
    u_normal = 45u;         /* unsigned constants are written with a terminal u or U */ 
    u_large = 3455339UL;    /* the suffix ul or UL indicates unsigned long */
    /* octal and hexadecimal constants may also be followed by L 
     * to make them long and U to make them unsigned
     */

    return 0;
}
