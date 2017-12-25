#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    int like[250]={0};
    int good[12000]={0};
    int table[12000]={0};
    int N;
    scanf("%d",&N);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        like[x]=i;
    }
    int l;
    scanf("%d",&l);
    int count=0;
    for(int i=0;i<l;i++)
    {
        int x;
        scanf("%d",&x);
        if(like[x]!=0)
            good[count++]=x;
    }
    int max=0;
    table[max++]=good[0];
    for(int i=1;i<count;i++)
    {
        int left=good[i],right=table[max-1];
        if(like[left]>=like[right])
            table[max++]=left;
        else
        {
            int begin=0,end=max-1;
            int center;
            while(begin<end)
            {
                center=(begin+end)/2;
                if(like[left]>like[table[center]])
                    begin=center+1;
                else if(like[left]<like[table[center]])
                    end=center-1;
                else
                    break;
            }
            for(int i=begin;i<max;i++)
                if(like[left]<like[table[i]])
                {
                    table[i]=left;
                    break;
                }
        }
    }
    printf("%d",max);
}
