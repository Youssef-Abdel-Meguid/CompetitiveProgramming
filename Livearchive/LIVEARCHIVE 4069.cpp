#include <bits/stdc++.h>

using namespace std;

int ans[16],sz;

int to_decimal(string s)
{
    int ret=0,p=1;
    for(int i=s.size()-1;i>=0;i--)
    {
        ret+=(s[i]-'0')*p;
        p*=-2;
    }
    return ret;
}

void to_binary(int x)
{
    memset(ans,0,sizeof(ans));
    sz=0;
    while(x)
    {
        ans[sz]=x%-2;
        x/=-2;
        if(ans[sz]==-1)
        {
            ans[sz]=1;
            if(x<0)
                x--;
            else
                x++;
        }
        sz++;
    }
}

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
        char c;
        cin>>c;
        if(c=='b')
        {
            string s;
            cin>>s;
            cout<<"From binary: "<<s<<" is "<<to_decimal(s)<<endl;
        }
        else
        {
            int x;
            cin>>x;
            to_binary(x);
            cout<<"From decimal: "<<x<<" is ";
            if(!x)
                cout<<x;
            else
                for(int i=sz-1;i>=0;i--)
                    cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}
