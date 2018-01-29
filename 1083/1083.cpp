#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct T
{
    string name;
    string id;
    int grade;
};

void print(T &x)
{
    printf("%s %s\n",x.name.c_str(),x.id.c_str());
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<T> v;
    for(int i=0;i<n;i++)
    {
        char s[100],t[100];
        int grade;
        scanf("%s%s%d",s,t,&grade);
        v.push_back({s,t,grade});
    }
    int low,high;
    scanf("%d%d",&low,&high);
    sort(v.begin(),v.end(),[](T &a,T&b){return a.grade>b.grade;});
    int flag=0;
    for(auto &x:v)
    {
        if(x.grade>=low && x.grade<=high)
        {
            print(x);
            flag=1;
        }
    }
    if(flag==0)
        printf("NONE");
}
