#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int a1,a2,a3,b1,b2,b3;
    scanf("%d.%d.%d %d.%d.%d",&a1,&a2,&a3,&b1,&b2,&b3);
    int c3=(a3+b3)/29;
    int x3=(a3+b3)%29;
    int c2=(a2+b2+c3)/17;
    int x2=(a2+b2+c3)%17;
    int x1=(a1+b1+c2);
    printf("%d.%d.%d",x1,x2,x3);
}
