#include<stdio.h>
#include<stdlib.h>

struct vertex
{
    int n;
    int a[10000];
};
typedef struct vertex vertex;

vertex g[10000+5];
int n;
char   visit[10000+5];

int max=0;
int node[20000];
int count=0;
int xcount=0;
void dfs(int k,int deep)
{
    visit[k]=1;
    if(deep>max)
    {
        max=deep;
        count=xcount;
        node[count++]=k;
    }
    else if(deep==max)
    {
        node[count++]=k;
    }

    for(int i=0;i<g[k].n;i++)
        if(visit[g[k].a[i]]==0)
            dfs(g[k].a[i],deep+1);
}

int find()
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            dfs(i,1);
            count++;
        }
    }
    return count;
}
int comp(const int *a,const int *b)
{
    return *a-*b;
}
int main(int argc,char *argv[])
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].a[g[a].n++]=b;
        g[b].a[g[b].n++]=a;
    }
    int c=find();
    if(c>1)
        printf("Error: %d components",c);
    else
    {
        int s=node[0];
        for(int i=1;i<=n;i++)
            visit[i]=0;
        max=0;
        xcount=count;
        dfs(s,1);
        node[count++]=s;
        qsort(node,count,sizeof(int),comp);
        printf("%d\n",node[0]);
        for(int i=1;i<count;i++)
            if(node[i]!=node[i-1])
                printf("%d\n",node[i]);
    }
}
