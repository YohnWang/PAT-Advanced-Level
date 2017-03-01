#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct person
{
    string id;
    int in;
    int out;
};
vector<struct person> ps;
int main(int argc,char *argv[])
{
    char ss[20];
    int h,m,s;
    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%s",ss);
        scanf("%d:%d:%d",&h,&m,&s);
        int in=h*60*60+m*60+s;
        scanf("%d:%d:%d",&h,&m,&s);
        int out=h*60*60+m*60+s;
        ps.push_back({string(ss),in,out});
    }
    make_heap(ps.begin(),ps.end(),[](person x,person y){return x.in>y.in;});
    printf("%s",ps[0].id.c_str());
    make_heap(ps.begin(),ps.end(),[](person x,person y){return x.out<y.out;});
    printf(" %s",ps[0].id.c_str());
    return 0;
}
