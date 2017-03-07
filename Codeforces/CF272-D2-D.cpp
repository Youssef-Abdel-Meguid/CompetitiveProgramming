#include <bits/stdc++.h>

using namespace std;

long long a[200000],m;
map<long long,long long>ma;
int n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d",&n)!=EOF)
    {
    	ma.clear();
    	long long s=0;
    	for(int i=0;i<2*n;i++)
    	{
    		scanf("%lld",&a[i]);
    		ma[a[i]]++;
    		if(i>=n&&a[i-n]==a[i])
    			s++;
    	}
    	scanf("%lld",&m);
    	long long ans=1;
    	map<long long,long long>::iterator it;
    	for(it=ma.begin();it!=ma.end();it++)
    	{
    		for(long long i=1;i<=it->second;i++)
    		{
    			long long tmp=i;
    			while(tmp%2==0&&s>0)
    			{
    				s--;
    				tmp/=2;
    			}
    			ans=(ans*tmp)%m;
    		}
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}
