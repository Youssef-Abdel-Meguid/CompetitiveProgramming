#include<bits/stdc++.h>

using namespace std;

class EmployManager
{
public:
    int maximumEarnings(vector <int> value, vector <string> earning)
    {
       int ans=0;
       for(int i=0;i<earning.size();i++)
            for(int j=i+1;j<earning[i].size();j++)
                ans-=(earning[i][j]-'0');
       for(int i=0;i<value.size();i++)
       {
            int sum=0;
            for(int j=0;j<value.size();j++)
                sum+=earning[i][j]-'0';
            if(sum>=value[i])
                ans+=(sum-value[i]);
       }
       return ans;
    }
};
