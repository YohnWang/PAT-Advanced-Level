#include<stdio.h>
#include<stdlib.h>

int trans(int a[],int x,int b)
{
    if(x==0)
    {
        a[0]=0;
        return 1;
    }
    int stack[100];
    int top=-1;
    while(x)
    {
        stack[++top]=x%b;
        x/=b;
    }
    int r=top+1;
    for(int i=0;top>=0;i++)
    {
        a[i]=stack[top--];
    }
    return r;
}

int ispal(int a[],int n)
{
    for(int i=0;i<n/2;i++)
    {
        if(a[i]!=a[n-i-1])
            return 0;
    }
    return 1;
}

int main(int argc,char *argv[])
{
    int a[1000];
    int x,b;
    scanf("%d%d",&x,&b);
    int r=trans(a,x,b);

    if(ispal(a,r))
        printf("Yes\n");
    else
        printf("No\n");

    printf("%d",a[0]);
    for(int i=1;i<r;i++)
        printf(" %d",a[i]);
    return 0;
}
