#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct student
{
    int id;
    string name;
    int score;
};
void print(vector<student> &v)
{
    for(auto x:v)
    {
        printf("%.6d ",x.id);
        printf("%s ",x.name.c_str());
        printf("%d\n",x.score);
    }
}
int main()
{
    int N,C;
    scanf("%d%d",&N,&C);
    vector<student> v;
    for(int i=0;i<N;i++)
    {
        int id,score;
        char s[100];
        scanf("%d%s%d",&id,s,&score);
        v.push_back({id,s,score});
    }
    if(C==1)
        sort(v.begin(),v.end(),[](student &a,student &b)
                            {return a.id<b.id;});
    else if(C==2)
        sort(v.begin(),v.end(),[](student &a,student &b)
                            {if(a.name==b.name)return a.id<b.id;
                            else return a.name<b.name;});
    else if(C==3)
        sort(v.begin(),v.end(),[](student &a,student &b)
                            {if(a.score==b.score)return a.id<b.id;
                            else return a.score<b.score;});
    print(v);
}
