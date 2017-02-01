#include <bits/stdc++.h>

using namespace std;

int n,k,a[10000];

int solve(int i,int j,int cnt)
{
    if(i>=n||j<0||i>j||cnt>k)
        return 0;
    int ret=0;
    if(a[i]==a[j])
        ret=solve(i+1,j-1,cnt);
    else
        ret=min(1+solve(i+1,j,cnt+1),1+solve(i,j-1,cnt+1));
    return ret;
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
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans=solve(0,n-1,0);
        if(ans>k)
            cout<<"Case "<<c++<<": Too difficult\n";
        else if(!ans)
            cout<<"Case "<<c++<<": Too easy\n";
        else
            cout<<"Case "<<c++<<": "<<ans<<"\n";
    }
    return 0;
}
