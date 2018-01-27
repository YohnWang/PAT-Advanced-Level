#include<stdio.h>
#include<stdlib.h>

long long int calc(int begin,int n)
{
    long long int pr=1;
    for(int i=begin;i-begin<n;i++)
        pr*=i;
    return pr;
}

void print(int i,int j)
{
    printf("%d",i);
    for(int k=i+1;k<=j;k++)
        printf("*%d",k);
}

int main(int argc,char *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i=12;i>=1;i--)
    {
        for(long long int j=2;j*j<=n;j++)
        {
            long long int pr=calc(j,i);
            if(n%pr==0)
            {
                printf("%d\n",i);
                print(j,j+i-1);
                return 0;
            }
        }
    }
    printf("%d\n",1);
    printf("%d",n);
}
