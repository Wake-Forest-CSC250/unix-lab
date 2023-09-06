#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int csc250_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    /* a security issue?
     * what happens if a line is bigger than MAXLINE? */
    while ((len = csc250_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            /* function call is still pass-by-value, but...
             * ...when the name of an array is used as an argument,
             * the value passed to the function is the location 
             * or *memory address* of the beginning of the array.
             * there is no copying of array elements!
             * 
             * Hmmm...have you seen this in Java? 
             */
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/* read a line into s, return length */
int csc250_getline(char s[],int lim)
{
    int c, i;
    
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    /* we put the character '\0' (the null character, whose value is zero) 
     * at the end of the array to mark the end of the string of characters.
     * In a C program, a string is stored as an array of characters
     * terminated with a '\0' to mark the end. 
     * See discussion in the Strings section. */
    s[i] = '\0';
    return i;
}

/* copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
