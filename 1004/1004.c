#include<stdio.h>
#include<stdlib.h>

struct node
{
    int children[100];
    int n;
}c[102];
int put[100];
int deep=0;

int dfs(int current,int floor)
{
    if(c[current].n==0)
    {
        put[floor]++;
        if(floor>deep)
            deep=floor;
    }
    else
    {
        for(int i=0;i<c[current].n;i++)
            dfs(c[current].children[i],floor+1);
    }
}

int main(int argc,char *argv[])
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        int now,k;
        int id,cnt=0;
        scanf("%d%d",&now,&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&id);
            c[now].children[cnt++]=id;
        }
        c[now].n=cnt;
    }
    dfs(1,0);
    printf("%d",put[0]);
    for(int i=1;i<=deep;i++)
        printf(" %d",put[i]);
    return 0;
}
