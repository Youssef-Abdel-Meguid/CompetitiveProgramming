#include <bits/stdc++.h>

using namespace std;

class BinaryCards
{
    string to_binary(long long x)
    {
        string ret="";
        while(x)
        {
            if(x&1)
                ret+='1';
            else
                ret+='0';
            x>>=1;
        }
        return ret;
    }
public:
    long long largestNumber(long long A, long long B)
    {
        pair<long long,bool>pa[64];
        long long x=1;
        for(int i=1;i<64;i++)
        {
            pa[i].first=x;
            x<<=1;
            pa[i].second=false;
        }
        string s=to_binary(A);
        long long ans=A;
        for(int i=1,j=0;j<s.size()&&i<64;i++,j++)
            if(s[j]=='1')
                pa[i].second=true;
        for(int i=1;i<64;i++)
        {
            if(ans>=B)
                return ans;
            if(!pa[i].second)
                ans+=pa[i].first;
        }
        return ans;
    }
};
