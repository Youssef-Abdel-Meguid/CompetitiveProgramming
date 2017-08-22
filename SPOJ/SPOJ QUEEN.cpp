#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int x,y,cost;
};

char graph[1000][1000];
bool visi[1000][1000];
int n,m,dis[1000][1000],s1,s2,d1,d2;
int dx[8]={1, 1,-1,-1, 0, 0, 1, -1};
int dy[8]={1,-1, 1,-1, 1,-1, 0,  0};

bool isvalid(int i,int j)
{
	return (i>=0&&i<n&&j>=0&&j<m&&graph[i][j]!='X');
}

int bfs()
{
	queue<Node>q;
	Node cur;
	cur.x=s1,cur.y=s2,cur.cost=0;
	dis[s1][s2]=0;
	q.push(cur);
	while(q.size())
	{
		cur=q.front();
		q.pop();
		if(cur.x==d1&&cur.y==d2)
			return cur.cost;
		for(int i=0;i<8;i++)
		{
			int x=dx[i]+cur.x;
			int y=dy[i]+cur.y;
			int xx=x;
			int yy=y;
			while(isvalid(x,y)&&!visi[x][y])
			{
				if(dis[x][y]>cur.cost+1)
				{
					dis[x][y]=cur.cost+1;
					Node tmp;
					tmp.x=x,tmp.y=y,tmp.cost=dis[x][y];
					q.push(tmp);
					visi[x][y]=true;
				}
				x=dx[i]+x;
				y=dy[i]+y;
			}
			while(isvalid(xx,yy)&&cur.cost+1<=dis[xx][yy])
			{
				dis[xx][yy]=cur.cost+1;
				Node tmp;
				tmp.x=xx,tmp.y=yy,tmp.cost=dis[xx][yy];
				if(!visi[xx][yy])
					q.push(tmp);
				visi[xx][yy]=true;
				xx=dx[i]+xx;
				yy=dy[i]+yy;
			}
		}
	}
	return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
    	scanf("%d%d",&n,&m);
    	for(int i=0;i<n;i++)
    	{
    		scanf("%s",graph[i]);
    		for(int j=0;j<m;j++)
    		{
    			if(graph[i][j]=='S')
    			{
    				s1=i;
    				s2=j;
    			}
    			if(graph[i][j]=='F')
    			{
    				d1=i;
    				d2=j;
    			}
    		}
    	}
    	memset(visi,false,sizeof(visi));
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    			dis[i][j]=1e9;
    	printf("%d\n",bfs());
    }
    return 0;
}
