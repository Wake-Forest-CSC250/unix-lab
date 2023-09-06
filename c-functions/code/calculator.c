#include <stdio.h>

#define MAXLINE 100

/* a simple calculator */
int main(void)
{
    /* The declaration here says that:
     * 1. sum is a double variable
     * 2. atof is a function that takes one char[] argument and returns a double
     */
    /* The function atof must be declared and defined consistently. 
     * If atof itself and the call to it in main have inconsistent types 
     * in the *same source file* (which is not the case here), 
     * the error will be detected by the compiler. 
     * But if (as is more likely) atof were compiled separately, 
     * like in this case, the mismatch would not be detected, 
     * atof would return a double that main would treat as an int, 
     * and meaningless answers would result!
     * 
     * Note also that *implicit declaration* of a function is invalid in C99!
     * Implicit declaration is when a name that has not been previously declared (say atof)
     * occurs in an expression (sum += atof(line) in the while loop) 
     * and is followed by a left parentheses -- in older versions of C,
     * it is declared by context to be a function name,
     * the function is assumed to return an int, and nothing is assumed about its arguments.
     * This is no longer allowed in newer versions of C for safety.
     * -*-*-* NO IMPLICIT DECLARATION *-*-*-
     * Rule of Thumb: 
     * Always explicit declare a function - and -
     * if the function takes arguments, declare them; if it takes no arguments, use void.
     */
    double sum, atof(char []);
    char line[MAXLINE];
    int csc250_getline(char line[], int max);

    sum = 0;
    while (csc250_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    
    return 0;
}
