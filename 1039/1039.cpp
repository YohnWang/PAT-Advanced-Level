#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
    map<string,vector<int>> v;
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++)
    {
        int course,num;
        scanf("%d%d",&course,&num);
        for(int j=0;j<num;j++)
        {
            char s[10];
            scanf("%s",s);
            v[string(s)].push_back(course);
        }
    }
    for(int i=0;i<N;i++)
    {
        char s[10];
        scanf("%s",s);
        printf("%s",s);
        auto &vx=v[string(s)];
        printf(" %d",static_cast<int>(vx.size()));
        sort(vx.begin(),vx.end());
        for(auto x:vx)
            printf(" %d",x);
        printf("\n");
    }
}
