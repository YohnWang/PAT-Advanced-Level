#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void print(char s[],int d)
{
    if(s[0]=='-')
        printf("-");
    if(d<0)
    {
        printf("0.");
        d++;
        while(d++)
            printf("0");
        for(int i=1;s[i]!='\0';i++)
            if(isdigit(s[i]))
                printf("%c",s[i]);
    }
    else
    {
        int cnt=0;
        printf("%c",s[1]);
        int i;
        for(i=3;cnt<d&&s[i]!='\0';i++)
        {
                printf("%c",s[i]);
                cnt++;
        }
        while(s[i]=='\0'&&cnt<d)
        {
            printf("0");
            cnt++;
        }
        if(s[i]!='\0')
            printf(".");
        while(s[i]!='\0')
            printf("%c",s[i++]);
    }
}

int main(int argc,char *argv[])
{
    char s[11000];
    int d;
    scanf("%[^E]E%d",s,&d);
    print(s,d);
}
