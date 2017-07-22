#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree  *left,*right;
};
typedef struct tree tree;

tree* make_tree(tree *left,tree *right)
{
    tree *r=malloc(sizeof(*r));
    r->left=left;
    r->right=right;
    return r;
}

#define LEFT (2)
#define RIGHT (1)
int quick_table[500][500];//find the data at left or right of x;

void init_table(int post[],int order[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>j)
                quick_table[order[i]][order[j]]=LEFT;
            else if(i<j)
                quick_table[order[i]][order[j]]=RIGHT;
        }
    }
}

tree* translate(int post[],int order[],int n)
{
    init_table(post,order,n);
    tree *root=NULL;
    for(int i=n-1;i>=0;i--)
    {
        tree *p=make_tree(NULL,NULL);
        p->data=post[i];
        if(root==NULL)
            root=p;
        else
        {
            tree *r=root;
            while(r!=NULL)
            {
                if(quick_table[r->data][p->data]==LEFT)
                {
                    if(r->left!=NULL)
                    {
                        r=r->left;
                    }
                    else
                    {
                        r->left=p;
                        break;
                    }
                }
                else if(quick_table[r->data][p->data]==RIGHT)
                {
                    if(r->right!=NULL)
                    {
                        r=r->right;
                    }
                    else
                    {
                        r->right=p;
                        break;
                    }
                }
                else
                {
                    printf("Error\n");
                }
            }
        }
    }
    return root;
}

void level(tree *t,int a[])
{
    tree* queue[1024];
    tree *r=t;
    int cnt=0;
    int front=0,rear=0;
    queue[rear++]=t;
    while(front!=rear) //if queue isn't empty
    {
        tree *p=queue[front++]; //dequeue
        //printf("");
        a[cnt++]=p->data;
        if(p->left!=NULL)
            queue[rear++]=p->left; //enqueue
        if(p->right!=NULL)
            queue[rear++]=p->right; //enqueue

    }

}

int main(int argc,char *argv[])
{
    int n;
    scanf("%d",&n);
    int post[500];
    int order[500];
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&order[i]);
    tree *root=translate(post,order,n);
    int a[500];
    level(root,a);
    printf("%d",a[0]);
    for(int i=1;i<n;i++)
        printf(" %d",a[i]);
    return 0;
}
