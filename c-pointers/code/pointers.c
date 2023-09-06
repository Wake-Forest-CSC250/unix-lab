#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

int main(void)
{
    int x = 1, y = 2, z[10];
    int *ip;    /* ip is a pointer to int */
    
    ip = &x;    /* ip now points to x */
    printf("The int variable x's address is: %p\n", (void *) ip);
    y = *ip;    /* y is now 1 */
    printf("The int variable y's value is: %d\n", y);
    *ip = 0;    /* x is now 0 */
    *ip += 1;   /* x is now back to 1 */
    ++*ip;      /* x is now 2 */
    /* The parentheses are necessary in this next line of code; 
     * without them, the expression would increment ip instead of 
     * what it points to, because unary operators like * and ++ 
     * associate right to left.
     */
    (*ip)++;    /* x is now 3 */
    printf("The int variable x's value is: %d\n", x);
    ip = &z[0]; /* ip now points to z[0] */

    void *ptr = malloc(sizeof(int));
    uintptr_t addr = (uintptr_t) ptr;
    void *ptr2 = (void *) addr;
    assert(ptr == ptr2);

    return 0;
}
