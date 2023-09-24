#include <stdio.h>

void show_bytes(unsigned char *start, size_t len) 
{
    size_t i;
    
    for (i = 0; i < len; i++)
        /* %p:	Print pointer
         * %x:	Print Hexadecimal */
        printf("%p\t0x%.2x\n", start + i, start[i]);
    printf("\n");
}

int main(void)
{
    int x = 15213;
    printf("int x = 15213;\n");
    show_bytes((unsigned char *) &x, sizeof(int));

    return 0;
}
