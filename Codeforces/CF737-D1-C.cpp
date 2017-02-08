#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n,s;
    while(cin>>n>>s)
    {
       map<int,int>ma;
       int x,ans=0;
       for(int i=1;i<=n;i++)
       {
            cin>>x;
            if(i==s&&x)
                ans++;
            else if(i!=s&&!x)
                ma[n+1]++;
            else if(x)
                ma[x]++;
       }
       for(int i=1;ma.size()&&i<=n-1;i++)
            if(ma.count(i))
                ma.erase(i);
            else
            {
                int mx=ma.rbegin()->first;
                ma[mx]--;
                ans++;
                if(!ma[mx])
                    ma.erase(mx);
            }
        cout<<ans<<endl;
    }
    return 0;
}
