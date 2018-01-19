#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int NC,NP;
    scanf("%d",&NC);
    vector<int> vx,vy;
    for(int i=0;i<NC;i++)
    {
        int x;
        scanf("%d",&x);
        vx.push_back(x);
    }
    scanf("%d",&NP);
    for(int i=0;i<NP;i++)
    {
        int x;
        scanf("%d",&x);
        vy.push_back(x);
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    int sum=0;
    auto i=vx.size()-1,j=vy.size()-1;
    while(i>=0&&j>=0&&vx[i]>0&&vy[j]>0)
    {
        sum+=vx[i]*vy[j];
        i--;
        j--;
    }
    i=0;j=0;
    while(i<vx.size()&&j<vy.size()&&vx[i]<0&&vy[j]<0)
    {
        sum+=vx[i]*vy[j];
        i++;
        j++;
    }
    printf("%d",sum);
}
