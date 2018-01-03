#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

struct student
{
    long long int id;
    int score;
    int local;
    int rank;
};

int main()
{
    vector<vector<student>> v;
    vector<student> finish;
    int N;
    cin>>N;
    int item=0;
    for(int i=0;i<N;i++)
    {
        int K;
        cin>>K;
        item+=K;
        v.push_back(vector<student>{});
        for(int j=0;j<K;j++)
        {
            long long int id;
            int score;
            cin>>id>>score;
            v[i].push_back({id,score,i+1,0});
        }
    }
    auto cmp=[](student &a,student &b)->bool
             {if(a.score==b.score)return a.id<b.id;else return a.score>b.score; };
    for(int i=0;i<N;i++)
        sort(begin(v[i]),end(v[i]),cmp);
    for(int i=0;i<N;i++)
    {
        int rank{1},_count{1};
        v[i][0].rank=rank;
        finish.push_back(v[i][0]);
        for(decltype(v[0].size()) j=1;j<v[i].size();j++)
        {
            if(v[i][j].score==v[i][j-1].score)
            {
                v[i][j].rank=rank;
                _count++;
            }
            else
            {
                rank+=_count;
                _count=1;
                v[i][j].rank=rank;
            }
            finish.push_back(v[i][j]);
        }
    }
    sort(begin(finish),end(finish),cmp);
    cout<<item<<endl;
    int rank{1},_count{1};
    printf("%013lld",finish[0].id);
    cout<<' '<<1<<' '<<finish[0].local<<' '<<finish[0].rank<<endl;
    for(int i=1;i<item;i++)
    {
        if(finish[i].score==finish[i-1].score)
            _count++;
        else
        {
            rank+=_count;
            _count=1;
        }
        printf("%013lld",finish[i].id);
        cout<<' '<<rank<<' '<<finish[i].local<<' '<<finish[i].rank<<endl;
    }
}
