#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct T
{
    int id;
    int virtue;
    int talent;
};

int main()
{
    int n,low,high;
    scanf("%d%d%d",&n,&low,&high);
    vector<T> sage,nobleman,foolman,smallman;
    for(int i=0;i<n;i++)
    {
        int id,virtue,talent;
        scanf("%d%d%d",&id,&virtue,&talent);
        if(virtue>=high&&talent>=high)
            sage.push_back({id,virtue,talent});
        else if(virtue>=high&&talent>=low)
            nobleman.push_back({id,virtue,talent});
        else if(virtue>=low&&talent>=low)
        {
            if(virtue>=talent)
                foolman.push_back({id,virtue,talent});
            else
                smallman.push_back({id,virtue,talent});
        }
    }
    auto cmp=[](T &a,T &b)
    {
        int aa=a.virtue+a.talent;
        int bb=b.virtue+b.talent;
        if(aa==bb)
        {
            if(a.virtue==b.virtue)
                return a.id<b.id;
            return a.virtue>b.virtue;
        }
        return aa>bb;
    };
    sort(sage.begin(),sage.end(),cmp);
    sort(nobleman.begin(),nobleman.end(),cmp);
    sort(foolman.begin(),foolman.end(),cmp);
    sort(smallman.begin(),smallman.end(),cmp);
    auto num=sage.size()+nobleman.size()+foolman.size()+smallman.size();
    printf("%d\n",static_cast<int>(num));
    for(auto &x:sage)
        printf("%.8d %d %d\n",x.id,x.virtue,x.talent);
    for(auto &x:nobleman)
        printf("%.8d %d %d\n",x.id,x.virtue,x.talent);
    for(auto &x:foolman)
        printf("%.8d %d %d\n",x.id,x.virtue,x.talent);
    for(auto &x:smallman)
        printf("%.8d %d %d\n",x.id,x.virtue,x.talent);
}
