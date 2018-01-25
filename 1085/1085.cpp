#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int find_le(vector<int> &v,int begin,int end,long long int x)
{
    while(begin<=end)
    {
        int center=(begin+end)/2;
        if(x<v[center])
            end=center-1;
        else if(x>v[center])
            begin=center+1;
        else
            return center;
    }
    return end;
}

int find_max_size(vector<int> &v,int p)
{
    if(p==0)
        return 0;
    int max=0;
    for(int i=0;i<v.size();i++)
    {
        long long int m=(long long int)v[i]*p;
        int index=find_le(v,i+1,v.size()-1,m);
        int size=index-i+1;
        if(max<size)
            max=size;
    }
    return max;
}

int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    vector<int> v(n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    printf("%d",find_max_size(v,p));
}
