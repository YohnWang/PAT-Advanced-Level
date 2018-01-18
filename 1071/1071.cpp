#include<iostream>
#include<algorithm>
#include<map>
#include<cctype>
using namespace std;

map<string,int> v;

void lex(const string &s)
{
    int state=0;
    string out;
    for(auto c:s)
    {
        if(state==0&&isalnum(c))
        {
            state=1;
            if(isupper(c))
                c=tolower(c);
            out.push_back(c);
        }
        else if(state==1&&isalnum(c))
        {
            if(isupper(c))
                c=tolower(c);
            out.push_back(c);
        }
        else if(state==1)
        {
            v[out]++;
            state=0;
            out.clear();
        }
    }
}

int main()
{
    string s;
    getline(cin,s);
    s.push_back('.');
    lex(s);
    string maxstr;
    int maxnum{0};
    for(auto &x:v)
        if(x.second>maxnum || (x.second==maxnum&&x.first<maxstr))
        {
            maxstr=x.first;
            maxnum=x.second;
        }
    cout<<maxstr<<" "<<maxnum;
}
