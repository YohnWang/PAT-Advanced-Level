#include<cstdio>
#include<vector>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;

struct person
{
    vector<int> hobby;
};

int cnt;
void dfs(map<int,vector<int>> &m,vector<person> &v,vector<int> &visit,int x)
{
    if(visit[x]!=0)
        return;
    visit[x]=1;
    cnt++;
    for(auto h:v[x].hobby)
    {
        for(auto p:m[h])
            dfs(m,v,visit,p);
    }
}

int main()
{
    map<int,vector<int>> m; //hobby h[i] saves its person
    int n;
    scanf("%d",&n);
    vector<person> v(n+1); //every person saves his or her hobbies
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d:",&k);
        for(int j=0;j<k;j++)
        {
            int x;
            scanf("%d",&x);
            v[i].hobby.push_back(x);
            m[x].push_back(i);
        }
    }
    vector<int> out;
    vector<int> visit(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            cnt=0;
            dfs(m,v,visit,i);
            out.push_back(cnt);
        }
    }
    sort(out.begin(),out.end(),greater<int>());
    printf("%lld\n",out.size());
    if(out.size()!=0)
        printf("%d",out[0]);
    for(auto i=1LLU;i<out.size();i++)
        printf(" %d",out[i]);
}
