#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct T
{
    double ton;
    double price;
    double unit;
};

int main()
{
    int N,D;
    scanf("%d%d",&N,&D);
    vector<T> v(N);
    for(int i=0;i<N;i++)
        scanf("%lf",&v[i].ton);
    for(int i=0;i<N;i++)
    {
        scanf("%lf",&v[i].price);
        v[i].unit=v[i].price/v[i].ton;
    }
    sort(v.begin(),v.end(),[](T &a,T &b){return a.unit>b.unit;});
    double profit=0,all=D;
    for(auto &x:v)
    {
        if(x.ton<=all)
        {
            all-=x.ton;
            profit+=x.price;
        }
        else
        {
            profit+=x.price*(1.0*all/x.ton);
            all=0;
        }
    }
    printf("%.2f",profit);
}
