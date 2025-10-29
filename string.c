#ifndef STRING_C
#define STRING_C

//strcomp
int strcomp(char *str, char *src){
    for (; (*str == *src) && (*str != '\0' && *src != '\0'); str++, src++)
    {
        ;
    }
    if (*str < *src)
    {
        return -1;
    }else if (*str > *src)
    {
        return 1;
    }else {
        return 0;
    }
}

//strlength
int strlength(char *str){
    int i;
    for (i = 0; *str != '\0'; i++, str++)
    {
        ;
    }
    return i;
}

#endif
