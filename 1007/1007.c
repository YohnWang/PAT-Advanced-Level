#include<stdio.h>
#include<stdlib.h>
#define NINF (0x80000000)

struct result
{
    int max;
    int begin;
    int end;
};
typedef struct result result;

result find_cross(int a[],int begin,int end,int center)
{
    int left,right;
    int left_max=NINF,right_max=NINF;
    int left_sum=0,right_sum=0;
    for(int i=center;i>=begin;i--)
    {
        left_sum+=a[i];
        if(left_sum>=left_max)
        {
            left_max=left_sum;
            left=i;
        }
    }
    for(int i=center+1;i<=end;i++)
    {
        right_sum+=a[i];
        if(right_sum>right_max)
        {
            right_max=right_sum;
            right=i;
        }
    }
    return (result){left_max+right_max,left,right};
}

result find_max(int a[],int begin,int end)
{
    int center=(begin+end)/2;
    if(begin==end)
        return (result){a[begin],begin,end};
    result left,cross,right;
    left=find_max(a,begin,center);
    right=find_max(a,center+1,end);
    cross=find_cross(a,begin,end,center);
    if(left.max>=right.max&&left.max>=cross.max)
        return left;
    if(cross.max>=right.max&&cross.max>=left.max)
        return cross;
    return right;
}

int main(int argc,char *argv[])
{
    int a[10010];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    result r=find_max(a,0,n-1);
    if(r.max>=0)
        printf("%d %d %d",r.max,a[r.begin],a[r.end]);
    else
        printf("%d %d %d",0,a[0],a[n-1]);
    return 0;
}
