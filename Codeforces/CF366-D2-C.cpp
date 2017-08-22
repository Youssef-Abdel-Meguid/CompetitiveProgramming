#include <bits/stdc++.h>

using namespace std;

int dp[100][201000],n,k,a[100],b[100],sh=100000;

int solve(int i,int bala)
{
	if(i>=n)
	{
		if(!bala)
			return 0;
		return -1e9;
	}
	if(dp[i][bala+sh]!=-1)
		return dp[i][bala+sh];
	int ret=0;
	ret=max(solve(i+1,bala),solve(i+1,bala+(b[i]*k)-a[i])+a[i]);
	return dp[i][bala+sh]=ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(cin>>n>>k)
    {
    	for(int i=0;i<n;i++)
    		cin>>a[i];
    	for(int i=0;i<n;i++)
    		cin>>b[i];
    	memset(dp,-1,sizeof(dp));
    	int ans=solve(0,0);
    	if(ans<=0)
    		cout<<-1<<endl;
    	else
    		cout<<ans<<endl;
    }
   	return 0;
}
