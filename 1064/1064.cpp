#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int power(int x,int y) //return x^y
{
    if(y==1)
        return x;
    else if(y==0)
        return 1;
    else if(y<0)
        return 0;
    else
        return power(x,y/2)*power(x,y-y/2);
}

//compute tree height and bottom node number
pair<int,int> compute_tree(int n)
{
    int height=floor(log(n)/log(2.0))+1;
    int bottom=n-(power(2,height-1)-1);
    return {height,bottom};
}

int left_num(int height,int bottom)
{
    int num=power(2,height-1)-1;//full
    int bot=power(2,height-2);
    if(bottom<bot)
        num-=bot-bottom;
    return num;
}

int left_node(int n)
{
    auto x=compute_tree(n);
    return left_num(x.first,x.second);
}

void process(vector<int> &v,vector<int> &out)
{
    queue<pair<int,int>> q;
    q.push({0,v.size()-1});
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        int num=x.second-x.first+1;
        int left=left_node(num);
        int right=num-left-1;
        out.push_back(v[x.first+left]);
        int ll=x.first,lr=x.first+left-1;
        int rl=lr+2,rr=x.second;
        if(left>0)
            q.push({ll,lr});
        if(right>0)
            q.push({rl,rr});
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    vector<int> out;
    process(v,out);
    printf("%d",out[0]);
    for(auto i=out.begin()+1;i!=out.end();i++)
        printf(" %d",*i);
}
