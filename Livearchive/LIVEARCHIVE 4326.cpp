/*
Normal MST problem ,,,, just use bitmasking to got all subgraphs with number of nodes equals to m
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int to,from,cost;

	bool operator < (Node &a) const
	{
		return cost < a.cost;
	}
};

vector<Node>graph;/*you can use set or priority queue but i think vector is better*/
vector<int>ans,tmp;
int n,m,rankk[16],parent[16],a[15],forests;
double min_ratio=1e9;

void inti(int n)
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

void union_set(int x,int y)
{
	x=find_set(x);
    y=find_set(y);
    if(x!=y)
    {
        link(x,y);
        forests--;
    }
}

bool same_set(int x,int y)
{
	return find_set(x)==find_set(y);
}

void MST(int mask,int cnt1)
{
	int cnt2=0;
	for(int i=0;i<graph.size();i++) /*if i used set the complexity here is O(nlogn) but with vector is just O(n)*/
		if((mask&(1<<graph[i].to))&&(mask&(1<<graph[i].from))&&!same_set(graph[i].from,graph[i].to))
		{
			union_set(graph[i].from,graph[i].to);
			cnt2+=graph[i].cost;
		}
	double ratio=(double)cnt2/(double)cnt1;
	if(ratio+1e-9<min_ratio)
	{
		min_ratio=ratio;
		ans=tmp;
	}
	else if(ratio==min_ratio&&ans>tmp)
		ans=tmp;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d%d",&n,&m)&&n)
    {
    	graph.clear();
    	memset(rankk,0,sizeof(rankk));
    	memset(parent,0,sizeof(parent));
    	min_ratio=1e9;
    	for(int i=0;i<n;i++)
    		scanf("%d",&a[i]);
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    		{
    			int x;
    			scanf("%d",&x);
    			if(i!=j)
    			{
    				Node tmp;
    				tmp.from=i;
    				tmp.to=j;
    				tmp.cost=x;
    				graph.push_back(tmp);
    			}
    		}
    	sort(graph.begin(),graph.end());
    	for(int i=0;i<(1<<n);i++)
    	{
 	   		if(__builtin_popcount(i)==m)
    		{
    			inti(n);
    			int cnt1=0;
    			for(int j=0;j<n;j++)
    				if(i&(1<<j))
    				{
    					cnt1+=a[j];
    					tmp.push_back(j+1);
    				}
    			MST(i,cnt1);
    			tmp.clear();
    		}
    	}
    	printf("%d",ans[0]);
    	for(int i=1;i<m;i++)
    		printf(" %d",ans[i]);
    	printf("\n");
    }
    return 0;
}
