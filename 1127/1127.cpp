#include<cstdio>
#include<map>
#include<vector>

using namespace std;

struct _tree
{
	int x;
	_tree *left{nullptr};
	_tree *right{nullptr};
};

_tree* make_tree(vector<int> &in,vector<int> &post)
{
	map<int,int> m;
	_tree *r=nullptr;
	for(int i=0;(unsigned)i<in.size();i++)
		m[in[i]]=i;
	for(auto i=post.rbegin();i!=post.rend();i++)
	{
		if(r==nullptr)
			r=new _tree{*i};
		else
		{
			auto p=r;
			while(p!=nullptr)
			{
				if(m[*i]<m[p->x])
				{
					if(p->left!=nullptr)
						p=p->left;
					else
					{
						p->left=new _tree{*i};
						break;
					}
				}
				else
				{
					if(p->right!=nullptr)
						p=p->right;
					else
					{
						p->right=new _tree{*i};
						break;
					}
				}
			}
		}

	}
	return r;
}

vector<vector<int>> v;

void dfs(_tree *t,int deep)
{
	if(t==nullptr)
		return;
	if(deep>=v.size())
		v.push_back({});
	v[deep].push_back(t->x);
	dfs(t->left,deep+1);
	dfs(t->right,deep+1);
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v1(n);
	vector<int> v2(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v1[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&v2[i]);
	auto r=make_tree(v1,v2);
	dfs(r,0);
	vector<int> out;
	for(auto i=0U;i<v.size();i++)
	{
		if(i%2!=0)
		{
			for(auto it=v[i].begin();it!=v[i].end();it++)
				out.push_back(*it);
		}
		else
		{
			for(auto it=v[i].rbegin();it!=v[i].rend();it++)
				out.push_back(*it);
		}
	}
	printf("%d",out[0]);
	for(auto i=1U;i<out.size();i++)
		printf(" %d",out[i] );
}