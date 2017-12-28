#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc,char *argv[])
{
    int m,n;
    vector<int> v;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
    }
    make_heap(v.begin(),v.end());
    for(int i=0;i<m*n/2;i++)
    {
        pop_heap(v.begin(),v.end());
        v.pop_back();
    }
    printf("%d",v.front());
}
