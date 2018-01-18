#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

bool is_equal(const string &s)
{
    auto c=s[0];
    for(auto x:s)
        if(x!=c)
            return false;
    return true;
}

void to_fill(string &s)
{
    while(s.size()<4)
        s.push_back('0');
}

int main()
{
    char c[200];
    scanf("%s",c);
    string s(c);
    to_fill(s);
    if(is_equal(s))
    {
        printf("%s - %s = 0000\n",s.c_str(),s.c_str());
        return 0;
    }
    int state=1;
    while(state||(stoi(s)!=6174&&stoi(s)!=0))
    {
        state=0;
        string t=s;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end(),[](char a,char b){return a>b;});
        int a=stoi(t);
        int b=stoi(s);
        int r=a-b;
        string rs=to_string(r);
        to_fill(rs);
        printf("%s - %s = %.4d\n",t.c_str(),s.c_str(),r);
        s=rs;
    }
}
