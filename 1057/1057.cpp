#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;
vector<int> s;

class Media
{
private:
    multiset<int,less<int>> Max;
    multiset<int,greater<int>> Min;
public:
    void push(int x)
    {
        if(Min.size()<=Max.size())
            Min.insert(x);
        else
            Max.insert(x);
    }
    void erase(int x)
    {
        auto iter=Max.find(x);
        if(iter!=Max.end())
            Max.erase(iter);
        else
            Min.erase(Min.find(x));
    }
    int median()
    {
        auto size=Max.size()+Min.size();
        auto Minsize=(size+1)/2;
        auto Maxsize=size-Minsize;
        //adjust size of Max and Min
        while(Min.size()<Minsize)
        {
            auto iter=Max.begin();
            auto x=*iter;
            Min.insert(x);
            Max.erase(iter);
        }
        while(Max.size()<Maxsize)
        {
            auto iter=Min.begin();
            auto x=*iter;
            Max.insert(x);
            Min.erase(iter);
        }
        //adjust value of Max and Min
        if(Max.size()==0)
            return *Min.begin();
        while(*Min.begin()>*Max.begin())
        {
            auto x=*Min.begin();
            auto y=*Max.begin();
            Min.erase(Min.begin());
            Max.erase(Max.begin());
            Min.insert(y);
            Max.insert(x);
        }
        return *Min.begin();
    }
};

Media M;

void pop()
{
    if(s.empty())
        printf("Invalid\n");
    else
    {
        int x=s.back();
        printf("%d\n",x);
        s.pop_back();
        M.erase(x);
    }
}

void push()
{
    int key;
    cin>>key;
    s.push_back(key);
    M.push(key);
}

void peekmedian()
{
    if(s.empty())
        printf("Invalid\n");
    else
        printf("%d\n",M.median());
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[30];
        scanf("%s",op);
        if(op[1]=='o')
            pop();
        else if(op[1]=='e')
            peekmedian();
        else if(op[1]=='u')
            push();
        else
            printf("Invalid\n");
    }
}
