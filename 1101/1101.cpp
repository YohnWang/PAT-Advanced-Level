#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> vx(n),vy;
    for(int i=0;i<n;i++)
        scanf("%d",&vx[i]);
    vy=vx;
    sort(vy.begin(),vy.end());
    vector<int> out;
    int max=-1;
    for(int i=0;i<n;i++)
    {
        if(vx[i]==vy[i]&&vx[i]>max)
            out.push_back(vx[i]);
        if(vx[i]>max)
            max=vx[i];
    }
    int k=static_cast<int>(out.size());
    printf("%d\n",k);
    if(k!=0)
        printf("%d",out[0]);
    for(int i=1;i<k;i++)
        printf(" %d",out[i]);
    printf("\n");
}
