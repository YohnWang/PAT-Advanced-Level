#include<stdio.h>
#include<stdlib.h>

struct T
{
    int data;
    int next;
} arr[100010];

int postion[100010];
int top=0;

int list_len(int head)
{
    int count=0;
    int p=head;
    while(p!=-1)
    {
        count++;
        p=arr[p].next;
    }
    return count;
}

void print_addr(int addr)
{
    if(addr==-1)
        printf("%d",addr);
    else
        printf("%.5d",addr);
}

void print_node(int p)
{
    print_addr(p);
    printf(" %d ",arr[p].data);
    print_addr(arr[p].next);
    printf("\n");
}

void print_list(int head)
{
    int p=head;
    while(p!=-1)
    {
        print_node(p);
        p=arr[p].next;
    }
}

//three pointers,ins meads insert next position after it
//tail means the head of reverse list
//h means the head of list waiting reversing
void list_part_rev(int k)
{
    int len=list_len(arr[100010-1].next);
    int ins=100010-1;
    while(len>=k)
    {
        int end=arr[ins].next;
        int tail=end;
        int h=arr[tail].next;
        for(int i=0;i<k-1;i++)
        {
            int next=arr[h].next;
            arr[ins].next=h;
            arr[h].next=tail;
            tail=h;
            h=next;
        }
        len-=k;
        arr[end].next=h;
        ins=end;
    }
}

int main(int argc,char *argv[])
{
    int head,N,K;
    scanf("%d%d%d",&head,&N,&K);
    for(int i=0;i<N;i++)
    {
        int addr,data,next;
        scanf("%d%d%d",&addr,&data,&next);
        arr[addr].data=data;
        arr[addr].next=next;
    }
    arr[100010-1].next=head;
    list_part_rev(K);
    print_list(arr[100010-1].next);
}
