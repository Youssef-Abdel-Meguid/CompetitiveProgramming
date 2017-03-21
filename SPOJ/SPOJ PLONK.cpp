#include <bits/stdc++.h>

using namespace std;

long long dx[100001],dy[100001],cntx[100001],cnty[100001];
int x[10000],y[10000];

void add(long long tree[],long long val,int indx)
{
    while(indx<100001)
    {
        tree[indx]+=val;
        indx+=(indx&-indx);
    }
}

long long get_sum(long long tree[],int indx)
{
    long long ret=0;
    while(indx)
    {
        ret+=tree[indx];
        indx-=(indx&-indx);
    }
    return ret;
}

long long sum_range(long long tree[], int l,int r)
{
    return get_sum(tree,r)-get_sum(tree,l-1);
}

void initi()
{
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(dx,0,sizeof(dx));
    memset(dy,0,sizeof(dy));
    memset(cntx,0,sizeof(cntx));
    memset(cnty,0,sizeof(cnty));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        initi();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            add(cntx,1,x[i]);
            add(cnty,1,y[i]);
            add(dx,x[i],x[i]);
            add(dy,y[i],y[i]);
        }
        long long ans=2e18;
        for(int i=0;i<n;i++)
        {
            long long al=sum_range(cntx,1,x[i]),ar=sum_range(cntx,x[i],100001);
            long long bl=sum_range(cnty,1,y[i]),br=sum_range(cnty,y[i],100001);
            long long cl=sum_range(dx,1,x[i]),cr=sum_range(dx,x[i],100001);
            long long dl=sum_range(dy,1,y[i]),dr=sum_range(dy,y[i],100001);
            ans=min(ans,(x[i]*al-cl)+(cr-x[i]*ar)+(y[i]*bl-dl)+(dr-y[i]*br));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
