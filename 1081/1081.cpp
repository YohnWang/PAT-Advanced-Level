#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct fraction
{
    int numerator;
    int denominator;
};

fraction operator+(fraction a,fraction b)
{
    //a and b -> x/y
    auto x1=a.numerator;
    auto y1=a.denominator;
    auto x2=b.numerator;
    auto y2=b.denominator;
    long long int xx=x1*y2+x2*y1;
    long long int yy=y1*y2;
    for(int i=2;i<65536;i++)
    {
        if(xx%i==0&&yy%i==0)
        {
            xx=xx/i;
            yy=yy/i;
            i=1;
        }
    }
    return {xx,yy};
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<fraction> v;
    fraction sum{0,1};
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d/%d",&x,&y);
        sum=sum+fraction{x,y};
    }
    int z=sum.numerator/sum.denominator;
    int x=sum.numerator%sum.denominator;
    int y=sum.denominator;
    if(z==0&&x!=0)
        printf("%d/%d",x,y);
    else if(x!=0)
        printf("%d %d/%d",z,x,y);
    else
        printf("%d",z);
}
