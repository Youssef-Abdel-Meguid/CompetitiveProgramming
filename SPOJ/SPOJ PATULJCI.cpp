#include <bits/stdc++.h>

using namespace std;

int a[300000];
vector<int>vec[100001];

void initi()
{
	for(int i=0;i<=100000;i++)
		vec[i].clear();
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n,c,q;
    while(scanf("%d%d",&n,&c)!=EOF)
    {
    	initi();
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&a[i]);
    		vec[a[i]].push_back(i);
    	}
    	scanf("%d",&q);
    	while(q--)
    	{
    		int l,r;
    		scanf("%d%d",&l,&r);
    		l--,r--;
    		int x=(r-l)+1;
    		bool found=false;
    		for(int i=0;i<=50&&!found;i++)
    		{
    			int val=a[l+(random()%x)];
    			int cnt=upper_bound(vec[val].begin(),vec[val].end(),r)-
    					lower_bound(vec[val].begin(),vec[val].end(),l);
    			if(cnt>x/2)
    			{
    				printf("yes %d\n",val);
    				found=true;
    			}
    		}
    		if(!found)
    			printf("no\n");
    	}
    }
    return 0;
}
