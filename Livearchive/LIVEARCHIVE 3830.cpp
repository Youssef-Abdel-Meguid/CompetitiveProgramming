#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,x,cnt=0,ans;
        cin>>n;
        cin>>x;
        if(x==1)
            cnt++;
        ans=x;
        for(int i=1;i<n;i++)
        {
            cin>>x;
            if(x==1)
                cnt++;
            ans^=x;
        }
        if(cnt==n&&n%2)
            cout<<"Brother"<<endl;
        else if(cnt==n&&n%2==0)
            cout<<"John"<<endl;
        else
        {
            if(ans)
                cout<<"John"<<endl;
            else
                cout<<"Brother"<<endl;
        }
    }
    return 0;
}
