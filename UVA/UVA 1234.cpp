#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int x,y,cost;

	bool operator < (const Node &a) const
	{
		return a.cost<cost;
	}
};

int rankk[10001],parent[10001],n,m,forests;
priority_queue<Node>q;

void initi()
{
	forests=n;
	for(int i=0;i<=n;i++)
	{
		parent[i]=i;
		rankk[i]=1;
	}
}

int find_set(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x]=find_set(parent[x]);
}

void link(int x,int y)
{
	if(rankk[x]>rankk[y])
		swap(x,y);
	parent[x]=y;
	if(rankk[x]==rankk[y])
		rankk[y]++;
}

bool union_set(int x,int y)
{
	x=find_set(x);
	y=find_set(y);
	if(x!=y)
	{
		link(x,y);
		forests--;
	}
	return x!=y;
}

bool same_set(int x,int y)
{
	return find_set(x)==find_set(y);
}


int MST()
{
	int ret=0;
	while(q.size())
	{
		Node cur=q.top();
		q.pop();
		if(!union_set(cur.x,cur.y))
			ret+=-cur.cost;
	}
	return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases,x;
    scanf("%d",&cases);
    while(cases--)
    {
    	scanf("%d%d",&n,&m);
    	while(m--)
    	{
    		int x,y,cost;
    		scanf("%d%d%d",&x,&y,&cost);
    		Node tmp;
    		tmp.x=x,tmp.y=y,tmp.cost=-cost;
    		q.push(tmp);
    	}
    	initi();
    	printf("%d\n",MST());
    }
    scanf("%d",&x);
    return 0;
}
