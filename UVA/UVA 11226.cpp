#include <bits/stdc++.h>

using namespace std;

bool isprime[500001];
int factors_sum[500001],lsopf[500001];

void seive()
{
	memset(isprime,true,sizeof(isprime));
	for(long long i=2;i*i<=500000;i++)
		if(isprime[i])
			for(long long j=i*2;j<=500000;j+=i)
				isprime[j]=false;
}

void prime_factors()
{
	factors_sum[1]=1;
	for(int i=2;i<=500000;i++)
	{
		int prime=2,tmp=i;
		while(!isprime[tmp])
		{
			if(isprime[prime]&&tmp%prime==0)
			{
				factors_sum[i]+=prime;
				tmp/=prime;
			}
			else
				prime++;
		}
		if(isprime[tmp])
			factors_sum[i]+=tmp;
	}
	for(int i=1;i<=500000;i++)
	{
		lsopf[i]=1;
		int x=i;
		while(factors_sum[x]!=x)
		{
			lsopf[i]++;
			x=factors_sum[x];
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    seive();
    prime_factors();
    int cases,c=1;
    scanf("%d",&cases);
    while(cases--)
    {
    	int n,m,ans=-1;
    	scanf("%d%d",&n,&m);
    	if(n>m)
    		swap(n,m);
    	for(int i=n;i<=m;i++)
    		ans=max(ans,lsopf[i]);
    	printf("Case #%d:\n%d\n",c++,ans);
    }
    return 0;
}
