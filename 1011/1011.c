#include<stdio.h>
char cc;
double max(double a,double b,double c)
{
    if(a>b)
    {
        if(a>c)
        {
            cc='W';
            return a;
        }
        else
        {
            cc='L';
            return c;
        }
    }
    else
    {
        if(b>c)
        {
            cc='T';
            return b;
        }
        else
        {
            cc='L';
            return c;
        }
    }
}


int main(int argc,char *argv[])
{
    double a,b,c;
    double x;
    scanf("%lf%lf%lf",&a,&b,&c);
    x=max(a,b,c);
    printf("%c",cc);
    scanf("%lf%lf%lf",&a,&b,&c);
    x*=max(a,b,c);
    printf(" %c",cc);
    scanf("%lf%lf%lf",&a,&b,&c);
    x*=max(a,b,c);
    printf(" %c",cc);
    x=(x*0.65-1)*2;
    printf(" %.2f",x);
    return 0;
}
