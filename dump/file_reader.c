#include <stdio.h>

void filecpy(FILE *ifp, FILE *ofp){
    int c;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
}

int main(int argc, char *argv[]){
    FILE *fp;
    if (argc == 1)
    {
        filecpy(stdin, stdout);
    }else{
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("cat: can't open %s\n", argv);
                return 1;
            }else{
                filecpy( fp, stdout);
                fclose(fp);
                putc(10, stdout);
            }
        }
    }
    return 0;
}
