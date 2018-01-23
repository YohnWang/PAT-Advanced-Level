#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
constexpr int MAX_PROBLEM=6;
int Full_Mark[MAX_PROBLEM];
int N,K,M;
struct T
{
    int a[MAX_PROBLEM]{0};
    int is_submit[MAX_PROBLEM]{0};
    int compile{0};
    int total{0};
    int id;
};

int profect(T &x)
{
    int cnt=0;
    for(int i=1;i<MAX_PROBLEM;i++)
        if(x.a[i]==Full_Mark[i])
            cnt++;
    return cnt;
}

bool comp(T &a,T &b)
{
    if(a.total==b.total)
    {
        int ax=profect(a);
        int bx=profect(b);
        if(ax==bx)
            return a.id<b.id;
        return ax>bx;
    }
    return a.total>b.total;
}

void print(T &x)
{
    printf("%.5d %d",x.id,x.total);
    for(int i=1;i<=K;i++)
    {
        if(x.is_submit[i]==0)
            printf(" -");
        else
            printf(" %d",x.a[i]);
    }
}

int main()
{

    scanf("%d%d%d",&N,&K,&M);
    for(int i=1;i<=K;i++)
        scanf("%d",&Full_Mark[i]);
    map<int,T> v;
    for(int i=0;i<M;i++)
    {
        int id,pid,score;
        scanf("%d%d%d",&id,&pid,&score);
        if(score!=-1)
        {
            v[id].compile=1;
            if(v[id].a[pid]<score)
                v[id].a[pid]=score;
        }
        else
        {
            if(v[id].is_submit[pid]==0)
                v[id].a[pid]=0;
        }
        v[id].is_submit[pid]=1;
    }
    vector<T> vx;
    for(auto &x:v)
    {
        T tmp=x.second;
        for(int i=1;i<=K;i++)
            if(tmp.is_submit[i])
                tmp.total+=tmp.a[i];
        tmp.id=x.first;
        if(tmp.compile!=0)
            vx.push_back(tmp);
    }
    sort(vx.begin(),vx.end(),comp);
    int rk=1,before=-1;
    for(int i=0;i<vx.size();i++)
    {
        if(vx[i].total!=before)
            rk=i+1;
        before=vx[i].total;
        printf("%d ",rk);
        print(vx[i]);
        printf("\n");
    }
}
