#include<stdio.h>
#include<math.h>

struct polynomial
{
    double power;
    double factor;
};
typedef struct polynomial polynomial;

int add(polynomial a[],int ak,polynomial b[],int bk,polynomial c[])
{
    int i=0,j=0,ck=0;
    while(i<ak && j<bk)
    {
        if(fabs(a[i].power-b[j].power)<0.000001)
        {
            c[ck].power=a[i].power;
            c[ck].factor=a[i].factor+b[j].factor;
            if(!(fabs(c[ck].factor)<0.0000001))
                ck++;
            i++;j++;
        }
        else if(a[i].power<b[j].power)
        {
            c[ck].power=b[j].power;
            c[ck].factor=b[j].factor;
            ck++;j++;
        }
        else
        {
            c[ck].power=a[i].power;
            c[ck].factor=a[i].factor;
            ck++;i++;
        }
    }
    while(i<ak)
    {
        c[ck].power=a[i].power;
        c[ck].factor=a[i].factor;
        ck++;i++;
    }
    while(j<bk)
    {
        c[ck].power=b[j].power;
        c[ck].factor=b[j].factor;
        ck++;j++;
    }
    return ck;
}

int main(int argc,char *argv[])
{
    polynomial a[100],b[100],c[100];
    int ak,bk,ck;
    scanf("%d",&ak);
    for(int i=0;i<ak;i++)
        scanf("%lf%lf",&a[i].power,&a[i].factor);
    scanf("%d",&bk);
    for(int i=0;i<bk;i++)
        scanf("%lf%lf",&b[i].power,&b[i].factor);
    ck=add(a,ak,b,bk,c);
    printf("%d",ck);
    for(int i=0;i<ck;i++)
        printf(" %g %.1f",c[i].power,c[i].factor);
    return 0;
}
