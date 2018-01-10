#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    const int *x=a;
    const int *y=b;
    return *x-*y;
}

int output[201];
int nend;

void dfs(int a[],int n,int k,int count,int index,int dest)
{
    count+=a[k];
    if(count==dest)
    {
        output[index]=a[k];
        nend=index+1;
        printf("%d",output[0]);
        for(int i=1;i<nend;i++)
            printf(" %d",output[i]);
        exit(0);
    }
    else if(count<dest)
    {
        output[index]=a[k];
        for(int i=k+1;i<n;i++)
            dfs(a,n,i,count,index+1,dest);
    }
}

int main(int argc,char *argv[])
{
    int a[10010];
    int n,dest;
    scanf("%d%d",&n,&dest);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=x;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++)
        dfs(a,n,i,0,0,dest);
    printf("No Solution");
}
