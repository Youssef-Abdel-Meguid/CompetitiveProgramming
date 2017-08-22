#include <bits/stdc++.h>

using namespace std;

int dp[1000][1001][2],cnt[1000][2],n,m,x,y;

int solve(int indx,int width,int color)
{
	if(indx==m)
	{
		if(width>=x&&width<=y)
			return 0;
		return 1e9;
	}
	if(dp[indx][width][color]!=-1)
		return dp[indx][width][color];
	int ret=1e9;
	if(width<y)
		ret=min(ret,solve(indx+1,width+1,color)+cnt[indx][color]);
	if(width>=x)
		ret=min(ret,solve(indx+1,1,!color)+cnt[indx][!color]);
	return dp[indx][width][color]=ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
    {
    	char c;
    	memset(cnt,0,sizeof(cnt));
    	for(int i=0;i<n;i++)
    		for(int j=0;j<m;j++)
    		{
    			scanf(" %c",&c);
    			if(c=='.')
    				cnt[j][0]++;
    			else
    				cnt[j][1]++;
    		}
    	memset(dp,-1,sizeof(dp));
    	int ans=min(solve(0,0,0),solve(0,0,1));
    	printf("%d\n",ans);
    }
   	return 0;
}
