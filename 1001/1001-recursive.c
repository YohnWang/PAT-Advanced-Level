#include<stdio.h>
#include<stdlib.h>

void print(int x)
{
    if(x==0)
        return ;
    if(abs(x)<1000)
        printf("%d",x);
    else
    {
        print(x/1000);
        printf(",%.3d",abs(x%1000));
    }
}

int main(int argc,char *argv[])
{
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a+b;
    if(c==0)
        printf("%d",c);
    else
        print(c);
}
