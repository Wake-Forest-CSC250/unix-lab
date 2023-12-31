#include <stdio.h>

#define MAXLINE 1000                    /* maximum input line length */

int strindex(char source[], char searchfor[]);

char pattern[] = "ould";                /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int csc250_getline(char line[], int max);

    while (csc250_getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    /* return the number of matches found. 
     * this value is available for use by 
     * the environment that called the program.
     */
    return found;
}

/* return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
