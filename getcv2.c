#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    printf("EOF:%d", EOF);
    char c;
    c = getchar();
    putchar(c);
    //while((c = getchar()) != '\n')
        //printf("%c", c);

    exit(0);
} 
