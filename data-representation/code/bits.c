#include <stdio.h>
#include <string.h>

void xor_cipher(char *message, char key)
{
    size_t i;

    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key;
    }
}

int main(void) 
{
    short int a, b, c, x, i;

    /* Let's print the size of a short int on my machine. */
    printf("The size of short int is %lu bytes.\n", sizeof(short));

    a = 26;   /* 00000000 00011010 */
    b = 54;   /* 00000000 00110110 */

    /* bitwise AND & */
    printf("26 & 54 = %d\n", a & b);
    /* logical AND && */
    printf("26 && 54 = %d\n", a && b);
    /* bitwise OR | */
    printf("26 | 54 = %d\n", a | b);
    /* logical OR || */
    printf("26 || 54 = %d\n", a || b);
    /* bitwise XOR ^ */
    c = a ^ b;
    printf("c = 26 ^ 54 = %d\n", c);
    printf("c ^ 54 = %d\n", c ^ b);
    printf("c ^ 26 = %d\n", c ^ a);
    /* bitwise NOT ~ */
    printf("~26 = %d\n", ~a);


    /* xor cipher example */
    char message[] = "hello";
    char key = 31;
    printf("original message: %s\n", message);
    xor_cipher(message, key);
    printf("encoded message: %s\n", message);
    xor_cipher(message, key);
    printf("decoded message: %s\n", message);

    /* left shift << */
    printf("26 << 3 = %d\n", a << 3);

    /* Left-shift n times can have the effect of multiplying by 2^n, as long as no overflow */
    a = 2;
    for (i = 1; i < 5; i++)
        printf("%d << %i = %d\n", a, i, a << i);
    x = a << 14;
    printf("%d << 14 = %d\n", a, x);

    a = 26;
    /* right shift >> */
    printf("26 >> 3 = %d\n", a >> 3);

    /* Left-shift n times can have the effect of integer-division by 2^n, as long as no overflow */
    a = 32;
    for (i = 1; i < 6; i++)
        printf("%d >> %i = %d\n", a, i, a >> i);
    /* Note the effect of right-shift when shifting a non-multiple of 2 */
    a = 35;
    for (i = 1; i < 6; i++)
        printf("%d >> %i = %d\n", a, i, a >> i);

    x = 0x34C2;
    printf("Original x: %d\n", x);
    /* The bit positions that have been vacated by the shift operation are zero-filled. 
     * A left shift is a logical shift (the bits that are shifted off the end are discarded, including the sign bit). */
    printf("Original x << 2: %d\n", x << 2);    /* If you left-shift a signed number so that the sign bit is affected, the result is undefined. */


    return 0;
}
