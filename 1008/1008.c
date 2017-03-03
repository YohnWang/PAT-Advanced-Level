#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int a[200];
    int n;
    a[0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int total=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])
            total+=(a[i]-a[i-1])*6+5;
        else
            total+=(a[i-1]-a[i])*4+5;
    }
    printf("%d",total);
    return 0;
}
