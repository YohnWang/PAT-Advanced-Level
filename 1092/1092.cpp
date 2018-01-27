#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int count(char s[],map<char,int> &m)
{
    int cnt=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(isalnum(s[i]))
        {
            m[s[i]]++;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    char s[2000];
    map<char,int> mb,mw;
    scanf("%s",s);
    auto all=count(s,mb);
    scanf("%s",s);
    count(s,mw);
    int have=0,need=0;
    for(auto x:mw)
    {
        need+=x.second;
        if(mb[x.first]<x.second)
            have+=mb[x.first];
        else
            have+=x.second;
    }
    if(have<need)
        printf("No %d",need-have);
    else
        printf("Yes %d",all-need);
}
