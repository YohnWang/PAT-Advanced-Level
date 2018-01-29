#include<cstdio>
#include<vector>
#include<queue>
#include<cctype>
#include<algorithm>
using namespace std;

struct T
{
    int data;
    int left;
    int right;
}a[100];

int counter=0;
void dfs(int x)
{
    if(x==-1)
        return ;
    counter++;
    dfs(a[x].left);
    dfs(a[x].right);
}

void level(vector<int> &v,int r)
{
    queue<int> q;
    q.push(r);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        v.push_back(x);
        if(a[x].right!=-1)
            q.push(a[x].right);
        if(a[x].left!=-1)
            q.push(a[x].left);
    }
}

void inorder(vector<int> &v,int x)
{
    if(x==-1)
        return ;
    inorder(v,a[x].right);
    v.push_back(x);
    inorder(v,a[x].left);
}

void print(vector<int> v,int n)
{
    printf("%d",v[0]);
    for(int i=1;i<n;i++)
        printf(" %d",v[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        int l=getchar();
        getchar();
        int r=getchar();
        getchar();
        if(isdigit(l))
            a[i].left=l-'0';
        else
            a[i].left=-1;
        if(isdigit(r))
            a[i].right=r-'0';
        else
            a[i].right=-1;
    }
    int root;
    for(int i=0;i<n;i++)
    {
        counter=0;
        dfs(i);
        if(counter==n)
        {
            root=i;
            break;
        }
    }
    vector<int> v;
    level(v,root);
    print(v,n);
    v.clear();
    inorder(v,root);
    print(v,n);
}
