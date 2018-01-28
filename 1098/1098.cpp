#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int is_insert(vector<int> &vx,vector<int> &vy)
{
    int i;
    for(i=0;i<vy.size()-1 && vy[i]<=vy[i+1];i++){}
    for(int j=i+1;j<vy.size();j++)
        if(vy[j]!=vx[j])
            return -1;
    return i+1;
}

void heap_step(vector<int> &v,int unsorted)
{
    pop_heap(v.begin(),v.begin()+unsorted);
}

void print(vector<int> &v)
{
    if(v.size()!=0)
        printf("%d",v[0]);
    for(auto iter=v.begin()+1;iter!=v.end();iter++)
        printf(" %d",*iter);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> vx(n),vy(n);
    for(int i=0;i<n;i++)
        scanf("%d",&vx[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&vy[i]);
    auto end=is_insert(vx,vy);
    if(end!=-1)
    {
        printf("Insertion Sort\n");
        sort(vy.begin(),vy.begin()+end+1);
        print(vy);
    }
    else
    {
        printf("Heap Sort\n");
        make_heap(vx.begin(),vx.end());
        auto un=vx.size();
        while(vx!=vy)
            heap_step(vx,un--);
        heap_step(vx,un--);
        print(vx);
    }
}
