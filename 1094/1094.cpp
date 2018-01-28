#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int out[1024];

void dfs(vector<vector<int>> &v,vector<int> &visit,int now,int deep)
{
    if(visit[now]!=0)
        return ;
    visit[now]=1;
    out[deep]++;
    for(auto x:v[now])
        dfs(v,visit,x,deep+1);
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    vector<vector<int>> v(N+1);
    for(int i=0;i<M;i++)
    {
        int n,id;
        scanf("%d%d",&id,&n);
        for(int j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            v[id].push_back(x);
        }
    }
    vector<int> visit(N+1,0);
    dfs(v,visit,1,1);
    auto iter=max_element(out,out+101);
    printf("%d %d",*iter,iter-out);
}
