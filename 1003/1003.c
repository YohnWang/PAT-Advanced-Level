#include<stdio.h>
#include<stdlib.h>

struct city
{
    int other[600];
    int other_num;
    int length[600];
    int rescue_team;
}c[600]={{{0},0,{0},0}};

static int isvisited[600]={0};
static int shortest=0x7fffffff;
static int maximum=0;
static int counter=0;

void dfs(int current,int target,int distance,int teams)
{
    if(isvisited[current]==1)
        return ;
    isvisited[current]=1;
    if(current==target)
    {
        if(distance<shortest)
        {
            counter=1;
            shortest=distance;
            maximum=teams;
        }
        else if(distance==shortest)
        {
            counter++;
            if(maximum<teams)
                maximum=teams;
        }
    }
    else
    {
        for(int i=0;i<c[current].other_num;i++)
        {
            int next=c[current].other[i];
            dfs(next,target,distance+c[current].length[i],teams+c[next].rescue_team);
        }
    }
    isvisited[current]=0;
}

int main(int argc,char *argv[])
{
    int current,target;
    int N,M;
    scanf("%d%d%d%d",&N,&M,&current,&target);
    for(int i=0;i<N;i++)
        scanf("%d",&c[i].rescue_team);
    for(int i=0;i<M;i++)
    {
        int c1,c2,l;
        scanf("%d%d%d",&c1,&c2,&l);
        int left=c[c1].other_num;
        int right=c[c2].other_num;
        c[c1].other[left]=c2;
        c[c1].length[left]=l;
        c[c1].other_num++;
        c[c2].other[right]=c1;
        c[c2].length[right]=l;
        c[c2].other_num++;
    }
    dfs(current,target,0,c[current].rescue_team);
    printf("%d %d",counter,maximum);
    return 0;
}
