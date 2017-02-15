#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdio>

using namespace std;

double dp[502],p;
int a[12],n,maxx;
bool ismine[502];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(cin>>n>>p)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=0;i<n;i++)
            if(a[i+1]-a[i]>50)
                for(int j=n;j>i;j--)
                    a[j]-=(a[i+1]-a[i]-50);
        maxx=a[n];
        memset(dp,0,sizeof(dp));
        memset(ismine,false,sizeof(ismine));
        for(int i=1;i<=n;i++)
            ismine[a[i]]=true;
        dp[1]=1;
        for(int i=0;i<=maxx;i++)
            if(!ismine[i])
            {
                dp[min(i+1,maxx+1)]+=dp[i]*p;
                dp[min(i+2,maxx+1)]+=dp[i]*(1-p);
            }
        cout<<fixed<<setprecision(7)<<dp[maxx+1]<<endl;
    }
    return 0;
}
