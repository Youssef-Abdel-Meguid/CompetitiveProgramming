#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif*/
    int n;
    while(cin>>n)
    {
        long long v[n],d[n],p[n];
        for(int i=0;i<n;i++)
            cin>>v[i]>>d[i]>>p[i];
        vector<long long>ans;
        bool visi[n];
        memset(visi,false,sizeof(visi));
        for(int i=0;i<n;i++)
        {
            if(visi[i])
                continue;
            ans.push_back(i+1);
            for(int j=i+1;j<n;j++)
                if(v[i])
                {
                    if(visi[j])
                        continue;
                    p[j]-=v[i];
                    v[i]--;
                }
            long long x=0;
            for(int j=i+1;j<n;j++)
            {
                if(visi[j])
                    continue;
                if(x>p[j])
                {
                    visi[j]=true;
                    x+=d[j];
                }
                else
                    p[j]-=x;
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
