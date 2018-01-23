#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int bfs(vector<vector<int>> &v,int src,int deep)
{
    queue<int> q;
    vector<int> visited(v.size(),0);
    vector<int> level_num(v.size(),0);
    int cnt=0,level=0;
    q.push(src);
    level_num[level]=1;
    visited[src]=1;
    while(!q.empty()&&level<deep)
    {
        int p=q.front();
        q.pop();
        for(auto x:v[p])
            if(visited[x]==0)
            {
                visited[x]=1;
                q.push(x);
                level_num[level+1]++;
            }
        cnt++;
        level_num[level]--;
        if(level_num[level]==0)
            level++;
    }
    return cnt;
}

int main()
{
    int N,L;
    scanf("%d%d",&N,&L);
    vector<vector<int>> v(N+1);
    for(int i=1;i<=N;i++)
    {
        int M;
        scanf("%d",&M);
        for(int j=0;j<M;j++)
        {
            int x;
            scanf("%d",&x);
            v[x].push_back(i);
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",bfs(v,x,L+1)-1); //don't count origin,so is level
    }
}
