#include<stdio.h>
#include<math.h>
const char *number[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
const char *carry[]={NULL,"Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
struct T
{
    int num;
    int car;
} output[100];
int top=0;

//finite state machine
void analyse(int x)
{
    char s[20];
    int len=sprintf(s,"%d",x);
    int state=0;
    int cnt=0;
    for(int i=len-1;i>=0;i--)
    {
        if(state==0)
        {
            if(s[i]=='0')
                state=0;
            else
            {
                if(cnt>=5&&cnt<=7)
                {
                    output[top].num=-1;
                    output[top].car=4;
                    top++;
                }
                output[top].num=s[i]-'0';
                output[top].car=cnt;
                top++;
                state=1;
            }
        }
        else if(state==1)
        {
            if(s[i]=='0')
                state=2;
            else
            {
                output[top].num=s[i]-'0';
                output[top].car=cnt;
                top++;
                state=1;
            }
        }
        else if(state==2)
        {
            if(s[i]=='0')
                state=2;
            else
            {
                output[top].num=0;
                output[top].car=cnt;
                top++;
                if(cnt>8)
                {
                    output[top].num=-1;
                    output[top].car=8;
                    top++;
                }
                else if(cnt>4&&cnt!=8)
                {
                    output[top].num=-1;
                    output[top].car=4;
                    top++;
                }
                output[top].num=s[i]-'0';
                output[top].car=cnt;
                top++;
                state=1;
            }
        }
        cnt++;
    }
}

void print()
{
    if(carry[output[top-1].car]==NULL)
        printf("%s",number[output[top-1].num]);
    else
        printf("%s %s",number[output[top-1].num],carry[output[top-1].car]);
    for(int i=top-2;i>=0;i--)
    {
        if(output[i].num==0)
            printf(" %s",number[0]);
        else if(output[i].num==-1)
            printf(" %s",carry[output[i].car]);
        else if(carry[output[i].car]!=NULL)
            printf(" %s %s",number[output[i].num],carry[output[i].car]);
        else
            printf(" %s",number[output[i].num]);
    }
}

int main()
{
    int x;
    scanf("%d",&x);
    if(x==0)
    {
        printf("ling");
        return 0;
    }
    if(x<0)
        printf("Fu ");
    analyse(abs(x));
    print();
}
