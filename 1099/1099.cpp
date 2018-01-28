#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct
{
    int data;
    int size;
    int left{-1};
    int right{-1};
}a[200];

int size(int x)
{
    if(x==-1)
        return 0;
    int l=size(a[x].left);
    int r=size(a[x].right);
    a[x].size=l+r+1;
    return a[x].size;
}

int return_size(int x)
{
    if(x==-1)
        return 0;
    return a[x].size;
}

void process(vector<int> &v,int l,int r,int x)
{
    if(x==-1)
        return;
    int nth=return_size(x)-return_size(a[x].right);//1 is the first ,not 0
    a[x].data=v[l+nth-1];
    //printf("x=%d size=%d data=%d nth=%d l=%d r=%d\n",x,a[x].size,a[x].data,nth,l,r);
    process(v,l,l+nth-2,a[x].left); //r is not used, but it is important
    process(v,l+nth,r,a[x].right);
}

void level_order(vector<int> &v)
{
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        v.push_back(a[x].data);
        if(a[x].left!=-1)
            q.push(a[x].left);
        if(a[x].right!=-1)
            q.push(a[x].right);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int left,right;
        scanf("%d%d",&left,&right);
        a[i].left=left;
        a[i].right=right;
    }
    vector<int> v(n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    size(0);
    process(v,0,n-1,0);
    vector<int> out;
    level_order(out);
    printf("%d",out[0]);
    for(int i=1;i<n;i++)
        printf(" %d",out[i]);
}
