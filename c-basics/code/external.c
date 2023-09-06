/* program layout: includes */
#include <stdio.h>

/* program layout: symbolic constant definitions */
#define MAXLINE 1000    /* maximum input line size */

/* program layout: global/external variables */
int max;                /* maximum length seen so far */
char line[MAXLINE];     /* current input line */
char longest[MAXLINE];  /* longest line saved here */

/* program layout: function declarations */
/* also called function prototypes, which must agree with the definitions
 * of the same functions below and the uses of these functions.
 * in a function prototype, parameter names are optional and need not agree,
 * but well-chosen names are good documentation */
int csc250_getline(void);
void copy(void);

/* program layout: function definitions
 * main is often the first definition followed by other functions
 */
/* print longest input line 
 * TIP: you can run this code by typing in text in the command line;
 *      once you are done, you should enter CTRL+D to input EOF (end-of-file).
 */
int main(void)
{
    int len;
    /* Before a function can use an external variable, the name
     * of the variable must be made known to the function; 
     * the declaration is the same as before except for the added keyword extern.
     * 
     * In certain circumstances, the extern declaration can be omitted.
     * If the definition of the external variable occurs in the source file 
     * before its use in a particular function, then there is no need 
     * for an extern declaration in the function.
     * The extern declarations in main, csc250_getline and copy are thus redundant.
     * Common practice is to place definitions of all external variables 
     * at the beginning of the source file, and then omit all extern declarations.
     * 
     * If the program is in several source files,
     * the usual practice is to collect extern declarations of variables and functions 
     * in a separate file, historically called a *header*, 
     * that is included by #include at the front of each source file. 
     * The suffix .h is conventional for header names.
     * We will discuss header files in the future.
     */
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = csc250_getline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)        /* there was a line */
        printf("%s", longest);
    return 0;
}

/* our CSC250 version of getline to get a line of text */
int csc250_getline(void)
{
    int c, i;
    extern char line[];
    /* EOF is an integer defined in <stdio.h> 
     * Notice here that c is of type int, not char.
     * This is because c must be big enough to hold EOF 
     * in addition to any possible char (EOF should not be confused
     * with any real character).
     * The specific numeric value of EOF doesn't matter 
     * as long as it is not the same as any char value.
     * 
     * Notice also that any assignment is an expression and has a value, 
     * which is the value of the left hand side after the assignment.
     * This means that a assignment can appear as part of a larger expression.
     * This is why we can have c=getchar() in the for loop, because it
     * simply returns the value being assigned to c.
     * 
     * The parentheses around the assignment (c=getchar()) are necessary
     * because the precedence of != is higher than that of =
     * (do you still remember the notion of precedence?)
     */
    for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy a line of text considered to be the longest to a separate storage space */
void copy(void)
{
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
