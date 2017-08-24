#include<bits/stdc++.h>

using namespace std;

vector<vector<int> >adj;
bool visi[2001];
vector<int>ans;

void dfs(int n,int d)
{
    visi[n]=true;
    for(int i=0;i<adj[n].size();i++)
       {
           int new_n=adj[n][i];
           if(!visi[new_n])
             dfs(new_n,d+1);
       }
    ans.push_back(d);
}

int main()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x!=-1)
                adj[x].push_back(i);
        }
    for(int i=1;i<=n;i++)
        {
            memset(visi,false,sizeof(visi));
            dfs(i,1);
        }
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1]<<endl;
    return 0;
}
