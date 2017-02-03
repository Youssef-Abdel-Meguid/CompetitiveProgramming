#include <bits/stdc++.h>

using namespace std;

long long countt[20001],dis[20001];

void add(int indx,int val,long long a[])
{
    while(indx<20001)
    {
        a[indx]+=val;
        indx+=(indx&-indx);
    }
}

long long get_sum(int indx,long long a[])
{
    long long ret=0;
    while(indx)
    {
        ret+=a[indx];
        indx-=(indx&-indx);
    }
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(cin>>n)
    {
        pair<int,int>pa[n];
        for(int i=0;i<n;i++)
            cin>>pa[i].first>>pa[i].second;
        sort(pa,pa+n);
        memset(countt,false,sizeof(countt));
        memset(dis,false,sizeof(dis));
        long long ans=0,tot_dis=0;
        for(int i=0;i<n;i++)
        {
            long long c=get_sum(pa[i].second,countt);
            long long d=get_sum(pa[i].second,dis);
            ans+=pa[i].first*(c*pa[i].second-d);
            ans+=pa[i].first*(tot_dis-d-(i-c)*pa[i].second);
            tot_dis+=pa[i].second;
            add(pa[i].second,1,countt);
            add(pa[i].second,pa[i].second,dis);
        }
        cout<<ans<<endl;
    }    
    return 0;
}
