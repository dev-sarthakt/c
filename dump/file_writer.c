#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "a");
    int c;
    while ((c = getc(stdin)) != EOF)
    {
        putc(c, fp);
    }
    fclose(fp);
    return 0;
}
