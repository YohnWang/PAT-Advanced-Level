#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

double analyse(vector<int> &a,vector<int> &b)
{
    int similar=0;
    decltype(a.size()) i=0,j=0;
    while(i<a.size()&&j<b.size())
    {
        if(a[i]==b[j])
        {
            similar++;
            i++;j++;
        }
        else if(a[i]<b[j])
            i++;
        else
            j++;
    }
    return 100.0*similar/(a.size()+b.size()-similar);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
        }
        sort(v[i].begin(),v[i].end());
        auto iter=unique(v[i].begin(),v[i].end());
        v[i].erase(iter,v[i].end());
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%.1f\%\n",analyse(v[a-1],v[b-1]));
    }
}
