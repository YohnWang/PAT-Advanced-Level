#include<stdio.h>
#include<stdlib.h>

int table[1000][1000];
int visit[1000][1000];
int a[20000];
int n;
int x,y; //matrix

int cmp(const void *a,const void *b)
{
    const int *x=a,*y=b;
    return *y-*x;
}

void findxy()
{
    int min=100000;
    for(int i=100;i>0&&i>=n/i; i--)
    {
        if(n%i==0 && i-n/i<min)
        {
            x=i;
            y=n/x;
            min=i-n/i;
        }
    }
}
enum {LEFT,RIGHT,UP,DOWN};
void move()
{
    int state=RIGHT;
    int r=0,c=0;
    for(int i=0; i<n; i++)
    {
        visit[r][c]=1;
        table[r][c]=a[i];
        if(state==RIGHT)
        {
            if(c+1>=y||visit[r][c+1]!=0)
            {
                state=DOWN;
                r=r+1;
            }
            else
                c=c+1;
        }
        else if(state==DOWN)
        {
            if(r+1>=x||visit[r+1][c]!=0)
            {
                state=LEFT;
                c=c-1;
            }
            else
                r=r+1;
        }
        else if(state==LEFT)
        {
            if( c-1<0||visit[r][c-1]!=0)
            {
                state=UP;
                r=r-1;
            }
            else
                c=c-1;
        }
        else if(state==UP)
        {
            if(r-1<0||visit[r-1][c]!=0)
            {
                state=RIGHT;
                c=c+1;
            }
            else
                r=r-1;
        }
    }
}

void print()
{
    for(int i=0; i<x; i++)
    {
        printf("%d",table[i][0]);
        for(int j=1; j<y; j++)
            printf(" %d",table[i][j]);
        printf("\n");
    }
}

int main(int argc,char *argv[])
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    qsort(a,n,4,cmp);
    findxy();
    move();
    print();
}
