#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int x;
    long long cost;
};

bool operator <(Node a,Node b)
{
    if(a.cost!=b.cost)
        return a.cost<b.cost;
    return a.x<b.x;
}

vector<Node>adjlist[100001];
int n,m,path[100001];
long long dis[100001];

long long dijkstra()
{
    for(int i=1;i<=n;i++)
        dis[i]=1e15;
    set<Node>se;
    Node cur;
    cur.x=1,cur.cost=0;
    dis[1]=0;
    se.insert(cur);
    while(se.size())
    {
        cur=*se.begin();
        se.erase(se.begin());
        /*if(cur.x==n)
            return cur.cost;*/
        for(int i=0;i<adjlist[cur.x].size();i++)
        {
            Node tmp;
            tmp.x=adjlist[cur.x][i].x;
            tmp.cost=cur.cost+adjlist[cur.x][i].cost;
            if(tmp.cost<dis[tmp.x])
            {
                dis[tmp.x]=tmp.cost;
                se.insert(tmp);
                path[tmp.x]=cur.x;
            }
        }
    }
    return dis[n];
}

void print_path(int x)
{
    if(path[x]==0)
        return;
    print_path(path[x]);
    cout<<path[x]<<" ";
}

int main()
{
    cin>>n>>m;
    int x,y,cost;
    while(m--)
    {
        cin>>x>>y>>cost;
        Node tmp;
        tmp.x=y,tmp.cost=cost;
        adjlist[x].push_back(tmp);
        tmp.x=x;
        adjlist[y].push_back(tmp);
    }
    long long ans=dijkstra();
    if(ans==1e15)
        cout<<-1<<endl;
    else
    {
        print_path(n);
        cout<<n<<endl;
    }
    return 0;
}
