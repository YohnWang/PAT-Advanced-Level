#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct T
{
    string name;
    char gender;
    string id;
    int grade;
};
int main()
{
    int n;
    scanf("%d",&n);
    vector<T> male,female;
    for(int i=0;i<n;i++)
    {
        char name[20],id[20];
        char gender;
        int grade;
        scanf("%s %c %s %d",name,&gender,id,&grade);
        if(gender=='M')
            male.push_back({name,gender,id,grade});
        else
            female.push_back({name,gender,id,grade});
    }
    sort(male.begin(),male.end(),[](T &a,T &b){return a.grade<b.grade;});
    sort(female.begin(),female.end(),[](T &a,T &b){return a.grade>b.grade;});
    int flag=0;
    if(female.size()==0)
    {
        printf("Absent\n");
        flag=1;
    }
    else
        printf("%s %s\n",female[0].name.c_str(),female[0].id.c_str());
    if(male.size()==0)
    {
        printf("Absent\n");
        flag=1;
    }
    else
        printf("%s %s\n",male[0].name.c_str(),male[0].id.c_str());
    if(flag)
        printf("NA\n");
    else
        printf("%d",female[0].grade-male[0].grade);
}
