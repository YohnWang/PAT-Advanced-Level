#include<stdio.h>
#include<stdlib.h>

struct
{
    int data;
    int next;
}a[200000]={[0 ... 199999]={0,-1}}; //notice the the list head point is -1
int look[20000];
const int OUT1=199999;
const int OUT2=199998;

void process()
{
    int prv=OUT1;
    int p=a[prv].next;
    int sprv=OUT2;//if the next of a is not initialized,there must be a[sprv].next=-1
    while(p!=-1)
    {
        if(look[abs(a[p].data)]==0)
        {
            look[abs(a[p].data)]=1;
            p=a[p].next;
            prv=a[prv].next;
        }
        else
        {
            a[prv].next=a[p].next;
            a[sprv].next=p;
            sprv=p;
            a[sprv].next=-1;
            p=a[prv].next;
        }
    }
}

void print_addr(int addr)
{
    if(addr==-1)
        printf("-1");
    else
        printf("%.5d",addr);
}

void print_node(int addr)
{
    print_addr(addr);
    printf(" %d ",a[addr].data);
    print_addr(a[addr].next);
    printf("\n");
}

void print_list(int h)
{
    int p=h;
    while(p!=-1)
    {
        print_node(p);
        p=a[p].next;
    }
}

int main()
{
    int head,n;
    scanf("%d%d",&head,&n);
    a[OUT1].next=head;
    for(int i=0;i<n;i++)
    {
        int addr,data,next;
        scanf("%d%d%d",&addr,&data,&next);
        a[addr].data=data;
        a[addr].next=next;
    }
    process();
    print_list(a[OUT1].next);
    print_list(a[OUT2].next);
}
