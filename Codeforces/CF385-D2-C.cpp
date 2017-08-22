#include <bits/stdc++.h>

using namespace std;

int primes[10000001],cnt[10000001],n,x,m,ans[10000001],l,r;

void seive()
{
	memset(primes,true,sizeof(primes));
	primes[0]=primes[1]=false;
	for(int i=2;i*i<=10000000;i++)
		if(primes[i])
			for(int j=2*i;j<=10000000;j+=i)
				primes[j]=false;
}

int f(int x)
{
	int ret=0;
	for(int i=x;i<=10000000;i+=x)
		ret+=cnt[i];
	return ret;
}

void solve()
{
	for(int i=2;i<=10000000;i++)
	{
		if(primes[i])
			ans[i]=f(i);
		ans[i]+=ans[i-1];
	}
}

int main()
{
	/*#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif*/
    seive();
   /* while()
    {*/
        scanf("%d",&n);
    	/*memset(cnt,0,sizeof(cnt));
    	memset(ans,0,sizeof(ans));*/
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&x);
    		cnt[x]++;
    	}
    	solve();
    	scanf("%d",&m);
    	while(m--)
    	{
    		scanf("%d%d",&l,&r);
    		int a=ans[min(r,10000000)]-ans[min(l-1,10000000)];
    		printf("%d\n",a);
    	}
   /// }
   	return 0;
}
