#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,bool> >adjlist[30012];
bool visi[30012];

bool dfs(int s,int t)
{
	if(s==t)
		return true;
	if(visi[s])
		return false;
	visi[s]=true;
	for(int i=0;i<adjlist[s].size();i++)
	{
		if(adjlist[s][i].second==false)
			continue;
		adjlist[s][i].second=false;
		if(dfs(adjlist[s][i].first,t))
			return true;
		adjlist[s][i].second=true;
	}
	return false;
}

void initi()
{
	for(int i=0;i<=n;i++)
		adjlist[i].clear();
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
    	scanf("%d%d",&n,&m);
    	initi();
    	while(m--)
    	{
    		int x,y;
    		scanf("%d%d",&x,&y);
    		if(x<=0||y<=0||x>n||y>n)
    			continue;
    		adjlist[x].push_back(make_pair(y,true));
    		adjlist[y].push_back(make_pair(x,true));
    	}
    	memset(visi,false,sizeof(visi));
    	bool path1=dfs(2,1);
    	memset(visi,false,sizeof(visi));
    	bool path2=dfs(2,3);
    	if(path2&&path1)
    		printf("YES\n");
    	else
    		printf("NO\n");
    }
    return 0;
}
