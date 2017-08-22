#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int indx;
	long long val;
};

int n,m,w,a[100000];
long long lazy[4*100001];
Node tree[4*100001];

Node get_min(Node a,Node b)
{
	if(a.val<=b.val)
		return a;
	return b;
} 

void build(int indx,int s,int e)
{
	if(s==e)
	{
		tree[indx].indx=s;
		tree[indx].val=a[s];
		return;
	}
	int mid=(s+e)/2;
	build(indx*2,s,mid);
	build(indx*2+1,mid+1,e);
	tree[indx]=get_min(tree[indx*2],tree[indx*2+1]);
}

void relax(int indx,int s,int e,int val)
{
	tree[indx].val+=val;
	if(s!=e)
	{
		lazy[indx*2]+=val;
		lazy[indx*2+1]+=val;
	}
	lazy[indx]=0;
}

void update(int indx,int s,int e,int st,int en,int val)
{
	relax(indx,s,e,lazy[indx]);
	if(s>en||st>e)
		return;
	if(s>=st&&e<=en)
	{
		relax(indx,s,e,val);
		return;
	}
	int mid=(s+e)/2;
	update(indx*2,s,mid,st,en,val);
	update(indx*2+1,mid+1,e,st,en,val);
	tree[indx]=get_min(tree[indx*2],tree[indx*2+1]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d%d%d",&n,&m,&w)!=EOF)
    {
    	memset(lazy,0,sizeof(lazy));
    	for(int i=0;i<n;i++)
    		scanf("%d",&a[i]);
    	build(1,0,n-1);
    	while(m--)
    	{
    		int st,en;
    		st=tree[1].indx;
    		en=st+w-1;
    		if(en>=n)
    		{
    			st-=(en-(n-1));
    			en=n-1;
    		}
    		update(1,0,n-1,st,en,1);
    	}
    	printf("%I64d\n",tree[1].val);
    }
   	return 0;
}
