#include<stdio.h>
#include<stdlib.h>
int a[100010];
int N,M;
struct{int l,r;} nfind[100010];
int ntop=0;

void nfind_add(int l,int r)
{
    nfind[ntop].l=l;
    nfind[ntop].r=r;
    ntop++;
}

int lrvalue(int l,int r)
{
    return a[r]-a[l-1];
}

int bfind(int l,int r,int x)
{
    int begin=l,end=r;
    int center=begin;
    while(begin<=end)
    {
        center=(begin+end)/2;
        if(x<a[center])
            end=center-1;
        else if(x>a[center])
            begin=center+1;
        else
            return center;
    }
    if(begin>N)
        return 0;
    return begin;
}
int main(int argc,char *argv[])
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        int x;
        scanf("%d",&x);
        a[i+1]=a[i]+x;
    }
    int is_find=0;
    int min=999999999;
    for(int i=1;i<=N;i++)
    {
        int diff=M+a[i-1];
        int index=bfind(i,N,diff);
        int value=lrvalue(i,index);
        if(value==M&&(is_find=1))
            printf("%d-%d\n",i,index);
        else if(is_find==0&&value>M)
        {
            if(value<min)
            {
                min=value;
                ntop=0;
                nfind_add(i,index);
            }
            else if(value==min)
                nfind_add(i,index);
        }
    }
    if(is_find==0)
        for(int i=0;i<ntop;i++)
            printf("%d-%d\n",nfind[i].l,nfind[i].r);
}
