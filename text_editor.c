#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc > 1 && (strcmp(argv[2], "-w") == 0))
    {
        printf("Writing : %s\n", argv[1]);
        FILE *fp = fopen(argv[1], "w");
        int c;
        while ( (c = getc(stdin)) != EOF)
        {
            putc(c, fp);
        }
        fclose(fp);
    }else if (argc > 1 && (strcmp(argv[2], "-r") == 0)) {
        printf("Reading : %s\n", argv[1]);
        FILE *fp = fopen(argv[1], "r");
        int c;
        while ( (c = getc(fp)) != EOF)
        {
            putc(c, stdout);
        }
        fclose(fp);
    }
    return 0;
}
