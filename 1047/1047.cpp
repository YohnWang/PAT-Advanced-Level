#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    vector<vector<int>> v(M+1);
    vector<string> name(1000000);
    for(int i=0;i<N;i++)
    {
        char s[20];
        int n;
        scanf("%s %d",s,&n);
        int sh=(s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+(s[3]-'0');
        if(name[sh]=="")
            name[sh]=string(s);
        for(int j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            v[x].push_back(sh);
        }
    }
    for(int i=1;i<=M;i++)
    {
        sort(v[i].begin(),v[i].end());
        printf("%d %d\n",i,static_cast<int>(v[i].size()));
        for(auto x:v[i])
            printf("%s\n",name[x].c_str());
    }
}
