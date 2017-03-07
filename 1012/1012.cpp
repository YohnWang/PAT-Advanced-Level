#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct student
{
    int id;
    int C;
    int M;
    int E;
    int A;
};

struct what
{
    int i;
    int rank;
    what():i(0),rank(0){}
    what(int a,int b){i=a;rank=b;}
};

int main(int argc,char *argv[])
{
    vector<student> v,v1,v2,v3,v4;
    map<int,what> Map;
    int N,M;
    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        int id,c,m,e,a;
        cin>>id>>c>>m>>e;
        a=c+m+e;
        v.push_back({id,c,m,e,a});
    }
    v1=v2=v3=v4=v;
    stable_sort(v1.begin(),v1.end(),[](student a,student b){return a.C>b.C;});
    stable_sort(v2.begin(),v2.end(),[](student a,student b){return a.M>b.M;});
    stable_sort(v3.begin(),v3.end(),[](student a,student b){return a.E>b.E;});
    stable_sort(v4.begin(),v4.end(),[](student a,student b){return a.A>b.A;});

    int cnt=1,inc=1;
    for(auto i=v3.begin();i!=v3.end();i++)//E
    {
        Map[i->id]={3,cnt};
        if((i+1)->E==i->E)
            inc++;
        else
        {
            cnt+=inc;
            inc=1;
        }

    }
    cnt=1;inc=1;
    for(auto i=v2.begin();i!=v2.end();i++)//M
    {
        if(Map[i->id].rank>=cnt)
            Map[i->id]={2,cnt};
        if((i+1)->M==i->M)
            inc++;
        else
        {
            cnt+=inc;
            inc=1;
        }
    }
    cnt=1;inc=1;
    for(auto i=v1.begin();i!=v1.end();i++)//C
    {

        if(Map[i->id].rank>=cnt)
            Map[i->id]={1,cnt};
        if((i+1)->C==i->C)
            inc++;
        else
        {
            cnt+=inc;
            inc=1;
        }
    }

    cnt=1;inc=1;
    for(auto i=v4.begin();i!=v4.end();i++)//A
    {
        if(Map[i->id].rank>=cnt)
            Map[i->id]={4,cnt};
        if((i+1)->A==i->A)
            inc++;
        else
        {
            cnt+=inc;
            inc=1;
        }
    }
    char table[]={0,'C','M','E','A'};
    for(int i=0;i<M;i++)
    {
        int id;
        cin>>id;
        if(Map[id].rank!=0)
            cout<<Map[id].rank<<" "<<table[Map[id].i]<<endl;
        else
            cout<<"N/A"<<endl;
    }
    return 0;
}
