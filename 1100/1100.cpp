#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;

const char *low[]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
const char *high[]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int find_low(char s[])
{
    for(int i=0;i<sizeof(low)/sizeof(low[0]);i++)
    {
        if(strcmp(s,low[i])==0)
            return i;
    }
    return -1;
}

int find_high(char s[])
{
    for(int i=0;i<sizeof(high)/sizeof(high[0]);i++)
    {
        if(strcmp(s,high[i])==0)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char s[100]={0};
        gets(s);
        if(isdigit(s[0]))//Earth
        {
            int x;
            sscanf(s,"%d",&x);
            int l=x%13;
            int r=x/13;
            if(r!=0&&l!=0)
                printf("%s %s\n",high[r],low[l]);
            else if(r==0)
                printf("%s\n",low[l]);
            else if(r!=0)
                printf("%s\n",high[r]);
        }
        else  //Mars
        {
            char s1[10]={0},s2[10]={0};
            sscanf(s,"%s%s",s1,s2);
            if(s2[0]!='\0')
            {
                int l=find_low(s2);
                int r=find_high(s1);
                printf("%d\n",13*r+l);
            }
            else
            {
                int l=find_low(s1);
                int r=find_high(s1);
                if(l!=-1)
                    printf("%d\n",l);
                else if(r!=-1)
                    printf("%d\n",r*13);
            }
        }
    }
}
