#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
//vector type of unsigned char
typedef signed char Etype;

struct vector
{
    int size;
    int capacity;
    Etype *a;
};
typedef struct vector vector;

vector* vector_init(vector *v)
{
    v->size=0;
    v->capacity=2;
    v->a=malloc(v->capacity*sizeof(Etype));
    if(v->a==NULL)
        return NULL;
    return v;
}

void vector_del(vector *v)
{
    v->size=0;
    v->capacity=0;
    free(v->a);
    v->a=NULL;
}

void vector_push_back(vector *v,Etype e)
{
    if(v->size==v->capacity)
    {
        v->capacity+=v->capacity;
        Etype *replace=malloc(v->capacity*sizeof(Etype));
        memcpy(replace,v->a,v->size*sizeof(Etype));
        free(v->a);
        v->a=replace;
    }
    v->a[v->size++]=e;
}

void vector_pop_back(vector *v)
{
    if(v->size)
        v->size--;
}

Etype vector_at(vector *v,int position)
{
    return v->a[position];
}

int vector_size(vector *v)
{
    return v->size;
}

void vector_copy(vector *new,vector *v)
{
    new->size=v->size;
    new->capacity=v->capacity;
    new->a=malloc(new->capacity*sizeof(Etype));
    memcpy(new->a,v->a,new->size*sizeof(Etype));
}

//big number
typedef struct bgn bgn;
struct bgn
{
    char sign;
    vector v;
};

int bgn_assert(const char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(isdigit(s[i])||(i==0&&(s[i]=='+'||s[i]=='-')))
            continue;
        else
            return 0;
    }
    return i;
}

bgn bgn_new(const char s[])
{
    char s_end=bgn_assert(s);
    if(s_end==0)
        return bgn_new("0");
    else
    {
        bgn r;
        vector_init(&r.v);
        int begin=0,end=s_end-1;
        if(s[begin]=='-')
        {
            r.sign=1;
            begin++;
        }
        else if(s[begin]=='+')
        {
            r.sign=0;
            begin++;
        }
        else
            r.sign=0;
        while(s[begin]=='0'){begin++;}
        if(begin>end)
        {
            r.sign=0;
            vector_push_back(&r.v,0);
        }
        for(;end>=begin;end--)
        {
            vector_push_back(&r.v,s[end]-'0');
        }
        return r;
    }
}

void bgn_del(bgn b)
{
    vector_del(&b.v);
}

void bgn_mov(bgn *a,bgn b)
{
    bgn_del(*a);
    a->sign=b.sign;
    a->v=b.v;
}

char* bgn_str(char *s,bgn b)
{
    int k=0;
    if(b.sign)
        s[k++]='-';
    for(int i=b.v.size-1;i>=0;i--)
        s[k++]=b.v.a[i]+'0';
    s[k]='\0';
    return s;
}

bgn bgn_neg(bgn b) //notice ,return element is the b itself,do not change it or use it after change original b
{
    b.sign=!b.sign;
    return b;
}

int bgn_cmp(bgn a,bgn b)
{
    if(a.sign==0&&b.sign)
        return 1;
    else if(a.sign&&b.sign==0)
        return -1;
    else if(a.sign&&b.sign)
        return -bgn_cmp(bgn_neg(a),bgn_neg(b));
    if(a.v.size>b.v.size)
        return 1;
    else if(a.v.size<b.v.size)
        return -1;
    for(int i=a.v.size-1;i>=0;i--)
    {
        if(a.v.a[i]>b.v.a[i])
            return 1;
        else if(a.v.a[i]<b.v.a[i])
            return -1;
    }
    return 0;
}

bgn bgn_shift(bgn b,int offset)
{
    bgn c;
    bgn e=bgn_new("0");
    if(-offset>=b.v.size||bgn_cmp(b,e)==0)
        return e;
    bgn_del(e);
    c.sign=b.sign;
    vector_init(&c.v);
    if(offset>=0)
    {
        for(int i=0;i<offset;i++)
            vector_push_back(&c.v,0);
        for(int i=0;i<b.v.size;i++)
            vector_push_back(&c.v,vector_at(&b.v,i));
    }
    else
    {
        for(int i=-offset;i<b.v.size;i++)
            vector_push_back(&c.v,vector_at(&b.v,i));
    }
    return c;
}

bgn bgn_cut(bgn b,int rest)
{
    bgn c;
    c.sign=b.sign;

    if(rest>=b.v.size)
    {
        vector_copy(&c.v,&b.v);
        return c;
    }
    vector_init(&c.v);
    for(int i=0;i<rest;i++)
        vector_push_back(&c.v,b.v.a[i]);
    while(c.v.size>1&&c.v.a[c.v.size-1]==0)
        vector_pop_back(&c.v);
    if(c.v.size==1&&c.v.a[0]==0)
        c.sign=0;
    return c;
}

bgn bgn_sub(bgn a,bgn b);
bgn bgn_add(bgn a,bgn b)
{
    bgn c;
    int i=0,j=0;
    if(a.sign&&b.sign)
        c.sign=1;
    else if(a.sign&&b.sign==0)
        return bgn_sub(b,bgn_neg(a));
    else if(a.sign==0&&b.sign)
        return bgn_sub(a,bgn_neg(b));
    else
        c.sign=0;

    int carry=0;
    vector_init(&c.v);
    while(i<a.v.size && j<b.v.size)
    {
        int sum=a.v.a[i]+b.v.a[j]+carry;
        vector_push_back(&c.v,sum%10);
        carry=sum/10;
        i++;j++;
    }
    while(i<a.v.size)
    {
        int sum=a.v.a[i]+carry;
        vector_push_back(&c.v,sum%10);
        carry=sum/10;
        i++;
    }
    while(j<b.v.size)
    {
        int sum=b.v.a[j]+carry;
        vector_push_back(&c.v,sum%10);
        carry=sum/10;
        j++;
    }
    if(carry!=0)
        vector_push_back(&c.v,carry);
    return c;
}

