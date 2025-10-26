#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

char *word(){
    char c, *pword, *pwordcpy;
    for (pword = pwordcpy = (char *) malloc(sizeof(char *)); (c = getchar()) != EOF && c != '\n' && c != '\0'; pword++)
    {
        *pword = c;
    }
    if (c == '\n')
    {
        *pword = '\n';
        pword++;
    }
    *pword = '\0';
    return pwordcpy;
}

int main(){
    char *para[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++)
    {
        para[i] = word();
    }
    printf("\n");
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("%s", para[i]);
    }
    for (int i = 0; i < MAXSIZE; i++)
    {
        free(para[i]);
    }
    return 0;
}
