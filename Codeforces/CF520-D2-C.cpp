#include <bits/stdc++.h>

using namespace std;

int cnt[4];
char c[100001];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    	scanf("%s",c);
    	memset(cnt,0,sizeof(cnt));
    	for(int i=0;i<n;i++)
    		if(c[i]=='A')
    			cnt[0]++;
    		else if(c[i]=='C')
    			cnt[1]++;
    		else if(c[i]=='G')
    			cnt[2]++;
    		else
    			cnt[3]++;
    	long long ans=1;
    	int maxn=-1,cntt=1;
    	for(int i=0;i<4;i++)
    		if(cnt[i]>maxn)
    		{
    			cntt=1;
    			maxn=cnt[i];
    		}
    		else if(cnt[i]==maxn)
    			cntt++;
    	if(cntt==1)
    		printf("1\n");
    	else
    	{
    		for(int i=0;i<n;i++)
    			ans=(ans*cntt)%1000000007;
    		printf("%lld\n",ans);
    	}
    }
   	return 0;
}
