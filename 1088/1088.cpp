#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

//implement x/y
struct T
{
    long long int x;
    long long int y;
};

long long int gcd(long long int a,long long int b)
{
    if(b!=0)
        return gcd(b,a%b);
    return a;
}

void adjust(T &a)
{
    if((a.x<0&&a.y<0) || (a.x>0&&a.y<0))
    {
        a.x=-a.x;
        a.y=-a.y;
    }
    auto g=gcd(llabs(a.x),a.y);
    a.x/=g;
    a.y/=g;
}

T operator+(T a,T b)
{
    T r;
    r.x=a.x*b.y+a.y*b.x;
    r.y=a.y*b.y;
    adjust(r);
    return r;
}

T operator-(T a,T b)
{
    T r;
    r.x=a.x*b.y-a.y*b.x;
    r.y=a.y*b.y;
    adjust(r);
    return r;
}

T operator*(T a,T b)
{
    T r;
    r.x=a.x*b.x;
    r.y=a.y*b.y;
    adjust(r);
    return r;
}

T operator/(T a,T b)
{
    T r;
    r.x=a.x*b.y;
    r.y=a.y*b.x;
    adjust(r);
    return r;
}

void printT(T a)
{
    adjust(a);
    if(a.y==0)
        printf("Inf");
    else
    {
        if(a.x==0)
            printf("0");
        else if(a.x>0)
        {
            auto z=a.x/a.y;
            auto x=a.x%a.y;
            if(z!=0 && x!=0)
                printf("%lld %lld/%lld",z,x,a.y);
            else if(z==0 && x!=0)
                printf("%lld/%lld",x,a.y);
            else if(z!=0 && x==0)
                printf("%lld",z);
            else
                printf("0");
        }
        else
        {
            printf("(");
            auto z=a.x/a.y;
            auto x=a.x%a.y;
            if(z!=0 && x!=0)
                printf("%lld %lld/%lld",z,-x,a.y);
            else if(z==0 && x!=0)
                printf("%lld/%lld",x,a.y);
            else if(z!=0 && x==0)
                printf("%lld",z);
            else
                printf("0");
            printf(")");
        }
    }
}

int main()
{
    int x,y;
    T a,b;
    scanf("%d/%d",&x,&y);
    a=T{x,y};
    scanf("%d/%d",&x,&y);
    b=T{x,y};

    printT(a);
    printf(" + ");
    printT(b);
    printf(" = ");
    printT(a+b);
    printf("\n");

    printT(a);
    printf(" - ");
    printT(b);
    printf(" = ");
    printT(a-b);
    printf("\n");

    printT(a);
    printf(" * ");
    printT(b);
    printf(" = ");
    printT(a*b);
    printf("\n");

    printT(a);
    printf(" / ");
    printT(b);
    printf(" = ");
    printT(a/b);
    printf("\n");

}
