#include<bits/stdc++.h>

using namespace std;

int a[100001],goal[100001],n;
vector<int>graph[100001];
vector<int>ans;
bool visi[100001];

void dfs(int i,bool odd,bool even)
{
    if(visi[i])
        return;
    if(a[i]^even!=goal[i])
        {
            ans.push_back(i);
            even=!even;
        }
    visi[i]=true;
    for(int j=0;j<graph[i].size();j++)
        dfs(graph[i][j],even,odd);
}

int main()
{
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++)
        {
            cin>>x>>y;
            graph[x-1].push_back(y-1);
            graph[y-1].push_back(x-1);
        }
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>goal[i];
    dfs(0,0,0);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<endl;
    return 0;
}
