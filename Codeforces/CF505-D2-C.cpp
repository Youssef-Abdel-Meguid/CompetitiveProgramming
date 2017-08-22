#include <bits/stdc++.h>

using namespace std;

int n,d,a[30001],dp[30001][500];

int solve(int indx,int len)
{
    if(indx>30000||!(d+len))
        return 0;
    if(dp[indx][len]!=-1)
        return dp[indx][len];
    int ret=0;
    ret=a[indx]+max(max(solve(indx+d+len-1,len-1),solve(indx+d+len,len)),solve(indx+d+len+1,len+1));
    return dp[indx][len]=ret;
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif*/
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        printf("%d\n",solve(d,0));
    }
    return 0;
}
