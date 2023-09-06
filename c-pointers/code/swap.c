#include <stdio.h>

void swap1(int, int);
void swap2(int*, int*);

int main(void)
{
    int a, b;

    a = 1;
    b = 2;
    swap1(a, b);
    printf("a = %d, b = %d\n", a, b);
    swap2(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

/* Because of call by value, swap1 cannot affect the arguments a and b 
 * in the main routine above that called it.
 * The function swap1(a, b) swaps copies of a and b.
 */
void swap1(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

/* Since the operator & produces the address of a variable (see the swap2 function call
 * above in the main routine), &a is a pointer to a. In swap2 itself, the parameters are 
 * declared as pointers, and the operands are accessed indirectly through them.
 */
void swap2(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
