#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int table[256];

int main(int argc,char *argv[])
{
    char s1[500],s2[500];
    gets(s1);
    gets(s2);
    for(int i=0;s1[i]!='\0';i++)
        table[s1[i]]=1;
    for(int i=0;s2[i]!='\0';i++)
        table[s2[i]]++;
    for(int i=0;s1[i]!='\0';i++)
    {
        if(table[s1[i]]==1)
        {
            if(isalpha(s1[i]))
            {
                printf("%c",toupper(s1[i]));
                table[s1[i]]=-1;
                if(isupper(s1[i]))
                    table[tolower(s1[i])]=-1;
                else
                    table[toupper(s1[i])]=-1;
            }
            else if(isdigit(s1[i])||s1[i]=='_')
            {
                printf("%c",s1[i]);
                table[s1[i]]=-1;
            }
        }
    }
}
