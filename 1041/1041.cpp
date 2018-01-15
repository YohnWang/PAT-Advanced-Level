#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    int n;
    vector<int> v,vx(10010,0);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
        vx[x]++;
    }
    for(auto x:v)
        if(vx[x]==1)
        {
            printf("%d",x);
            return 0;
        }
    printf("None");
}