bgn bgn_sub(bgn a,bgn b)
{
    bgn c;
    if(a.sign==0&&b.sign)// 1-(-1)
        return bgn_add(a,bgn_neg(b));
    else if(a.sign&&b.sign==0)//(-1)-1
    {
        c=bgn_add(bgn_neg(a),b);
        c.sign=1;
        return c;
    }
    else if(a.sign&&b.sign)//(-1)-(-1)
        return bgn_add(a,bgn_neg(b));
    // 1-1
    int cmp=bgn_cmp(a,b);
    if(cmp==0)
        return bgn_new("0");
    else if(cmp==-1)
        return bgn_neg(bgn_sub(b,a));
    int carry=0;
    int i=0,j=0;
    vector_init(&c.v);
    c.sign=0;
    while(i<a.v.size && j<b.v.size)
    {
        int diff=a.v.a[i]-b.v.a[j]-carry;
        if(diff<0)
        {
            diff+=10;
            carry=1;
        }
        else
            carry=0;
        vector_push_back(&c.v,diff);
        i++;j++;
    }
    while(i<a.v.size)
    {
        int diff=a.v.a[i]-carry;
        carry=0;
        vector_push_back(&c.v,diff);
        i++;
    }
    while(c.v.a[c.v.size-1]==0)
        vector_pop_back(&c.v);
    return c;
}

bgn bgn_mul(bgn a,bgn b)
{
    bgn c=bgn_new("0");
    /*
    bgn table[11];
    int table_flag[10]={0};
    for(int i=0;i<11;i++)
        table[i]=bgn_new("0");
    */
    if(bgn_cmp(a,c)==0||bgn_cmp(b,c)==0)
        return c;

    for(int i=0;i<b.v.size;i++)
    {
        int carry=0;
        bgn tmp;
        //int pos=b.v.a[i];
        //if(table_flag[pos]==0)
        //{
        //   printf("occured\n");
            tmp.sign=0;
            vector_init(&tmp.v);
            for(int j=0;j<a.v.size;j++)
            {
                int product=a.v.a[j]*b.v.a[i]+carry;
                carry=product/10;
                vector_push_back(&tmp.v,product-10*carry);
            }
            if(carry!=0)
                vector_push_back(&tmp.v,carry);

         //   bgn_mov(&table[pos],bgn_add(tmp,table[10]));//tmp + 0 -> table
         //   table_flag[pos]=1;

            bgn_mov(&tmp,bgn_shift(tmp,i));
            bgn_mov(&c,bgn_add(c,tmp));
            bgn_del(tmp);
        //}
        //else
        //{
         //   tmp=bgn_shift(table[pos],i);
         //   bgn_mov(&c,bgn_add(c,tmp));
         //   bgn_del(tmp);
        //}
    }
    //for(int i=0;i<11;i++)
    //    bgn_del(table[i]);
    //sign
    if((a.sign&&b.sign) || (!a.sign&&!b.sign))
        c.sign=0;
    else
        c.sign=1;
    return c;
}

bgn bgn_mul_quick(bgn a,bgn b)
{
    //static int cnt=0;
    //printf("occure %d\n",cnt++);
    const int limit=30;
    int  offset;
    if(a.v.size>limit&&b.v.size>limit)
        offset=a.v.size/2;
    else if(a.v.size<limit&&b.v.size>limit)
        return bgn_mul(b,a);
    //else if(a.v.size>limit&&b.v.size<limit)
    //     offset=a.v.size/2;
    else
        return bgn_mul(a,b);

    bgn A,B,C,D;
    A=bgn_shift(a,-offset);
    B=bgn_cut(a,offset);
    //B=bgn_sub(a,bgn_shift(A,offset));
    C=bgn_shift(b,-offset);
    D=bgn_cut(b,offset);
    //D=bgn_sub(b,bgn_shift(C,offset));

    //printf("%s\n",bgn_str(ts,A));
    //printf("%s\n",bgn_str(ts,B));
    //printf("%s\n",bgn_str(ts,C));
    //printf("%s\n",bgn_str(ts,D));

    bgn AC,BD,X,Y;
    AC=bgn_mul_quick(A,C);
    BD=bgn_mul_quick(B,D);
    X=bgn_sub(B,A);
    Y=bgn_sub(C,D);
    //printf("%s\n",bgn_str(ts,X));
    //printf("%s\n",bgn_str(ts,Y));
    bgn XY=bgn_mul_quick(X,Y);
    bgn_mov(&XY,bgn_add(XY,AC));
    bgn_mov(&XY,bgn_add(XY,BD));
    bgn_mov(&XY,bgn_shift(XY,offset));
    bgn_mov(&XY,bgn_add(XY,BD));
    bgn_mov(&AC,bgn_shift(AC,offset*2));
    bgn_mov(&XY,bgn_add(AC,XY));

    bgn_del(A);bgn_del(B);bgn_del(C);
    bgn_del(D);bgn_del(X);bgn_del(Y);
    bgn_del(AC);bgn_del(BD);
    return XY;
}

int main(int argc,char *argv[])
{
    int N;
    scanf("%d",&N);
    for(int k=1;k<=N;k++)
    {
        char s[50];
        bgn a,b,c;
        scanf("%s",s);
        a=bgn_new(s);
        scanf("%s",s);
        b=bgn_new(s);
        scanf("%s",s);
        c=bgn_new(s);
        bgn d=bgn_add(a,b);

        if(bgn_cmp(d,c)>0)
            printf("Case #%d: true\n",k);
        else
            printf("Case #%d: false\n",k);
    }
}
