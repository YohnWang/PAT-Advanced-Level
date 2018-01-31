#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

double lex(char s[])
{
    int state=0;
    int cnt=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(state==0)
        {
            if(isdigit(s[i])||s[i]=='-')
                state=1;
            else
                return 2000;
        }
        else if(state==1)
        {
            if(isdigit(s[i]))
                state=1;
            else if(s[i]=='.')
                state=2;
            else
                return 3000;
        }
        else if(state==2)
        {
            cnt++;
            if(isdigit(s[i])&&cnt<=2)
                state=2;
            else
                return 4000;
        }
    }
    double r;
    sscanf(s,"%lf",&r);
    return r;
}

int main(int argc,char *argv[])
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    double sum=0;
    for(int i=0;i<n;i++)
    {
        char s[1000];
        scanf("%s",s);
        double r=lex(s);
        if(r>=-1000 && r<=1000)
            sum+=r,cnt++;
        else
            printf("ERROR: %s is not a legal number\n",s);
    }
    if(cnt>1)
        printf("The average of %d numbers is %.2f",cnt,sum/cnt);
    else if(cnt==1)
        printf("The average of 1 number is %.2f",sum);
    else
        printf("The average of 0 numbers is Undefined");
}
