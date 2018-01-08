#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treap treap;
struct treap
{
    treap *left;
    treap *right;
    int prio;
    int data;
    int lsize,rsize;
};

static void set_size(treap *k)
{
    if(k!=NULL)
    {
        if(k->left)
            k->lsize=k->left->lsize+k->left->rsize+1;
        else
            k->lsize=0;
        if(k->right)
            k->rsize=k->right->lsize+k->right->rsize+1;
        else
            k->rsize=0;
    }
}

static treap* ll_rotate(treap *k2)
{
    treap *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    set_size(k2);
    set_size(k1);
    return k1;
}

static treap* rr_rotate(treap *k2)
{
    treap *k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    set_size(k2);
    set_size(k1);
    return k1;
}

int quick_rand()
{
    static int seed=1;
    seed=seed*1103515245+12345;
    return seed;
}

treap* treap_add(treap *r,int data)
{
    if(r==NULL)
    {
        r=malloc(sizeof(*r));
        r->data=data;
        r->prio=quick_rand();
        r->left=NULL;
        r->right=NULL;
    }
    else if(data<r->data)
    {
        r->left=treap_add(r->left,data);
        if(r->left->prio<r->prio)
            r=ll_rotate(r);
    }
    else if(data>=r->data)
    {
        r->right=treap_add(r->right,data);
        if(r->right->prio<r->prio)
            r=rr_rotate(r);
    }
    else
    {

    }
    set_size(r);
    return r;
}

treap* treap_del(treap *r,int data)
{
    if(r==NULL)
        return r;
    if(data<r->data)
        r->left=treap_del(r->left,data);
    else if(data>r->data)
        r->right=treap_del(r->right,data);
    else
    {
        if(r->left==NULL && r->right==NULL)
        {
            free(r);
            r=NULL;
        }
        else if(r->left==NULL)
        {
            treap *p=r->right;
            free(r);
            r=p;
        }
        else if(r->right==NULL)
        {
            treap *p=r->left;
            free(r);
            r=p;
        }
        else
        {
            if(r->left->prio<r->right->prio)
            {
                r=ll_rotate(r);
                r->right=treap_del(r->right,data);
            }
            else
            {
                r=rr_rotate(r);
                r->left=treap_del(r->left,data);
            }
        }
    }
    set_size(r);
    return r;
}

int nth_x(treap *r,int i)
{
    int l=r->lsize+1;
    if(i==l)
        return r->data;
    else if(i<l)
        return nth_x(r->left,i);
    else
        return nth_x(r->right,i-l);
}

treap *r=NULL;
int a[100010];
int top=0;

void pop()
{
    if(top==0)
        printf("Invalid\n");
    else
    {
        printf("%d\n",a[top-1]);
        r=treap_del(r,a[--top]);
    }
}

void _push()
{
    int key;
    scanf("%d",&key);
    a[top++]=key;
    r=treap_add(r,key);
}

void peekmedian()
{
    if(top==0)
        printf("Invalid\n");
    else
        printf("%d\n",nth_x(r,(top+1)/2));
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[30];
        scanf("%s",op);
        if(op[1]=='o')
            pop();
        else if(op[1]=='e')
            peekmedian();
        else if(op[1]=='u')
            _push();
        else
            printf("Invalid\n");
    }
}
