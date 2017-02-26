#include<stdio.h>
#include<ctype.h>
#include<string.h>
char* __strrev(char *s)
{
    int len=strlen(s);
    for(int i=0; i<len/2; i++)
    {
        char tmp=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=tmp;
    }
    return s;
}
int main(int argc,char *argv[])
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int c=a+b;
        char s[1000],ss[1000];
        sprintf(s,"%d",c);
        int cnt=0;
        int k=0;
        for(int i=strlen(s)-1; i>=0; i--)
        {
            if(cnt==3 && isdigit(s[i]))
            {
                ss[k++]=',';
                cnt=0;
            }
            if(isdigit(s[i]))
                cnt++;
            ss[k++]=s[i];
        }
        ss[k++]='\0';
        printf("%s\n",__strrev(ss));
    }
    return 0;
}
