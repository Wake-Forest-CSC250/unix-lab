# include <stdio.h>

int main(void)
{
    unsigned int i = 3;
    int decrement = -1;

    while (i >= 0) {
        printf("i: %u\n", i);
        i += decrement;
    }

    return 0;
}
