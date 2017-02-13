#include <bits/stdc++.h>

using namespace std;

int a[1000],n,k,dp[1000][1000];

int solve(int l,int r)
{
    if(l>=r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    int ret=1e9;
    for(int i=l;i<=r;i++)
    {
        int x=a[i]*(r-l+1)+solve(i+1,r)+solve(l,i-1);
        ret=min(ret,x);
        //cout<<x<<" "<<l<<" "<<r<<endl;
    }
    return dp[l][r]=ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases,c=1;
    cin>>cases;
    while(cases--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            a[i]=i+k;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<c++<<": ";
        cout<<solve(1,n)<<endl;
    }
    return 0;
}
