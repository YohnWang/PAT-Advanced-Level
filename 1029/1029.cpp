#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
void input(vector<long int> &v)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long int x;
        scanf("%ld",&x);
        v.push_back(x);
    }
}
int main()
{
    vector<long int> a,b;
    input(a);
    input(b);
    vector<long int> c(a.size()+b.size());
    merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
    auto size=c.size()-1;
    printf("%ld",c[size/2]);;
}
