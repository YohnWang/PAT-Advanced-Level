#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    getchar();
    vector<string> v(N);
    int min_len=10000;
    for(int i=0;i<N;i++)
    {
        char s[1000];
        gets(s);
        v[i]=string(s);
        reverse(v[i].begin(),v[i].end());
        if(min_len>v[i].size())
            min_len=v[i].size();
    }
    string out;
    for(int i=0;i<min_len;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(v[j][i]!=v[j-1][i])
                goto END;
        }
        out.push_back(v[0][i]);
    }
END:
    reverse(out.begin(),out.end());
    printf("%s",out.c_str());
    if(out.size()==0)
        printf("nai");
}
