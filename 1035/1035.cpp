#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int N;
    cin>>N;
    using T=pair<string,string>;
    vector<T> v;
    for(int i=0;i<N;i++)
    {
        string name,password;
        cin>>name>>password;
        v.push_back({name,password});
    }
    vector<T> out;
    for(auto &x:v)
    {
        int flag=0;
        for(auto &c:x.second)
        {
            if(c=='1')
                {c='@';flag=1;}
            else if(c=='0')
                {c='%';flag=1;}
            else if(c=='l')
                {c='L';flag=1;}
            else if(c=='O')
                {c='o';flag=1;}
        }
        if(flag)
            out.push_back(x);
    }
    if(out.size()>0)
    {
        cout<<out.size()<<endl;
        for(auto &x:out)
            cout<<x.first<<" "<<x.second<<endl;
    }
    else if(N>1)
        cout<<"There are "<<N<<" accounts and no account is modified";
    else
        cout<<"There is 1 account and no account is modified";
}
