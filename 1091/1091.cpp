#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<vector<int>>> v;
vector<vector<vector<int>>> visit;

void read(int M,int N,int L)
{
    v.resize(L);
    visit.resize(L);
    for(int i=0;i<L;i++)
    {
        v[i].resize(M);
        visit[i].resize(M);
        for(int j=0;j<M;j++)
        {
            v[i][j].resize(N);
            visit[i][j].resize(N,0);
            for(int k=0;k<N;k++)
                scanf("%d",&v[i][j][k]);
        }
    }
}

int in_range(int x,int y,int z)
{
    if(x>=0&&x<v[0][0].size()&&
       y>=0&&y<v[0].size()&&
       z>=0&&z<v.size())
        return 1;
    return 0;
}
using T=struct{int x,y,z;};
void should_push(queue<T> &q,T cor)
{
    if(in_range(cor.x,cor.y,cor.z)&&v[cor.z][cor.y][cor.x]==1
       &&visit[cor.z][cor.y][cor.x]==0)
    {
        q.push(cor);
        visit[cor.z][cor.y][cor.x]=1;
    }
}

int bfs(int x,int y,int z)
{

    queue<T> q;
    int cnt=0;
    q.push({x,y,z});
    visit[z][y][x]=1;
    while(!q.empty())
    {
        auto cor=q.front();
        q.pop();
        cnt++;
        //up
        T cu={cor.x,cor.y,cor.z+1};
        should_push(q,cu);
        //down
        T cd={cor.x,cor.y,cor.z-1};
        should_push(q,cd);
        //left
        T cl={cor.x,cor.y-1,cor.z};
        should_push(q,cl);
        //right
        T cr={cor.x,cor.y+1,cor.z};
        should_push(q,cr);
        //front
        T cf={cor.x+1,cor.y,cor.z};
        should_push(q,cf);
        //back
        T cb={cor.x-1,cor.y,cor.z};
        should_push(q,cb);
    }
    return cnt;
}

int count_core(int M,int N,int L,int T)
{
    int result=0;
    for(int i=0;i<L;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int k=0;k<N;k++)
            {
                if(in_range(k,j,i)&&v[i][j][k]==1
                   &&visit[i][j][k]==0)
                {
                    int r=bfs(k,j,i);
                    if(r>=T)
                        result+=r;
                }
            }
        }
    }
    return result;
}

int main()
{
    int M,N,L,T;
    scanf("%d%d%d%d",&M,&N,&L,&T);
    read(M,N,L);
    printf("%d",count_core(M,N,L,T));
}
