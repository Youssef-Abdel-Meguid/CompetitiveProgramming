#include<bits/stdc++.h>
 
using namespace std;
 
vector<int>graph[100001];
bool visi[100001];
int max_diamter[100001];
 
void bfs(int node)
{
    queue<pair<int,int>>q;
    q.push(make_pair(node,0));
    while(q.size())
    {
        node=q.front().first;
        int diamter=q.front().second;
        max_diamter[node]=diamter;
        q.pop();
        visi[node]=true;
        for(int i=0;i<graph[node].size();i++)
            if(!visi[graph[node][i]])
                q.push(make_pair(graph[node][i],diamter+1));
    }
}
 
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        memset(visi,false,sizeof(visi));
        memset(max_diamter,0,sizeof(max_diamter));
        bfs(1);
        int far_node=1;
        for(int i=1;i<=n;i++)
            if(max_diamter[i]>max_diamter[far_node])
                far_node=i;
        memset(visi,false,sizeof(visi));
        memset(max_diamter,0,sizeof(max_diamter));
        bfs(far_node);
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,max_diamter[i]);
        cout<<n-1-ans<<endl;
        for(int i=1;i<=n;i++)
            graph[i].clear();
    }
    return 0;
}
