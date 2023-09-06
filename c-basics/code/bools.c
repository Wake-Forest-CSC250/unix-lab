#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool b;

    b = true;
    if (b) {
        printf("We can use bool if we include <stdbool.h>!\n");
    }

    return 0;
}
