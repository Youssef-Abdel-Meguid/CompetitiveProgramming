#include <bits/stdc++.h>

using namespace std;

int bit[100001],a[100001];

void add(int indx,int val)
{
    while(indx<=100000)
    {
        bit[indx]+=val;
        indx+=(indx&-indx);
    }
}

int get_sum(int indx)
{
    int ret=0;
    while(indx)
    {
        ret+=bit[indx];
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
        memset(bit,0,sizeof(bit));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            int l,r;
            cin>>l>>r;
            int ans1=get_sum(l);
            int ans2=get_sum(r);
            int ans=ans1-a[l]+ans2-a[r];
            cout<<ans<<endl;
            a[l]=ans1;
            a[r]=ans2;
            add(l+1,1);
            add(r,-1);
        }
    }
    return 0;
}
