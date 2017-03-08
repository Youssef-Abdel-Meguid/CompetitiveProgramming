#include <bits/stdc++.h>

using namespace std;

class BagsOfGold
{
	vector<int>b;
	int dp[50][50][2];

	int solve(int l,int r,bool turn)
	{
		if(l>r)
			return 0;
		if(l==r)
		{
			if(turn)
				return b[l];
			return -b[r];
		}
		if(dp[l][r][turn]!=1e9)
			return dp[l][r][turn];
		if(turn)
			return dp[l][r][turn]=max(b[l]+solve(l+1,r,!turn),b[r]+solve(l,r-1,!turn));
		return dp[l][r][turn]=min(-b[l]+solve(l+1,r,!turn),-b[r]+solve(l,r-1,!turn));
	}

public:
	int netGain(vector <int> bags)
	{
		for(int i=0;i<50;i++)
			for(int j=0;j<50;j++)
				for(int k=0;k<2;k++)
					dp[i][j][k]=1e9;
		b=bags;
		return solve(0,bags.size()-1,1);
	}
};
