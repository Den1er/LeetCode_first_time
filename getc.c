#include <stdio.h>
#include <stdlib.h>
int
main(void)
{
    int c;
    printf("buffer_size: %d\n", BUFSIZ);
    while((c = getc(stdin)) != EOF){
        fflush(stdin);

        fflush(stdout);
        printf("%c\n", c);
        /*if(putc(c, stdout) == EOF)
            printf("output err");
            */
    }
    if(ferror(stdin))
        printf("input error");

    exit(0);
}
