#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

struct tree
{
    int x;
    tree *left{nullptr},*right{nullptr};
    tree(int data):x{data}{}
};

tree* to_tree(vector<int> &v)
{
    if(v.size()==0)
        return nullptr;
    auto i=0U;
    tree *r=new tree(v[i++]);
    queue<tree*> q;
    q.push(r);
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        if(i<v.size())
        {
            p->left=new tree(v[i++]);
            q.push(p->left);
        }
        if(i<v.size())
        {
            p->right=new tree(v[i++]);
            q.push(p->right);
        }
    }
    return r;
}


void post(tree *r,vector<int> &v)
{
    if(r!=nullptr)
    {
        post(r->left,v);
        post(r->right,v);
        v.push_back(r->x);
    }
}

void print_post(vector<int> &v)
{
    tree *r=to_tree(v);
    vector<int> out;
    post(r,out);
    printf("%d",out[0]);
    for(auto i=1U;i<v.size();i++)
        printf(" %d",out[i]);
    printf("\n");
}

int main()
{
    int N,n;
    scanf("%d%d",&N,&n);
    for(int k=0;k<N;k++)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        int state=0;
        if(is_heap(v.begin(),v.end()))
            state=1;
        else if(is_heap(v.begin(),v.end(),greater<int>()))
            state=2;
        if(state==1)
            printf("Max Heap\n");
        else if(state==2)
            printf("Min Heap\n");
        else
            printf("Not Heap\n");
        print_post(v);
    }
}
