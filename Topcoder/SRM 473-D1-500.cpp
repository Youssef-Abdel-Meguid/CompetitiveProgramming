#include<bits/stdc++.h>

using namespace std;

class RightTriangle
{
public:
    long long triangleCount(int places, int points, int a, int b, int c)
    {
        if(places%2)
            return 0;
        bool isred[1000000];
        memset(isred,false,sizeof(isred));
        set<int>se;
        for(int i=0;i<places;i++)
            se.insert(i);
        for(int i=0;i<points;i++)
        {
            long long y=((1LL*a * i * i)%places + (1LL*b * i)%places + c)%places;
            int x=y;
            set<int>::iterator it=se.lower_bound(x);
            if(it==se.end())
                it=se.begin();
            isred[*it]=true;
            se.erase(it);
        }
        long long ans=0;
        for(int i=0;i<places/2;i++)
            if(isred[i]&&isred[i+places/2])
                ans+=(points-2);
        return ans;
    }
};
