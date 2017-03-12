#include <bits/stdc++.h>

using namespace std;

int n,k,a[500000];

bool Maximizing(int mid)
{
	long long sum=0,sum1=0;
	for(int i=0;i<n;i++)
		if(a[i]>mid)
			sum+=(a[i]-mid);
		else
			sum1+=(mid-a[i]);
	return sum<=sum1&&sum<=k;
}

bool Minimizing(int mid)
{
	long long sum=0,sum1=0;
	for(int i=0;i<n;i++)
		if(a[i]<mid)
			sum+=(mid-a[i]);
		else
			sum1+=(a[i]-mid);
	return sum<=sum1&&sum<=k;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d%d",&n,&k)!=EOF)
    {
    	for(int i=0;i<n;i++)
    		scanf("%d",&a[i]);
    	int l=1,r=1e9,mid,ret1=0,ret2=0;
    	while(l<=r)
    	{
    		mid=(l+r)/2;
    		if(Maximizing(mid))
    		{
    			ret1=mid;
    			r=mid-1;
    		}
    		else
    			l=mid+1;
    	}
    	l=1,r=1e9;
    	while(l<=r)
    	{
    		mid=(l+r)/2;
    		if(Minimizing(mid))
    		{
    			ret2=mid;
    			l=mid+1;
    		}
    		else
    			r=mid-1;
    	}
    	printf("%d\n",ret1-ret2);
    }
    return 0;
}
