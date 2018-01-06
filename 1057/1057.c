#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int left;
    int right;
    int count;
};

struct bost
{
    struct node *v;
    int range;
};
typedef struct bost bost;

bost make_bost(int range)
{
    bost b;
    b.v=malloc(sizeof(b.v[0])*(range+1));
    b.range=range;
    memset(b.v,0,sizeof(b.v[0])*(range+1));
    return b;
}

void push(bost *b,int x)
{
    int left=0,right=b->range;
    while(left<=right)
    {
        int center=(left+right)/2;
        if(x<center)
        {
            b->v[center].left++;
            right=center-1;
        }
        else if(x>center)
        {
            b->v[center].right++;
            left=center+1;
        }
        else
        {
            b->v[center].count++;
            break;
        }
    }
}

int exist(bost *b,int x)
{
    if(b->v[x].count>0)
        return 1;
    return 0;
}

int erase(bost *b,int x)
{
    if(exist(b,x)==0)
        return 0;
    int left=0,right=b->range;
    while(left<=right)
    {
        int center=(left+right)/2;
        if(x<center)
        {
            b->v[center].left--;
            right=center-1;
        }
        else if(x>center)
        {
            b->v[center].right--;
            left=center+1;
        }
        else
        {
            b->v[center].count--;
            break;
        }
    }
    return 1;
}

int nth_x(bost *b,int i)
{
    int left=0,right=b->range;
    int center=(left+right)/2;
    while(left<=right)
    {
        center=(left+right)/2;
        int l=b->v[center].left;
        int c=b->v[center].count;
        if(i<=l)
            right=center-1;
        else if(i>l+c)
        {
            i=i-l-c;
            left=center+1;
        }
        else
            return center;
    }
    return center;
}

bost b;
int a[100010];
int top=0;

void pop()
{
    if(top==0)
        printf("Invalid\n");
    else
    {
        printf("%d\n",a[top-1]);
        erase(&b,a[--top]);
    }
}

void _push()
{
    int key;
    scanf("%d",&key);
    a[top++]=key;
    push(&b,key);
}

void peekmedian()
{
    if(top==0)
        printf("Invalid\n");
    else
        printf("%d\n",nth_x(&b,(top+1)/2));
}

int main()
{
    b=make_bost(100001);
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
