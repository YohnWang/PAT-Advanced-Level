#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a[200];
int s[1010];

bool is_sym(int l,int r)
{
    while(l<=r)
    {
        if(s[l]!=s[r])
            return false;
        l++;r--;
    }
    return true;
}

int main()
{
    int n=0,c;
    while((c=getchar())!=EOF)
    {
        s[n]=c;
        a[c].push_back(n);
        n++;
    }
    s[n]='\0';
    int m=0;
    for(int i=0;i<n;i++)
    {

        for(auto iter=a[s[i]].rbegin();iter!=a[s[i]].rend();iter++)
        {
            if(is_sym(i,*iter))
            {
                m=max(m,*iter-i+1);
                break;
            }
        }
    }
    printf("%d",m);
}
