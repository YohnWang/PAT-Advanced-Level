#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print(int i)
{
    switch(i)
    {
    case 0:
        printf("zero");
        break;
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    default:
        break;
    }
}
int main(int argc,char *argv[])
{
    char s[200];
    scanf("%s",s);
    int length=strlen(s);
    int sum=0;
    for(int i=0;i<length;i++)
        sum+=s[i]-'0';
    sprintf(s,"%d",sum);
    length=strlen(s);
    print(s[0]-'0');
    for(int i=1;i<length;i++)
    {
        printf(" ");
        print(s[i]-'0');
    }
    return 0;
}
