#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;
vector<int> s;

class Media
{
private:
    struct T
    {
        int left;
        int right;
        int count;
        T():left{0},right{0},count{0}{}
    };
    vector<T> look;
    enum {Range=100010};
public:
    Media():look(Range){}
    void push(int x)
    {
        int l=0,r=Range;
        while(l<=r)
        {
            int center=(l+r)/2;
            if(x<center)
            {
                look[center].left++;
                r=center-1;
            }
            else if(x>center)
            {
                look[center].right++;
                l=center+1;
            }
            else
            {
                look[center].count++;
                break;
            }

        }
    }
    void erase(int x)
    {
        int l=0,r=Range;
        while(l<=r)
        {
            int center=(l+r)/2;
            if(x<center)
            {
                look[center].left--;
                r=center-1;
            }
            else if(x>center)
            {
                look[center].right--;
                l=center+1;
            }
            else
            {
                look[center].count--;
                break;
            }
        }
    }
    int nth(int pos)
    {
        int l=0,r=Range;
        int center=(l+r)/2;
        int half=pos;
        while(l<=r)
        {
            center=(l+r)/2;
            int left=look[center].left;
            if(half<=left)
                r=center-1;
            else if(half>left+look[center].count)
            {
                l=center+1;
                half=half-left-look[center].count;
            }
            else
                return center;
        }
        return center;
    }
    int median()
    {
        int l=0,r=Range;
        int center=(l+r)/2;
        int size=look[center].left+look[center].right+look[center].count;
        return nth((size+1)/2);
    }

};

Media M;

void pop()
{
    if(s.empty())
        printf("Invalid\n");
    else
    {
        int x=s.back();
        printf("%d\n",x);
        s.pop_back();
        M.erase(x);
    }
}

void push()
{
    int key;
    scanf("%d",&key);
    s.push_back(key);
    M.push(key);
}

void peekmedian()
{
    if(s.empty())
        printf("Invalid\n");
    else
        printf("%d\n",M.median());
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[30];
        scanf("%s",op);
        if(op[1]=='o')
            pop();
        else if(op[1]=='e')
            peekmedian();
        else if(op[1]=='u')
            push();
        else
            printf("Invalid\n");
    }
}
