#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int max_deep=0;
int max_deep_cnt=0;

void dfs(vector<vector<int>> &v,vector<int> &visit,int now,int deep)
{
    if(visit[now]!=0)
        return ;
    visit[now]=1;

    if(deep>max_deep&&v[now].size()==0)
    {
        max_deep_cnt=1;
        max_deep=deep;
    }
    else if(deep==max_deep&&v[now].size()==0)
        max_deep_cnt++;

    for(auto x:v[now])
        dfs(v,visit,x,deep+1);
}

int main()
{
    int n;
    double p,r;
    scanf("%d%lf%lf",&n,&p,&r);
    vector<vector<int>> v(n);
    int start;
    for(int i=0;i<n;i++)
    {
        int from;
        scanf("%d",&from);
        if(from==-1)
            start=i;
        else
            v[from].push_back(i);
    }
    vector<int> visit(n,0);
    dfs(v,visit,start,0);
    printf("%.2f %d",p*pow(r/100+1,max_deep),max_deep_cnt);
}
