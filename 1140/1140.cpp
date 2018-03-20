#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void to_next(vector<int> &v)
{
    vector<int> dv;
    unsigned int i{0};
    while(i<v.size())
    {
        int elem=v[i];
        int cnt=0;
        while(i+cnt<v.size()&&v[i+cnt]==elem)
            cnt++;
        dv.push_back(elem);
        string num=to_string(cnt);
        for(auto c:num)
            dv.push_back(c-'0');
        i+=cnt;
    }
    v=dv;
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    vector<int> v{x};
    for(int i=1;i<y;i++)
        to_next(v);
    for(auto x:v)
        printf("%d",x);
}
