#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(cin>>n&&n)
    {
        deque<int>de1,de2;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            de1.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            de2.push_back(x);
        }
        sort(de1.begin(),de1.end());
        sort(de2.begin(),de2.end());
        int ans=0;
        while(de1.size())
        {
            if(de1.back()>de2.back())
            {
                de1.pop_back();
                de2.pop_back();
                ans+=200;
            }
            else if(de1.front()>de2.front())
            {
                de1.pop_front();
                de2.pop_front();
                ans+=200;
            }
            else if(de1.front()<de2.back())
            {
                de1.pop_front();
                de2.pop_back();
                ans-=200;
            }
            else
            {
                de1.pop_front();
                de2.pop_back();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
