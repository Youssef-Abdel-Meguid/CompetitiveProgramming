#include<bits/stdc++.h>

using namespace std;

class ChildlessNumbers
{
    long long D(long long x)
    {
        long long ret=0;
        while(x)
        {
            ret+=x%10;
            x/=10;
        }
        return ret;
    }
public:
    int howMany(int A, int B)
    {
        long long y;
        int ans=0;
        for(int i=A;i<=B;i++)
        {
            bool flag=false;
            for(int j=1;j<=100&&!flag;j++)
            {
                y=(long long)j*i;
                if(D(y)==j)
                    flag=true;
            }
            if(!flag)
                ans++;
        }
        return ans;
    }
};
