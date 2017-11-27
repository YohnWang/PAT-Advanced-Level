#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char g[100][100]={[0 ... 80]={[0 ... 80]=' '}};
int main(int argc,char *argv[])
{
    char s[1200];
    scanf("%s",s);
    int n=strlen(s);
    int h=(n+2)/3;
    int b=n-h*2+1;
    int count=0;
    for(int i=0;i<h;i++)
        g[i][0]=s[count++];
    for(int j=1;j<=b;j++)
        g[h-1][j]=s[count++];
    for(int k=h-2;k>=0;k--)
        g[k][b]=s[count++];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<b+1;j++)
                printf("%c",g[i][j]);
        printf("\n");
    }
}
