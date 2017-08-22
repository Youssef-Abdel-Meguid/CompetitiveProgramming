#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int x,y,cost;
};

bool operator <(Node a,Node b)
{
	if(a.cost!=b.cost)
		return a.cost<b.cost;
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}

char a[26][26];
int aa[25][25],n,m,dis[25][25],x,y,xx,yy;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

bool isvalid(int i,int j)
{
	return i>=0&&i<n&&j>=0&&j<m;
}

int dijkstra()
{
	set<Node>se;
	Node cur;
	cur.x=x,cur.y=y,cur.cost=0;
	dis[x][y]=0;
	se.insert(cur);
	while(se.size())
	{
		cur=*se.begin();
		se.erase(se.begin());
		if(cur.x==xx&&cur.y==yy)
			return cur.cost;
		for(int i=0;i<4;i++)
		{
			Node tmp;
			tmp.x=cur.x+dx[i];
			tmp.y=cur.y+dy[i];
			if(!isvalid(tmp.x,tmp.y))
				continue;
			if(a[tmp.x][tmp.y]=='X')
				continue;
			tmp.cost=cur.cost+aa[tmp.x][tmp.y];
			if(dis[tmp.x][tmp.y]>tmp.cost)
			{
				dis[tmp.x][tmp.y]=tmp.cost;
				se.insert(tmp);
			}
		}
	}
	return dis[xx][yy];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d%d",&m,&n)&&m&&n)
    {
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    			scanf(" %c",&a[i][j]);
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    		{
    			if(a[i][j]=='X')
    				aa[i][j]=-1;
    			else if(a[i][j]=='S')
    			{
    				x=i,y=j;
    				aa[i][j]=0;
    			}
    			else if(a[i][j]=='D')
    			{
    				xx=i,yy=j;
    				aa[i][j]=0;
    			}
    			else
    				aa[i][j]=(a[i][j]-'0');
    			dis[i][j]=1e9;
    		}
    	printf("%d\n",dijkstra());
    }
   	return 0;
}
