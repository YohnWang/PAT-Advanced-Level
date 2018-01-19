#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct T
{
    char c;
    int next;
};

T arr[2000000];

int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    for(int i=0;i<n;i++)
    {
        int addr,next;
        char c;
        scanf("%d %c %d",&addr,&c,&next);
        arr[addr].c=c;
        arr[addr].next=next;
    }
    vector<int> addr1,addr2;
    int p=a;
    while(p!=-1)
    {
        addr1.push_back(p);
        p=arr[p].next;
    }
    p=b;
    while(p!=-1)
    {
        addr2.push_back(p);
        p=arr[p].next;
    }
    int r=-1;
    if(addr1.size()&&addr2.size())
    {
        auto iter1=addr1.rbegin();
        auto iter2=addr2.rbegin();
        while(iter1!=addr1.rend()&&iter2!=addr2.rend()&&*iter1==*iter2)
        {
            r=*iter1;
            iter1++;
            iter2++;
        }
    }
    if(r!=-1)
        printf("%.5d",r);
    else
        printf("%d",r);
}
