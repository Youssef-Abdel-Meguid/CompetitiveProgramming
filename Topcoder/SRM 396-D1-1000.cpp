#include <bits/stdc++.h>

using namespace std;

class MoreNim
{
public:
    long long bestSet(vector <string> heaps)
    {
        vector<long long>a,b;
        for(int i=0;i<heaps.size();i++)
        {
            stringstream ss;
            ss<<heaps[i];
            long long x;
            ss>>x;
            a.push_back(x);
            b.push_back(x);
        }
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        long long ret=0;
        for(int i=0;i<a.size();i++)
        {
            if(!a[i])
            {
                ret+=b[i];
                continue;
            }
            long long last_bit=(a[i]&-a[i]);
            for(int j=i+1;j<a.size();j++)
                if(a[j]&last_bit)
                    a[j]^=a[i];
        }
        return ret;
    }
};
