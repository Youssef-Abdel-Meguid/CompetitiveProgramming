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
        pair<int,int>pa[m];
        int sum=0,ans[n],p[n];
        for(int i=0;i<m;i++)
        {
            cin>>pa[i].first;
            sum+=pa[i].first;
            pa[i].second=i;
        }
        if(sum<n)
        {
            cout<<-1<<endl;
            continue;
        }
        sort(pa,pa+m);
        while(sum>n)
        {
            sort(pa,pa+m);
            pa[m-1].first--;
            sum--;
        }
        int pos=0;
        for(int i=0;i<n;i+=2)
            p[pos++]=i;
        for(int i=1;i<n;i+=2)
            p[pos++]=i;
        pos=0;
        sort(pa,pa+m);
        for(int i=m-1;i>=0;i--)
            for(int j=0;j<pa[i].first;j++)
                ans[p[pos++]]=pa[i].second+1;
        bool flag=true;
        for(int i=0;i<n&&flag;i++)
            if(ans[i]==ans[(i+1)%n])
                flag=false;
        if(!flag)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
