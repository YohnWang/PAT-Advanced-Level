#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>



long long int trans(char s[],long long int r)
{
    long long int sr=0;
    long long int cnt=1;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(isdigit(s[i]))
        {
            if(s[i]-'0'>=r)
                return -1;
            sr=(s[i]-'0')*cnt+sr;
        }
        else
        {
            if(s[i]-'a'+10>=r)
                return -1;
            sr=(s[i]-'a'+10)*cnt+sr;
        }
        cnt*=r;
    }
    if(sr<0)
        return -2;
    return sr;
}


long long int find(long long sr,char tar[],long long int begin,long long int end)
{
    long long int center=begin+(end-begin)/2;
    if(begin<=end)
    {
        long long tmp=trans(tar,center);
        if(tmp==-1)
            return find(sr,tar,center+1,end);
        else if(tmp==-2)
            return find(sr,tar,begin,center-1);
        else if(tmp>sr)
            return find(sr,tar,begin,center-1);
        else if(tmp<sr)
            return find(sr,tar,center+1,end);
        else
            return center;
    }
    return -1;

}

long long int find_radix(char src[],int r,char tar[])
{
    long long int sr=trans(src,r);
    return find(sr,tar,1,sr+1);
}

int main(int argc,char *argv[])
{
    char N1[20],N2[20];
    int tag,radix;
    long long r;
    //char radixc;
    scanf("%s%s%d%d",N1,N2,&tag,&radix);
    if(tag==1)
        r=find_radix(N1,radix,N2);
    else
        r=find_radix(N2,radix,N1);
    if(r==-1)
        printf("Impossible");
    else
        printf("%lld",r);
    return 0;
}
