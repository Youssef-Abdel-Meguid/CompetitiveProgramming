#include<bits/stdc++.h>

using namespace std;

bool graph[101][101][101],visi[101];
int n,m;

bool dfs(int i,int j,int c)
{
    if(visi[i])
        return false;
    if(graph[i][j][c])
        return true;
    visi[i]=true;
    for(int k=1;k<=n;k++)
        if(graph[i][k][c]&&dfs(k,j,c))
            return true;
    return false;
}

int main()
{
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            graph[a][b][c]=graph[b][a][c]=true;
        }
    int q,u,v,ans=0;
    cin>>q;
    for(int i=0;i<q;i++)
        {
            cin>>u>>v;
            ans=0;
            for(int j=1;j<=m;j++)
                {
                    memset(visi,0,sizeof(visi));
                    if(dfs(u,v,j))
                        ans++;
                }
            cout<<ans<<endl;
        }
    return 0;
}
