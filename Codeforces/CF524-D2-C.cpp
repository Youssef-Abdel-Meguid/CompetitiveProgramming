#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
    	map<int,int>ma;
    	int x,q;
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&x);
    		for(int i=1;i<=k;i++)
    			if(ma[i*x])
    				ma[i*x]=min(ma[i*x],i);
    			else
    				ma[i*x]=i;
    	}
    	scanf("%d",&q);
    	map<int,int>::iterator it,it1;
    	while(q--)
    	{
    		scanf("%d",&x);
    		int ans=1e9,tmp;
    		for(it=ma.begin();it!=ma.end();it++)
    			if(it->first<=x)
    			{
    				int c=0;
    				//cout<<it->first<<" "<<it->second<<endl;
    				c+=it->second;
    				tmp=x-it->first;
    				it1=ma.find(tmp);
    				if(!tmp)
    				{
    					if(c<=k)
    						ans=min(ans,c);
    				}
    				else if(it1==ma.end())
    					continue;
    				c+=it1->second;
    				if(c<=k)
    					ans=min(c,ans);
    			}
    		if(ans==1e9)
    			printf("%d\n",-1);
    		else
    			printf("%d\n",ans);
    	}
    	//cout<<endl;
    }
   	return 0;
}
