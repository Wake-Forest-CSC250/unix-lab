#include <stdio.h>

int foo(int index) 
{
    /* volatile tells the compiler not to optimize anything 
     * that has to do with the volatile variable. */
    volatile int iList[2] = {0x12345678};
    volatile char cList[2];
    cList[index] = 0xAA;
    return iList[0];
}

int main(void)
{
    int i, rc;
    for (i = 0; i < 100; ++i) {
        rc = foo(i);
        printf("foo(%d) returns: %x\n", i, rc);
    }

    return 0;
}
