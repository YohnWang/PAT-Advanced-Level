#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool cmp(string &a,string &b)
{
    decltype(a.size()) i=0,j=0;
    while(i<a.size()&&j<b.size())
    {
        if(a[i]<b[j])
            return true;
        else if(a[i]>b[j])
            return false;
        else
            i++,j++;

    }
    int ii=0;
    while(i<a.size())
    {
        if(a[i]<a[ii])
            return true;
        else if(a[i]>a[ii])
            return false;
        else
            i++,ii++;
    }
    int jj=0;
    while(j<b.size())
    {
        if(b[jj]<b[j])
            return true;
        else if(b[jj]>b[j])
            return false;
        else
            j++,jj++;
    }
    return a.size()>b.size();
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        char s[20];
        scanf("%s",s);
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    string out="";
    for(auto &str:v)
        out+=str;
    int state=0;
    for(auto x:out)
        if(state==0&&x!='0')
        {
            state=1;
            printf("%c",x);
        }
        else if(state==1)
            printf("%c",x);
    if(state==0)
        printf("0");
}
