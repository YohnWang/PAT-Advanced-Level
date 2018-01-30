#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    double sum=0;
    int n;
    scanf("%d",&n);
    double a[100010];
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++)
    {
        long long int appear=1LL*i*(n-i+1);
        sum+=a[i]*appear;
    }
    printf("%.2lf",sum);
}
