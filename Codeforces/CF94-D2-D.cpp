#include <bits/stdc++.h>

using namespace std;

const double EPS=1e-9;
double a[51];
int cnt[51];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n,w,m;
    while(cin>>n>>w>>m)
    {
        memset(cnt,0,sizeof(cnt));
        memset(a,0,sizeof(a));
        vector<pair<int,double> >ans[50];
        double total=((n+0.0)*w)/m;
        for(int i=1;i<=n;i++)
            a[i]=w;
        bool flag=true;
        for(int i=0;i<m&&flag;i++)
        {
            double tmp=total;
            for(int j=1;j<=n&&flag;j++)
            {
                if(a[j]<EPS)
                    continue;
                if(tmp<EPS)
                    break;
                double x=min(tmp,(double)a[j]);
                a[j]-=x;
                tmp-=x;
                cnt[j]++;
                if(cnt[j]>2)
                    flag=false;
                ans[i].push_back(make_pair(j,x));
            }
        }
        if(!flag)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for (int i=0;i<m;i++)
            {
                for(int j=0;j<ans[i].size();j++)
                    cout<<fixed<<setprecision(6)<<ans[i][j].first<<" "<<ans[i][j].second<<" ";
                cout<<"\n";
            }
        }
    }
    return 0;
}
