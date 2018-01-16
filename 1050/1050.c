#include<stdio.h>
#include<stdlib.h>
char table[256];

void get_table()
{
    int c;
    while((c=getchar())!=EOF)
        table[c]=1;
}

void set_s(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(table[s[i]]==1)
            s[i]=-1;
    }
}

void prints(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=-1)
            printf("%c",s[i]);
    }
}

int main(int argc,char *argv[])
{
    char s[20000];
    gets(s);
    get_table();
    set_s(s);
    prints(s);
}
