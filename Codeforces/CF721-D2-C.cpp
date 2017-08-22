#include <bits/stdc++.h>

using namespace std;

struct Node {
	int x, y, cost;
	Node(int x, int y, int cost) :
			x(x), y(y), cost(cost) {
	}
	bool operator<(const Node&e) const {
		return e.cost < cost;
	}
};
vector<pair<int,int>>adjlist[5001];
vector<int>ans;
int T,n,m;
bool visi[5001][5001];
int dis[5001][5001];
short path[5001][5001];
priority_queue<Node>pq;

void dijkstra()
{
    for(int i=0;i<5000;i++)
        for(int j=0;j<5000;j++)
        {
            dis[i][j]=2e9;
           // path[i][j]=-1;
        }
    pq.push(Node(0, 0, 0));
    dis[0][0]=0;
    while(pq.size())
    {
        Node cur=pq.top();
        pq.pop();
        if(visi[cur.x][cur.y])
            continue;
        visi[cur.x][cur.y]=true;
        if(cur.x==n-1)
            continue;
        for(int i=0;i<adjlist[cur.x].size();i++)
        {
            int x=adjlist[cur.x][i].first;
            int y=cur.y+1;
            int cost=adjlist[cur.x][i].second+cur.cost;
            if(visi[x][y]||cost>=dis[x][y]||cost>T)
                continue;
            dis[x][y]=cost;
            path[x][y]=cur.x;
            pq.push(Node(x, y, cost));
        }
    }
    int ii;
    for(ii=n;ii>=1;ii--)
        if(visi[n-1][ii])
            break;
   // cout<<ii<<endl;
    for(int i=n-1;i!=0;i=path[i][ii--])
        ans.push_back(i);
    ans.push_back(0);
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif*/
   /* while(!=EOF)
    {
        for(int i=1;i<=n;i++)
            adjlist[i].clear();
        ans.clear();
        memset(visi,false,sizeof(visi));
        memset(path,0,sizeof(path));*/
        scanf("%d%d%d",&n,&m,&T);
        while(m--)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            x--,y--;
            adjlist[x].push_back(make_pair(y,c));
        }
        dijkstra();
        printf("%d\n",ans.size());
        for(int i=ans.size()-1;i>=0;i--)
            printf("%d ",ans[i]+1);
        printf("\n");
   // }
    return 0;
}
