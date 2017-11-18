#include<stdio.h>
#include<stdlib.h>

char s[200000];
long long int count=0;

int main(int argc,char *argv[])
{
    scanf("%s",s);
    int P=0,A=0,T=0;
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]=='T')
            T++;
    }
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]=='P')
            P++;
        else if(s[i]=='T')
            T--;
        else if(s[i]=='A')
        {
            count=((P*T)+count)%1000000007;
        }
    }
    printf("%d",(int)count);
}
