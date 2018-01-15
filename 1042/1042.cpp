#include<cstdio>
#include<vector>
using namespace std;

void decode(int x)
{
    if(x<=13)
        printf("S%d",x);
    else if(x<=13+13)
        printf("H%d",x%13!=0?x%13:13);
    else if(x<=13+13+13)
        printf("C%d",x%(13+13));
    else if(x<=13+13+13+13)
        printf("D%d",x%(13+13+13));
    else
        printf("J%d",x%(13+13+13+13));
}

int main()
{
    vector<int> v(60),vx(60);
    for(int i=1;i<=54;i++)
        v[i]=i;
    int n;
    scanf("%d",&n);
    vector<int> table;
    for(int i=0;i<54;i++)
    {
        int x;
        scanf("%d",&x);
        table.push_back(x);
    }
    for(int k=0;k<n;k++)
    {
        int cnt=1;
        for(auto x:table)
            vx[x]=v[cnt++];
        v=vx;
    }
    decode(v[1]);
    for(int i=2;i<=54;i++)
    {
        printf(" ");
        decode(v[i]);
    }
}
