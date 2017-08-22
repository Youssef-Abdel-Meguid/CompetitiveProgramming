#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int x,len,cost;
};

bool operator <(Node a,Node b)
{
    if(a.len!=b.len)
        return a.len<b.len;
    if(a.cost!=b.cost)
    	return a.cost<b.cost;
    return a.x<b.x;
}

vector<int>to[101],len[101],cost[101];
int n,m,k;
bool visi[101][10001];

int dijkstra()
{
    memset(visi,0,sizeof(visi));
    set<Node>se;
    Node cur;
    cur.x=1,cur.len=0,cur.cost=0;
    se.insert(cur);
    while(se.size())
    {
        cur=*se.begin();
        se.erase(se.begin());
        if(visi[cur.x][cur.cost])
            continue;
        visi[cur.x][cur.cost]=true;
        if(cur.x==n)
            return cur.len;
        for(int i=0;i<to[cur.x].size();i++)
        {
            Node tmp;
            tmp.x=to[cur.x][i];
            tmp.len=len[cur.x][i]+cur.len;
            tmp.cost=cost[cur.x][i]+cur.cost;
            if(tmp.cost<=k)
                se.insert(tmp);
        }
    }
    return -1;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        cin>>k>>n>>m;
        int x,y,l,c;
        while(m--)
        {
            cin>>x>>y>>l>>c;
            to[x].push_back(y);
            len[x].push_back(l);
            cost[x].push_back(c);
        }
        cout<<dijkstra()<<endl;
        for(int i=1;i<=n;i++)
        {
            to[i].clear();
            len[i].clear();
            cost[i].clear();
        }
    }
}
