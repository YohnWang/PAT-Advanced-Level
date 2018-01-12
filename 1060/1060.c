#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int convert(char a[],int n,char c[])
{
    c[0]='0';
    c[1]='.';
    int cnt=2;
    int state=0;
    int power=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(state==0&&a[i]=='0')
            continue;
        else if(state==0&&isdigit(a[i]))
        {
            if(cnt<n)c[cnt++]=a[i];
            state=1;
            power++;
        }
        else if(state==0&&a[i]=='.')
            state=2;
        else if(state==1&&isdigit(a[i]))
        {
            if(cnt<n)c[cnt++]=a[i];
            power++;
        }
        else if(state==1&&a[i]=='.')
            state=3;
        else if(state==2&&a[i]=='0')
            power--;
        else if(state==2&&isdigit(a[i]))
        {
            state=4;
            if(cnt<n)c[cnt++]=a[i];
        }
        else if(state==3)
            {if(cnt<n)c[cnt++]=a[i];}
        else if(state==4)
            {if(cnt<n)c[cnt++]=a[i];}
    }
    if(state==2)
        power=0;
    while(cnt<n)
        c[cnt++]='0';
    c[cnt]='\0';
    return power;
}
void print(char s[],int k)
{
    if(strcmp(s,"0")==0)
        printf("0*10^0");
    else
        printf("%s*10^%d",s,k);
}

int main(int argc,char *argv[])
{
    int n;
    char a[5000],b[5000];
    scanf("%d%s%s",&n,a,b);
    char c[500],d[500];
    int kc=convert(a,n+2,c);
    int kd=convert(b,n+2,d);
    if(kc==kd && strcmp(c,d)==0)
    {
        printf("YES ");
        print(c,kc);
    }
    else
    {
        printf("NO ");
        print(c,kc);
        printf(" ");
        print(d,kd);
    }
}
