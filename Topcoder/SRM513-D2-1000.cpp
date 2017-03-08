#include <bits/stdc++.h>

using namespace std;

class CutTheNumbers
{
public:
    int maximumSum(vector <string> board)
    {
        int n=board.size(),m=board[0].size(),ans=0;
        for(int mask=0;mask<=(1<<(n*m));mask++)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                int x=0;
                for(int j=0;j<m;j++)
                    if(mask&(1<<(j*n+i)))
                    {
                        x*=10;
                        x+=(board[i][j]-'0');
                    }
                    else
                    {
                        sum+=x;
                        x=0;
                    }
                sum+=x;
            }
            for(int i=0;i<m;i++)
            {
                int x=0;
                for(int j=0;j<n;j++)
                    if((mask&(1<<(i*n+j)))==0)
                    {
                        x*=10;
                        x+=(board[j][i]-'0');
                    }
                    else
                    {
                        sum+=x;
                        x=0;
                    }
                sum+=x;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
