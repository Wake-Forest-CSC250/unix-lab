#include <stdio.h>

int main(void)
{
    char amessage[] = "hello, world!\n";
    char *pmessage = "hello, world!\n";

    amessage[5] = '!';
    /* You cannot do the following, which would lead to a bus error: */
    /* *(pmessage + 5) = '!'; */

    printf("amessage prints: %s", amessage);
    printf("pmessage prints: %s", pmessage);

    return 0;
}

/* copy t to s; array subscript version 
 * Note that you cannot copy the string t to s by using s = t,
 * because then you will be copying only the pointer, not the characters!
 */
void astrcpy(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* copy t to s; pointer version */
void pstrcpy(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
/* copy t to s; pointer version 2 
 * Experienced C programmers would prefer this version,
 * The value of *t++ is the character that t pointed to 
 * before t was incremented; the postfix ++ doesn't change t 
 * until after this character has been fetched.
 * In the same way, the character is stored into the old s position 
 * before s is incremented. This character is also the value 
 * that is compared against '\0' to control the loop.
 */
void pstrcpy2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

/* As the final abbreviation, observe that a comparison against '\0' is redundant, 
 * since the question is merely whether the expression is zero.*/
/* copy t to s; pointer version 3 */
void pstrcpy3(char *s, char *t)
{
    while ((*s++ = *t++))   /* use an additional set of parentheses to avoid the warning: 
                             * using the result of an assignment as a condition without parentheses. 
                             * This is a good practice because doing so sends a clear signal 
                             * to the compiler that we want to use an assignment in the conditional, 
                             * and not because we accidentally forgot an extra equals sign.
                             */
        ;
}

/* strcmp(s,t), which compares the character strings s and t, 
 * and returns negative, zero or positive if s is 
 * lexicographically less than, equal to, or greater than t. 
 * The value is obtained by subtracting the characters at the first position where s and t disagree.
 */
/* return <0 if s<t, 0 if s==t, >0 if s>t: array version */
int astrcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* return <0 if s<t, 0 if s==t, >0 if s>t: pointer version */
int pstrcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
/* The standard idiom for pushing and popping a stack:
 * *p++ = val; // push val onto stack
 * val = *--p; // pop top of stack into val
 */

/* The strcpy in the standard library (<string.h>) returns the target string as its function value. */
