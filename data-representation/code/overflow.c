#include <stdio.h>
#include <limits.h>

int main(void)
{
    /* Let's print the size of an unsigned int on my machine. */
    printf("The size of unsigned int is %lu bytes.\n", sizeof(unsigned int));

    unsigned int value = UINT_MAX;  /* This macro is defined in limits.h */
    printf("The maximum unsigned int value is: %u\n", value);

    /* Now we create chaos, a.k.a., overflow. */
    value += 1;
    printf("After adding 1 to the maximum unsigned int value, we get: %u\n", value);

    /* We can create chaos in the opposite direction. */
    value = 0;                      /* Smallest unsigned int value is 0. */
    value -= 1;
    printf("After subtracting 1 to the minimum unsigned int value, we get: %u\n", value);

    return 0;
}
