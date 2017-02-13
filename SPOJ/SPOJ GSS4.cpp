#include <bits/stdc++.h>

using namespace std;

long long tree[500001],a[100001];
int n;

void build(int indx,int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        tree[indx]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(indx*2,l,mid);
    build(indx*2+1,mid+1,r);
    tree[indx]=tree[indx*2]+tree[indx*2+1];
}

long long query(int indx,int l,int r,int x,int y)
{
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return tree[indx];
    int mid=(l+r)/2;
    return query(indx*2,l,mid,x,y)+query(indx*2+1,mid+1,r,x,y);
}

void update(int indx,int l,int r,int x,int y)
{
    if(l>y||r<x)
        return;
    if(r-l+1==tree[indx])
        return;
    if(l==r)
    {
        tree[indx]=(long long)(sqrt((double)tree[indx]));
        return;
    }
    int mid=(l+r)/2;
    update(indx*2,l,mid,x,y);
    update(indx*2+1,mid+1,r,x,y);
    tree[indx]=tree[indx*2]+tree[indx*2+1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int c=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        build(1,1,n);
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",c++);
        while(q--)
        {
            int t,x,y;
            scanf("%d%d%d",&t,&x,&y);
            if(x>y)
                swap(x,y);
            if(t)
                printf("%lld\n",query(1,1,n,x,y));
            if(!t)
                update(1,1,n,x,y);
        }
        printf("\n");
    }
    return 0;
}
