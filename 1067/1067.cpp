#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//find the element is not at the right position
int is_finish(map<int,int> &v)
{
    for(auto &x:v)
    {
        if(x.first!=x.second)
            return x.first;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    map<int,int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        v[x]=i;
    }
    int cnt=0;
    int flag=is_finish(v);
    while(flag!=-1)
    {
        int index_zero=v[0];
        int index_tar=v[index_zero];
        if(index_zero!=0)
        {
            v[0]=index_tar;
            v.erase(index_zero); //it is at the right position,erase it
        }
        else
        {
            v[0]=v[flag];
            v[flag]=index_zero;
        }
        cnt++;
        flag=is_finish(v);
    }
    printf("%d",cnt);
}
