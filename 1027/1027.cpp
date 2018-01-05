#include<iostream>
#include<algorithm>
using namespace std;

void print(int x)
{
    if(x<10)
        cout<<x;
    else
        cout<<char('A'+x-10);
}
void radix(int x)
{
    int r=x/13;
    int b=x-r*13;
    print(r);
    print(b);
}

int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    cout<<"#";
    radix(r);
    radix(g);
    radix(b);
}
