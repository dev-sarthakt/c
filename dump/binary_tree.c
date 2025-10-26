#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode
{
    char *word;
    int cnt;
    struct tnode *left, *right;
};

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_(char *s){
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
}

struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    if (p == NULL)
    {
        p = talloc();
        p->word = strdup_(w);
        p->cnt = 1;
        p->left = p->right = NULL;
    }else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->cnt++;
    }else if(cond < 0){
        p->left = addtree(p->left, w);
    }else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(struct tnode *p){
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->cnt, p->word);
        treeprint(p->right);
    }
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getchar()))
        ;   // skip whitespace

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        c = getchar();
        if (!isalnum(c)) {
            ungetc(c, stdin);
            break;
        }
        *w = c;
    }
    *w = '\0';
    return word[0];
}

int main(void) {
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word);
    }

    treeprint(root);
    return 0;
}
