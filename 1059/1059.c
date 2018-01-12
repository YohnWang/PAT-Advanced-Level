#include<stdio.h>
#include<stdlib.h>

int prime[100000];
int table[100000];
int cnt;
struct T{int a,n;};
void select()
{
    for(int i=2;i<100000;i++)
        for(int j=i+i;j<100000;j+=i)
            prime[j]=1;
    for(int i=2;i<100000;i++)
        if(prime[i]==0)
            table[cnt++]=i;
}

void print(struct T a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i].a);
        if(a[i].n>1)
            printf("^%d",a[i].n);
        if(i!=n-1)
            printf("*");
    }
}

int main(int argc,char *argv[])
{
    select();
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("%d=%d",n,n);
        return 0;
    }
    int num=n;
    struct T a[10000]={{0,0}};
    int count=0;
    for(int i=0;n!=1&&table[i]<=num;i++)
    {
        while(n%table[i]==0)
        {
            a[count].a=table[i];
            a[count].n++;
            n=n/table[i];
        }
        if(a[count].n)
            count++;
    }
    printf("%d=",num);
    print(a,count);
}
