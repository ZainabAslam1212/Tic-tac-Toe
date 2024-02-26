#include<stdio.h>

int strlen(const char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}
int main()
{
    char s[100];
    printf("Enter a string :");
    gets(s);
    printf("length of %s is %d",s,strlen(s));
    return 0;
}
//this gives length of string

