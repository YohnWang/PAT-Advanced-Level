#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct graph
{
    vector<int> adj;
    double total;
};

double P,r;
double amount=0;

void dfs(vector<graph> &g,int now,vector<int> &visit,double price)
{
    if(visit[now]!=0)
        return ;
    visit[now]=1;
    if(g[now].adj.size()==0)//level
        amount+=g[now].total*price;
    for(auto x:g[now].adj)
        dfs(g,x,visit,price*((100+r)/100));
}

int main()
{
    int N;

    scanf("%d%lf%lf",&N,&P,&r);
    vector<graph> g(N);
    for(int i=0;i<N;i++)
    {
        int k;
        scanf("%d",&k);
        if(k!=0)
        {
            for(int j=0;j<k;j++)
            {
                int x;
                scanf("%d",&x);
                g[i].adj.push_back(x);
            }
        }
        else
        {
            double t;
            scanf("%lf",&t);
            g[i].total=t;
        }
    }
    vector<int> v(N,0);
    dfs(g,0,v,P);
    printf("%.1f",amount);
}
