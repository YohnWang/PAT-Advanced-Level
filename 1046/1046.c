#include<stdio.h>
#include<stdlib.h>

int A[100010];
int B[100010];
int n;

int main(int argc,char *argv[])
{
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
        sum+=A[i];
    }
    int tmp=0;
    for(int i=2;i<=n;i++)
    {
        tmp+=A[i-1];
        B[i]=tmp;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
        {
            int tmp=a;
            a=b;
            b=tmp;
        }
        int l=B[b]-B[a];
        int r=sum-l;
        printf("%d\n",l<r?l:r);
    }
}
