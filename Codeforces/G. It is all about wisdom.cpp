#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    long long x,cost,wisdom;
};

bool operator <(Node a,Node b)
{
    if(a.cost!=b.cost)
        return a.cost<b.cost;
    if(a.wisdom!=b.wisdom)
        return a.wisdom<b.wisdom;
    return a.x<b.x;
}

int n,m,k;
long long dis[100001];
vector<Node>adjlist[100001];

long long dijkstra(int w)
{
    for(int i=1;i<=n;i++)
        dis[i]=1e15;
    set<Node>se;
    Node cur;
    cur.x=1;
    cur.cost=0;
    cur.wisdom=w;
    se.insert(cur);
    while(se.size())
    {
        cur=*se.begin();
        se.erase(se.begin());
        dis[cur.x]=cur.cost;
        if(cur.x==n)
            return cur.cost;
        for(int i=0;i<adjlist[cur.x].size();i++)
        {
            if(adjlist[cur.x][i].wisdom>w)
                continue;
            Node tmp;
            tmp.x=adjlist[cur.x][i].x;
            tmp.cost=cur.cost+adjlist[cur.x][i].cost;
            tmp.wisdom=cur.wisdom;
            if(dis[tmp.x]>tmp.cost)
                se.insert(tmp);
        }

    }
    return 1e15;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d%d",&n,&m,&k);
        int max_wisdom=0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            int cost,wisdom;
            scanf("%d%d%d%d",&x,&y,&cost,&wisdom);
            max_wisdom=max(max_wisdom,wisdom);
            Node tmp;
            tmp.x=y,tmp.cost=cost,tmp.wisdom=wisdom;
            adjlist[x].push_back(tmp);
            tmp.x=x;
            adjlist[y].push_back(tmp);
        }
        int s=1,e=max_wisdom,mid,ret=-1;
        while(s<=e)
        {
            mid=(s+e)/2;
            long long x=dijkstra(mid);
            if(x<k)
            {
                e=mid-1;
                ret=mid;
            }
            else
                s=mid+1;
        }
        cout<<ret<<endl;
        for(int i=1;i<=n;i++)
            adjlist[i].clear();
    }
    return 0;
}
