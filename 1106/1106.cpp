#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> v;
int N;
double P,r;
int Min=1000000;
int Cnt=0;

void dfs(int x,int deep)
{
    if(v[x].size()==0)
    {
        if(deep<Min)
        {
            Min=deep;
            Cnt=1;
        }
        else if(deep==Min)
            Cnt++;
    }
    else
    {
        for(auto i:v[x])
            dfs(i,deep+1);
    }
}
int main()
{
    scanf("%d%lf%lf",&N,&P,&r);
    v.resize(N);
    for(int i=0;i<N;i++)
    {
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
        }
    }
    dfs(0,0);
    printf("%.4f %d",P*pow((100+r)/100,Min),Cnt);
}
