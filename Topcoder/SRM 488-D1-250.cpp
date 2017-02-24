#include <bits/stdc++.h>

using namespace std;

class TheBoredomDivOne
{
public:
	double find(int n, int m)
	{
		int t=n+m;
		double dp[t+2];
		dp[t]=dp[t+1]=0.0;
		for(int k=t-1;k>=n;k--)
		{
			double cnt=0.0,t0=0.0,t1=0.0,t2=0.0;
			for(int i=1;i<=t;i++)
				for(int j=i+1;j<=t;j++)
				{
					cnt++;
					if(i>k&&j>k)
						t2++;
					else if(i>k||j>k)
						t1++;
					else
						t0++;
				}
			double p0=t0/cnt,p1=t1/cnt,p2=t2/cnt;
			dp[k]=(1+p1*dp[k+1]+p2*dp[k+2])/(1-p0);
		}
		return dp[n];
	}
};
