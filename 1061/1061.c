#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int is_week(char c)
{
    if(c>='A'&&c<='G')
        return c-'A'+1;
    return 0;
}

int is_time(char c)
{
    if(isdigit(c))
        return c-'0';
    else if(c>='A'&&c<='N')
        return c-'A'+10;
    else
        return -1;
}

void print_week(int th)
{
    char *s[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    printf("%s",s[th-1]);
}

int main(int argc,char *argv[])
{
    char s1[100],s2[100],s3[100],s4[100];
    scanf("%s%s%s%s",s1,s2,s3,s4);
    int i=0,j=0;
    while(s1[i]!=s2[i]||!is_week(s1[i])){i++;}
    print_week(is_week(s1[i]));
    printf(" ");
    i++;
    while(s1[i]!=s2[i]||is_time(s1[i])==-1){i++;}
    printf("%.2d:",is_time(s1[i]));
    while(s3[j]!=s4[j]||!isalpha(s3[j])){j++;}
    printf("%.2d",j);
}
