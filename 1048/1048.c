#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    const int *x=a;
    const int *y=b;
    return *x-*y;
}
int bfind(int a[],int begin,int end,int x)
{
    while(begin<=end)
    {
        int center=(begin+end)/2;
        if(x<a[center])
            end=center-1;
        else if(x>a[center])
            begin=center+1;
        else
            return center;
    }
    return -1;
}
int main(int argc,char *argv[])
{
    int a[100100];
    int n,dest;
    scanf("%d%d",&n,&dest);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++)
    {
        int diff=dest-a[i];
        int k=bfind(a,i+1,n-1,diff);
        if(k!=-1)
        {
            printf("%d %d",a[i],diff);
            return 0;
        }
    }
    printf("No Solution");
}
