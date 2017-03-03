#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polynomial
{
    int power;
    double factor;
};
typedef struct polynomial polynomial;

int add(polynomial a[],int ak,polynomial b[],int bk,polynomial c[])
{
    int i=0,j=0,k=0;
    while(i<ak && j<bk)
    {
        if(a[i].power==b[j].power)
        {
            double dx=a[i].factor+b[j].factor;
            if(!(fabs(dx)<0.00001))
            {
                c[k].power=a[i].power;
                c[k].factor=dx;
                k++;
            }
            i++;j++;
        }
        else if(a[i].power>b[j].power)
        {
            c[k].power=a[i].power;
            c[k].factor=a[i].factor;
            if(!(fabs(c[k].factor)<0.0000001))
                k++;
            i++;
        }
        else
        {
            c[k].power=b[j].power;
            c[k].factor=b[j].factor;
            if(!(fabs(c[k].factor)<0.0000001))
                k++;
            j++;
        }
    }
    while(i<ak)
    {
        c[k].power=a[i].power;
        c[k].factor=a[i].factor;
        i++;k++;
    }
    while(j<bk)
    {
        c[k].power=b[j].power;
        c[k].factor=b[j].factor;
        j++;k++;
    }
    return k;
}

int _mul(polynomial a[],int ak,polynomial x,polynomial c[])
{
    for(int i=0;i<ak;i++)
    {
        c[i].factor=x.factor*a[i].factor;
        c[i].power=x.power+a[i].power;
    }
    return ak;
}

int mul(polynomial a[],int ak,polynomial b[],int bk,polynomial c[])
{
    polynomial tmp[200],cx[200];
    int i=0,j=0,k=0;
    for(int i=0;i<bk;i++)
    {
        int tk=_mul(a,ak,b[i],tmp);
        k=add(tmp,tk,c,k,cx);
        for(int j=0;j<k;j++)
            c[j]=cx[j];
    }
    return k;
}

int main(int argc,char *argv[])
{
    polynomial a[100],b[100],c[200];
    int ak,bk,ck;
    scanf("%d",&ak);
    for(int i=0;i<ak;i++)
        scanf("%d%lf",&a[i].power,&a[i].factor);
    scanf("%d",&bk);
    for(int i=0;i<bk;i++)
        scanf("%d%lf",&b[i].power,&b[i].factor);
    ck=mul(a,ak,b,bk,c);
    printf("%d",ck);
    for(int i=0;i<ck;i++)
        printf(" %d %.1f",c[i].power,c[i].factor);
    return 0;
}
