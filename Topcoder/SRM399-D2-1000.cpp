#include<bits/stdc++.h>

using namespace std;

class AvoidingProduct
{
public:
    vector <int> getTriple(vector <int> a, int n)
    {
        bool visi[2001];
        memset(visi,false,sizeof(visi));
        for(int i=0;i<a.size();i++)
            visi[a[i]]=true;
        vector<int>ans;
        int minn=1e9,x,y,z;
        for(int i=1;i<=100;i++)
        {
            if(visi[i])
                continue;
            for(int j=i;j<=100;j++)
            {
                if(visi[j])
                    continue;
                for(int k=j;k<=2000;k++)
                {
                    if(visi[k])
                        continue;
                    int a=abs(n-(i*j*k));
                    if(minn>a)
                    {
                        minn=a;
                        x=i,y=j,z=k;
                    }
                }
            }
        }
        ans.push_back(x);
        ans.push_back(y);
        ans.push_back(z);
        return ans;
    }
};
