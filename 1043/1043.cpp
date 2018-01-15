#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

class tree
{
    struct T
    {
        int x;
        T *left{nullptr};
        T *right{nullptr};
        T(int x):x{x}{};
    };
    T *root{nullptr};
public:
    void insert(int x)
    {
        if(root==NULL)
            root=new T{x};
        else
        {
            T *p=root;
            while(p!=NULL)
            {
                if(x<p->x&&p->left!=nullptr)
                    p=p->left;
                else if(x<p->x)
                    {p->left=new T{x};return;}
                else if(x>=p->x&&p->right!=nullptr)
                    p=p->right;
                else
                    {p->right=new T{x};return;}
            }
        }
    }
    void rinsert(int x)
    {
        if(root==NULL)
            root=new T{x};
        else
        {
            T *p=root;
            while(p!=NULL)
            {
                if(x>=p->x&&p->left!=nullptr)
                    p=p->left;
                else if(x>=p->x)
                    {p->left=new T{x};return;}
                else if(x<p->x&&p->right!=nullptr)
                    p=p->right;
                else
                    {p->right=new T{x};return;}
            }
        }
    }
    void _is_pre(T *r,vector<int> &v)
    {
        if(r!=nullptr)
        {
            v.push_back(r->x);
            _is_pre(r->left,v);
            _is_pre(r->right,v);
        }
    }
    bool is_pre(vector<int> &v)
    {
        vector<int> vx;
        _is_pre(root,vx);
        return v==vx;
    }
    void _post(T *r,vector<int> &v)
    {
        if(r!=nullptr)
        {
            _post(r->left,v);
            _post(r->right,v);
            v.push_back(r->x);
        }
    }
    void post(vector<int> &v)
    {
        _post(root,v);
    }
};

int main()
{
    int n;
    vector<int> v,vx;
    tree r,rr;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
        r.insert(x);
        rr.rinsert(x);
    }
    auto br=r.is_pre(v),brr=rr.is_pre(v);
    if(br||brr)
    {
        printf("YES\n");
        if(br)
            r.post(vx);
        else
            rr.post(vx);
        printf("%d",vx[0]);
        for(auto i=vx.begin()+1;i!=vx.end();i++)
            printf(" %d",*i);
    }
    else
        printf("NO");
}
