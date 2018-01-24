#include<stdio.h>
#include<stdlib.h>

int hash_table[20000]={[0 ... 19999]=-1};
int primer[20000];
int output[20000];
int top=0;

void select()
{
    primer[0]=primer[1]=1;
    for(int i=2;i<20000;i++)
        for(int j=i+i;j<20000;j+=i)
            primer[j]=1;
}

int bigger(int n)
{
    int i;
    for(i=n;i<20000;i++)
        if(primer[i]==0)
            return i;
    return -1;
}

void print(int x)
{
    if(x==-1)
        printf("-");
    else
        printf("%d",x);
}

int main(int argc,char *argv[])
{
    select();
    int Msize,N;
    scanf("%d%d",&Msize,&N);
    Msize=bigger(Msize);
    for(int i=0;i<N;i++)
    {
        int x;
        scanf("%d",&x);
        int index=x%Msize;
        if(hash_table[index]==-1)
        {
            hash_table[index]=x;
            output[top++]=index;
        }
        else
        {
            int flag=0;
            for(int j=1;j<Msize;j++)
            {
                index=(x+j*j)%Msize;
                if(hash_table[index]==-1)
                {
                    hash_table[index]=x;
                    output[top++]=index;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                output[top++]=-1;
        }
    }
    print(output[0]);
    for(int i=1;i<top;i++)
    {
        printf(" ");
        print(output[i]);
    }
}
