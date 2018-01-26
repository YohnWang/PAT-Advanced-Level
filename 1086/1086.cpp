#include<cstdio>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

struct Tree
{
    int x;
    Tree *left{nullptr};
    Tree *right{nullptr};
    Tree(int data):x{data}{}
};

Tree* construct(vector<int> &v,map<int,int> &m)
{
    Tree *root=nullptr;
    for(auto x:v)
    {
        if(root==nullptr)
            root=new Tree(x);
        else
        {
            auto r=new Tree(x);
            auto p=root;
            while(p!=nullptr)
            {
                if(m[x]<m[p->x])
                {
                    if(p->left!=nullptr)
                        p=p->left;
                    else
                    {
                        p->left=r;
                        break;
                    }
                }
                else
                {
                    if(p->right!=nullptr)
                        p=p->right;
                    else
                    {
                        p->right=r;
                        break;
                    }
                }
            }
        }
    }
    return root;
}

void post_order(Tree *r,vector<int> &v)
{
    if(r!=nullptr)
    {
        post_order(r->left,v);
        post_order(r->right,v);
        v.push_back(r->x);
    }
}

int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    vector<int> v; //pre-order
    map<int,int> m;//in-order table
    stack<int> vs;
    while(m.size()<n)
    {
        char s[10];
        scanf("%s",s);
        if(string(s)=="Push")
        {
            int x;
            scanf("%d",&x);
            vs.push(x);
            v.push_back(x);
        }
        else if(string(s)=="Pop")
        {
            m[vs.top()]=cnt++;
            vs.pop();
        }
    }
    vector<int> out;
    post_order(construct(v,m),out);
    printf("%d",out[0]);
    for(int i=1;i<out.size();i++)
        printf(" %d",out[i]);
}
