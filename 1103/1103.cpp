#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int N,K,P;
int table[1000];
vector<vector<int>> v;

void init()
{
    for(int i=0;i*i<=N;i++)
    {
        int pr=1;
        for(int j=0;j<P;j++)
        {
            pr*=i;
            if(pr>N)
            {
                table[i]=N+N;
                break;
            }
        }
        if(table[i]==0)
            table[i]=pr;
    }
}

vector<int> tmp;
int flag; // this flag must be set,bug I don't know why it is important,or it will be time limited
void dfs(int x,int deep,int pr)
{
    if(deep>K)
        return ;
    if(pr+table[x]<N)
    {
        tmp.push_back(x);
        for(int i=x;i*i<=N && flag<=N;i++) //P is in (1,7],so ignore p=1
            dfs(i,deep+1,pr+table[x]);
        flag=0;
        tmp.pop_back();
    }
    else if(pr+table[x]==N&&deep==K)
    {
        tmp.push_back(x);
        v.push_back(tmp);
        tmp.pop_back();
    }
    else if(pr+table[x]>N)
    {
        flag=pr+table[x];
    }
}

int sum(vector<int> &vx)
{
    int s=0;
    for(auto x:vx)
        s+=x;
    return s;
}

bool comp(vector<int> &l,vector<int> &r)
{
    int suml=sum(l);
    int sumr=sum(r);
    if(suml!=sumr)
        return suml>sumr;
    for(int i=0;i<K;i++)
    {
        if(l[i]!=r[i])
            return l[i]>r[i];
    }
    return true;
}

void print()
{
    printf("%d = ",N);
    printf("%d^%d",v[0][0],P);
    for(int i=1;i<K;i++)
        printf(" + %d^%d",v[0][i],P);
}

int main()
{
    scanf("%d%d%d",&N,&K,&P);
    init();
    for(int i=1;i*i<=N;i++)
        dfs(i,1,0);
    for(auto &x:v)
        sort(x.begin(),x.end(),greater<int>());
    sort(v.begin(),v.end(),comp);
    if(v.size()!=0)
        print();
    else
        printf("Impossible");
}
