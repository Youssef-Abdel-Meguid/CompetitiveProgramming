#include <bits/stdc++.h>

using namespace std;

int n,a[5000],dp[5000][5000];

int solve(int i,int min_sofar)
{
	if(i>=n)
		return 0;
	if(dp[i][min_sofar]!=-1)
		return dp[i][min_sofar];
	int ret=1e9;
	if(a[i]<=min_sofar)
		ret=solve(i+1,a[i]);
	else
	{
		ret=1+solve(i+1,min_sofar);
		if(a[i]<n)
			ret=min(ret,a[i]-min_sofar+solve(i+1,a[i]));
	}
	return dp[i][min_sofar]=ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d",&n)!=EOF)
    {
    	for(int i=0;i<n;i++)
    		scanf("%d",&a[i]);
    	memset(dp,-1,sizeof(dp));
    	printf("%d\n",solve(0,0));
    }
   	return 0;
}
