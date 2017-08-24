#include<bits/stdc++.h>

using namespace std;

long long arr[2<<17];
long long tree[2<<17];
int n,m;

void build_segment_tree(int l,int h,int pos,bool isor)
{
    if(l>h)
        return;
    if(l==h)
        {
            tree[pos]=arr[l];
            return;
        }
    int mid=(l+h)/2;
    build_segment_tree(l,mid,2*pos+1,!isor);
    build_segment_tree(mid+1,h,2*pos+2,!isor);
    if(isor)
        tree[pos]=tree[2*pos+2]|tree[2*pos+1];
    else
        tree[pos]=tree[2*pos+2]^tree[2*pos+1];
}

void update(int a,int b,int l,int h,int pos,bool isor)
{
    if(l>h)
        return;
    if(l==h)
        {
            tree[pos]=b;
            return;
        }
    int mid=(l+h)/2;
    if(a<=mid)
        update(a,b,l,mid,pos*2+1,!isor);
    else
        update(a,b,mid+1,h,pos*2+2,!isor);
    if(isor)
        tree[pos]=tree[pos*2+2]|tree[pos*2+1];
    else
        tree[pos]=tree[pos*2+2]^tree[pos*2+1];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=1<<n;i++)
        scanf("%d",&arr[i]);
    build_segment_tree(1,(1<<n),1,n&1);
    while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            update(a,b,1,(1<<n),1,n&1);
            printf("%d\n",tree[1]);
        }
    return 0;
}
