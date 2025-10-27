#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc > 1 && (strcmp(argv[2], "-w") == 0))
    {
        printf("\nWriting : %s\n", argv[1]);
        FILE *fp = fopen(argv[1], "w");
        int c, i = 0;
        printf("\n%d. ", i++);
        while ((c = getc(stdin)) != EOF)
        {
            if (c == '\n')
            {
                printf("%d. ", i++);
            }
            putc(c, fp);
        }
        if (c == EOF)
        {
            printf("\r   \n");
        }
        fclose(fp);
    }else if (argc > 1 && (strcmp(argv[2], "-a") == 0))
    {
        int c, i = 0;
        printf("\nAppending : %s\n", argv[1]);
        FILE *fp = fopen(argv[1], "r");
        while ( (c = getc(fp)) != EOF)
        {
            if (c == '\n')
            {
                i++;
            }
        }
        fclose(fp);
        fp = fopen(argv[1], "a");
        printf("\n%d. ", i++);
        while ((c = getc(stdin)) != EOF)
        {
            if (c == '\n')
            {
                printf("%d. ", i++);
            }
            putc(c, fp);
        }
        if (c == EOF)
        {
            printf("\r   \n");
        }
        fclose(fp);
    }else if (argc > 1 && (strcmp(argv[2], "-r") == 0)) {
        printf("\nReading : %s\n", argv[1]);
        FILE *fp = fopen(argv[1], "r");
        int c, i = 0;
        printf("\n%d. ", i++);
        while ((c = getc(fp)) != EOF)
        {
            if (c == '\n')
            {
                printf("\n%d. ", i++);
                continue;
            }
            putc(c, stdout);
        }
        if (c == EOF)
        {
            printf("\r   \n");
        }
        
        fclose(fp);
    }
    return 0;
}
