#include<bits/stdc++.h>

using namespace std;

vector<int>rail[401],road[401];
int n,m,dis[401];
bool not_road[401][401];

int bfs_rail()
{
    for(int i=1;i<=n;i++)
        dis[i]=1e9;
    queue<int>q;
    q.push(1);
    dis[1]=0;
    while(q.size())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<rail[x].size();i++)
            if(dis[rail[x][i]]>dis[x]+1)
            {
                dis[rail[x][i]]=dis[x]+1;
                q.push(rail[x][i]);
            }
    }
    return dis[n];
}

int bfs_road()
{
    for(int i=1;i<=n;i++)
        dis[i]=1e9;
    queue<int>q;
    q.push(1);
    dis[1]=0;
    while(q.size())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<road[x].size();i++)
            if(dis[road[x][i]]>dis[x]+1)
            {
                dis[road[x][i]]=dis[x]+1;
                q.push(road[x][i]);
            }
    }
    return dis[n];
}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        rail[x].push_back(y);
        rail[y].push_back(x);
        not_road[x][y]=not_road[y][x]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(not_road[i][j]==0)
            {
                road[i].push_back(j);
                road[j].push_back(i);
            }
    int ans=max(bfs_rail(),bfs_road());
    if(ans==1e9)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
