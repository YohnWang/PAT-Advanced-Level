#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

bool is_pop(int N,int M,vector<int> &v)
{
    stack<int> s;
    int cnt=1;
    for(auto &x:v)
    {
        if(s.empty()||s.top()<x)
        {
            s.push(cnt++);
            while(s.top()<x)
                s.push(cnt++);
            if(s.size()>static_cast<unsigned int>(M))
                return false;
            s.pop();
        }
        else if(s.top()>x)
            return false;
        else
            s.pop();
    }
    return true;
}

int main()
{
    int M,N,K;
    scanf("%d%d%d",&M,&N,&K);
    for(int i=0;i<K;i++)
    {
        vector<int> v;
        for(int j=0;j<N;j++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        if(is_pop(N,M,v))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
