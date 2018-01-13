#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct T
{
    int key;
    int addr;
    int next;
    T(int addr,int key,int next):key{key},addr{addr},next{next}{}
    bool operator<(T x){return key<x.key;}
};

struct L
{
    int key;
    int next;
};
L table[1000020];

int main()
{
    vector<T> v;
    int n,start;
    scanf("%d%d",&n,&start);
    if(start==-1)
    {
        printf("%d %d",0,-1);
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int key,addr,next;
        scanf("%d%d%d",&addr,&key,&next);
        table[addr].key=key;
        table[addr].next=next;
    }
    int p=start;
    while(p!=-1)
    {
        int key=table[p].key,addr=p,next=table[p].next;
        v.push_back({addr,key,next});
        p=next;
    }
    sort(v.begin(),v.end());
    printf("%llu %.5d\n",v.size(),v[0].addr);
    for(auto i=v.begin();i!=v.end()-1;i++)
        printf("%.5d %d %.5d\n",i->addr,i->key,(i+1)->addr);
    printf("%.5d %d %d\n",v.rbegin()->addr,v.rbegin()->key,-1);
}
