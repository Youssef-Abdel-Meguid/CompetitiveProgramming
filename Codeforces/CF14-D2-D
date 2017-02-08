#include <bits/stdc++.h>

using namespace std;

vector<int>adjlist[201];
bool no[201][201];

pair<int,int> dfs(int node,int parent)
{
    int diam = 0;
    int mxHeights[3]={-1,-1,-1};
    int ret=0;
    for(int i=0;i<adjlist[node].size();i++)
    {
        if(!no[node][adjlist[node][i]]&&adjlist[node][i]!=parent)
        {
            pair<int,int>p=dfs(adjlist[node][i],node);
            diam=max(diam,p.first);
            mxHeights[0]=p.second+1;
            sort(mxHeights,mxHeights+3);
        }
      
    }
    for(int i=0;i<3;i++)
        if(mxHeights[i]==-1)
            mxHeights[i]=0;
    diam=max(diam,mxHeights[1]+mxHeights[2]);
    return make_pair(diam,mxHeights[2]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(cin>>n)
    {
       for(int i=1;i<=n;i++)
         adjlist[i].clear();
       for(int i=1;i<n;i++)
       {
            int x,y;
            cin>>x>>y;
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
       }
       int ans=0;
       memset(no,false,sizeof(no));
       for(int i=1;i<=n;i++)
       {
            for(int j=0;j<adjlist[i].size();j++)
            {
                int a=i;
                int b=adjlist[i][j];
                no[a][b]=no[b][a]=true;
                pair<int,int>x=dfs(a,a);
                pair<int,int>y=dfs(b,b);
                ans=max(ans,x.first*y.first);
                no[a][b]=no[b][a]=false;
            }
       }
       cout<<ans<<endl;
    }
    return 0;
}
