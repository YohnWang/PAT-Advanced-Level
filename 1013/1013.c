#include<stdio.h>

struct city
{
    int connection[1000];
    int length;
};

struct city city[1000+20];

void dfs(int now,int isvisited[])
{
    if(isvisited[now]!=0)
        return ;
    isvisited[now]=1;

    for(int i=0;i<city[now].length;i++)
        dfs(city[now].connection[i],isvisited);
}

int connect(int isvisited[],int citynum)
{
    int r=0;
    for(int i=1;i<=citynum;i++)
    {
        if(isvisited[i]==0)
        {
            dfs(i,isvisited);
            r++;
        }
    }
    return r;
}

int search(int lost,int city)
{
    int isvisited[1200]={0};
    isvisited[lost]=2;
    return connect(isvisited,city)-1;
}

int main(int argc,char *argv[])
{
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        city[l].connection[city[l].length++]=r;
        city[r].connection[city[r].length++]=l;
    }
    for(int i=0;i<K;i++)
    {
        int c;
        scanf("%d",&c);
        printf("%d\n",search(c,N));
    }
    return 0;
}
