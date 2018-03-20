#include<cstdio>
using namespace std;
char v[10000000+10];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long int x;
        scanf("%lld",&x);
        //scan_d(x);
        if(x>0 && x<=n)
            v[x]=1;
    }
    for(int i=1;i<=n+1;i++)
        if(!v[i])
        {
            printf("%d",i);
            break;
        }
}
