#include<bits/stdc++.h>

using namespace std;

int a[100000],n,m,ans=0;
vector<int>graph[100000];

void solve(int node,int parent,int cats)
{
    if(a[node])
        cats++;
    else
        cats=0;
    if(cats>m)
        return;
    bool flag=true;
    for(int i=0;i<graph[node].size();i++)
        if(graph[node][i]!=parent)
            {
                solve(graph[node][i],node,cats);
                flag=false;
            }
    ans+=flag;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            x--,y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    solve(0,-1,0);
    cout<<ans<<endl;
    return 0;
}
