#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n,m;
    while(cin>>n>>m)
    {
        bool leadders[n+1];
        memset(leadders,true,sizeof(leadders));
        pair<char,int>pa[m];
        for(int i=0;i<m;i++)
            cin>>pa[i].first>>pa[i].second;
        set<int>se;
        for(int i=m-1;i>=0;i--)
            if(pa[i].first=='-')
                se.insert(pa[i].second);
            else
                se.erase(pa[i].second);
        for(int i=0;i<m;i++)
            if(pa[i].first=='+')
            {
                if((se.size()&&m>1)||(i>0&&pa[i].second!=pa[i-1].second))
                    leadders[pa[i].second]=false;
                se.insert(pa[i].second);
            }
            else
            {
                se.erase(pa[i].second);
                if((se.size()&&m>1)||(i<m-1&&pa[i].second!=pa[i+1].second))
                    leadders[pa[i].second]=false;
            }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(leadders[i])
                ans++;
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
            if(leadders[i])
                cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
