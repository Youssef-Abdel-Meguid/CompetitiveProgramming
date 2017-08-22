#include <bits/stdc++.h>

using namespace std;

int n,a[100001],dpl[100001],dpr[100001];

int solveL(int i)
{
    if(i>=n)
        return dpl[i]=1;
    if(dpl[i]!=-1)
        return dpl[i];
    int ret=1;
    if(a[i]<a[i+1])
        ret=solveL(i+1)+1;
    return dpl[i]=ret;
}

int solveR(int i)
{
    if(i<=1)
        return dpr[i]=1;
    if(dpr[i]!=-1)
        return dpr[i];
    int ret=1;
    if(a[i]>a[i-1])
        ret=solveR(i-1)+1;
    return dpr[i]=ret;
}

int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif*/
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(dpl,-1,sizeof(dpl));
        memset(dpr,-1,sizeof(dpr));
        for(int i=1;i<=n;i++)
        {
            solveL(i);
            solveR(i);
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            x=dpl[i+1];
            y=dpr[i-1];
            if(a[i+1]-a[i-1]>1)
                ans=max(ans,max(max(x+1,y+1),x+y+1));
            else
                ans=max(ans,max(x+1,y+1));
        }
        cout<<ans<<endl;
    }
   	return 0;
}
