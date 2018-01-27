#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int is_insert(vector<int> v,const vector<int> &vy)
{
    int i;
    for(i=1;i<vy.size();i++)
        if(vy[i]<vy[i-1])
            break;
    for(int j=i;j<vy.size();j++)
        if(vy[j]!=v[j])
            return -1;
    return i;
}

void merge_step(vector<int> &v,int step)
{
    auto start=v.begin();
    int i=0;
    for(i=0;i+step<=v.size();i+=step)
        sort(start+i,start+i+step);
    sort(start+i,v.end());
}

void print(vector<int> &v)
{
    printf("%d",v[0]);
    for(int i=1;i<v.size();i++)
        printf(" %d",v[i]);
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
    auto flag=is_insert(vx,vy);
    if(flag!=-1)
    {
        printf("Insertion Sort\n");
        sort(vy.begin(),vy.begin()+flag+1);
        print(vy);
    }
    else
    {
        printf("Merge Sort\n");
        int i;
        for(i=1;vx!=vy;i*=2)
            merge_step(vx,i);
        merge_step(vx,i);
        print(vx);
    }
}
