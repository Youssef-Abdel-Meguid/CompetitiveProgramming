#include <bits/stdc++.h>

using namespace std;

pair<int,int> operator +(pair<int,int>a,pair<int,int>b)
{
	return make_pair(a.first+b.first,a.second+b.second);
}

pair<int,int>dp[101][101];

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
    	int n,m,x,y,cost,s,d,type;
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
    			{
    				dp[i][j]=make_pair(1e9,1e9);
    				dp[j][i]=make_pair(1e9,1e9);
    			}
    	while(m--)
    	{
    		scanf("%d%d%d%d",&x,&y,&cost,&type);
    		if(type==1)
    		{
    			if(dp[x][y].first!=1e9)
    				continue;
    			dp[x][y]=make_pair(cost,cost);
    			dp[y][x]=make_pair(cost,cost);
    		}
    		else
    		{
    			dp[x][y]=make_pair(0,cost);
    			dp[y][x]=make_pair(0,cost);
    		}
    	}
    	scanf("%d%d",&s,&d);
    	for(int k=1;k<=n;k++)
    		for(int i=1;i<=n;i++)
    			for(int j=1;j<=n;j++)
    				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    	if(dp[s][d].first==1e9&&dp[s][d].second==1e9)
    		printf("-1\n");
    	else
    		printf("%d %d\n",dp[s][d].first,dp[s][d].second);
    }
    return 0;
}
