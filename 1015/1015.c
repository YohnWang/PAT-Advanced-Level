#include<stdio.h>
#include<stdlib.h>

int table[200000];
void select_prime(int a[],int range)
{
    a[0]=1;a[1]=1;
    for(int i=2;i<=range;i++)
    {
        for(int j=i+i;j<=range;j+=i)
            a[j]=1;
    }
}

int dtors(int s[],int d,int radix)
{
    int cnt=0;
    if(d==0)
        s[cnt++]=0;
    while(d!=0)
    {
        s[cnt]=d%radix;
        d/=radix;
        cnt++;
    }
    return cnt;
}

int stod(int s[],int n,int radix)
{
    int sum=0,r=1;
    for(int i=n-1;i>=0;i--)
    {
        sum+=r*s[i];
        r*=radix;
    }
    return sum;
}

int main()
{
    select_prime(table,100000);
    int N,D;
    scanf("%d",&N);
    while(N>=0)
    {
        scanf("%d",&D);
        int a[35];
        if(table[N]==0)
        {
            int n=dtors(a,N,D);
            int r=stod(a,n,D);
            if(table[r]==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
        {
            printf("No\n");
        }
        scanf("%d",&N);
    }
    return 0;
}
