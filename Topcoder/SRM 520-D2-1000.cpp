#include <bits/stdc++.h>

using namespace std;

class SRMSystemTestPhase
{
    char a[50][3];
    int dp[50][4][4],n;

    int solve(int position,int passed,int challanged)
    {
        if(position==n)
            return 1;
        if(dp[position][passed][challanged]!=-1)
            return dp[position][passed][challanged];
        int ret=0,p1=1,p2=1,p3=1;
        if(a[position][0]=='Y')
            p1=3;
        if(a[position][1]=='Y')
            p2=3;
        if(a[position][2]=='Y')
            p3=3;
        for(int i=0;i<p1;i++)
            for(int j=0;j<p2;j++)
                for(int k=0;k<p3;k++)
                {
                    int pas=0,ch=0;
                    if(a[position][0]=='Y')
                    {
                        if(i==0)
                            pas++;
                        else if(i==1)
                            ch++;
                    }

                    if(a[position][1]=='Y')
                    {
                         if(j==0)
                            pas++;
                        else if(j==1)
                            ch++;
                    }

                    if(a[position][2]=='Y')
                    {
                        if(k==0)
                            pas++;
                        else if(k==1)
                            ch++;
                    }

                    if(passed<pas||(passed==pas&&challanged>ch))
                        continue;
                    ret=(ret+(solve(position+1,pas,ch)))%1000000007;
                }
        return dp[position][passed][challanged]=ret;
    }

public:
    int countWays(vector <string> description)
    {
        n=description.size();
        for(int i=0;i<description.size();i++)
            for(int j=0;j<description[0].size();j++)
                a[i][j]=description[i][j];
        memset(dp,-1,sizeof(dp));
        return solve(0,3,0);
    }
};
