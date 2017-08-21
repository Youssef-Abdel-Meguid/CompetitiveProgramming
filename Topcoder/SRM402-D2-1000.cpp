#include<bits/stdc++.h>

using namespace std;

class RandomSort
{
    map<vector<int>,double>dp;
    int n;

    double solve(vector<int>vec)
    {
        if(dp.count(vec))
            return dp[vec];
        double ret=0,cnt=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(vec[i]>vec[j])
                {
                    swap(vec[i],vec[j]);
                    cnt++;
                    ret+=1+solve(vec);
                    swap(vec[i],vec[j]);
                }
        if(cnt)
            ret=ret/cnt;
        else
            ret=0;
        dp[vec]=ret;
        return ret;
    }
public:
    double getExpected(vector <int> permutation)
    {
        n=permutation.size();
        return solve(permutation);
    }
};
