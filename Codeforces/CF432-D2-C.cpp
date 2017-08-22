#include <bits/stdc++.h>

using namespace std;

bool isprime[100010];

void seive()
{
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
    for(int f=2;f<=sqrt(100009);f++)
    if(isprime[f])
        for(int f1=f*f;f1<100009;f1+=f)
            isprime[f1]=false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    seive();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    	int a[n+1],pos[n+1];
    	vector<pair<int,int> >ans; 
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&a[i]);
    		pos[a[i]]=i;
    	}
    	for(int i=n;i>0;i--)
    	{
    		while(pos[i]+1!=i)
    		{
    			int x=i-pos[i];
    			while(isprime[x]==false)
    				x--;
    			ans.push_back(make_pair(pos[i]+1,pos[i]+x));
    			swap(a[pos[i]],a[pos[i]+x-1]);
    			swap(pos[a[pos[i]]],pos[a[pos[i]+x-1]]);
    		}
    	}
    	cout<<ans.size()<<endl;
    	for(int i=0;i<ans.size();i++)
    		printf("%d %d\n",ans[i].first,ans[i].second);
    }
   	return 0;
}
