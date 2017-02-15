#include <bits/stdc++.h>

using namespace std;

class KSubstring
{
public:
    vector <int> maxSubstring(int A0, int X, int Y, int M, int n)
    {
        long long a[n],b[n+1];
        a[0]=A0;
        b[0]=0;
        b[1]=A0;
        for(int i=1;i<n;i++)
        {
            a[i]=(a[i-1]*X+Y)%M;
            b[i+1]=b[i]+a[i];
        }
        long long min_diff=1e18;
        int k=0;
        for(int i=n/2;i>0;i--)
        {
            set<long long>se;
            long long aa[n+1];
            for(int j=0;j+i<=n;j++)
            {
                if(j>=i)
                    se.insert(aa[j-i]);
                long long diff=b[j+i]-b[j];
                set<long long>::iterator it=se.lower_bound(diff);
                if(it!=se.end())
                {
                    if(*it-diff<min_diff)
                    {
                        min_diff=*it-diff;
                        k=i;
                    }
                }
                if(it!=se.begin())
                {
                    it--;
                    if(diff-*it<min_diff)
                    {
                        min_diff=diff-*it;
                        k=i;
                    }
                }
                aa[j]=diff;
            }
            if(!min_diff)
                break;
        }
        vector<int>ret;
        ret.push_back(k);
        ret.push_back(min_diff);
        return ret;
    }
};
