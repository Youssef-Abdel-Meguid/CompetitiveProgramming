#include <bits/stdc++.h>

using namespace std;

class GridCut
{
public:
    int cutLength(int width, int height, int n)
    {
        if(width*height==n)
            return 0;
        if(height==1||width==1)
            return 1;
        int ans=1e9;
        n=min(n,width*height-n);
        for(int i=1;i<=width;i++)
            for(int j=1;j<=height;j++)
                if(i*j>=n)
                    ans=min(ans,i+j);
        ans=min(ans,min(height+1,width+1));
        if(n%width==0)
            ans=min(ans,width);
        if(n%height==0)
            ans=min(ans,height);
        return ans;
    }
};
