#include <bits/stdc++.h>

using namespace std;

class CyclicGame
{
public:
    double estimateBank(vector <int> cells)
    {
        double next[16],last[16];
        int n=cells.size();
        memset(next,0,sizeof(next));
        memset(last,0,sizeof(last));
        for(int k=0;k<1000000;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=1;j<=6;j++)
                    next[i]+=last[(i+j)%n]+cells[(i+j)%n];
                next[i]/=6;
                if(next[i]<0)
                    next[i]=0;
            }
            for(int i=0;i<n;i++)
                last[i]=next[i];
            memset(next,0,sizeof(next));
        }
        return last[0];
    }
};
