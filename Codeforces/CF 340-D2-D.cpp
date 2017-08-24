#include<bits/stdc++.h>

using namespace std;

int a[100001],tree[1000000];

void update(int pos,int l,int r,int val,int node)
{
    if(l==r)
        {
            tree[pos]=val;
            return;
        }
    int mid=(l+r)/2;
    if(node<=mid)
        update(2*pos+1,l,mid,val,node);
    else
        update(2*pos+2,mid+1,r,val,node);
    tree[pos]=max(tree[2*pos+1],tree[2*pos+2]);
}

int get_max(int pos,int l,int r,int ql,int qr)
{
    if(l>=ql&&r<=qr)
        return tree[pos];
    if(r<ql||l>qr)
        return 0;
    int mid=(l+r)/2;
    return max(get_max(pos*2+1,l,mid,ql,qr),get_max(pos*2+2,mid+1,r,ql,qr));
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=n-1;i>=0;i--)
        {
            int sofar=get_max(0,1,n,a[i],n);
            ans=max(sofar+1,ans);
            update(0,1,n,sofar+1,a[i]);
        }
    cout<<ans<<endl;
    return 0;
}
