#include <bits/stdc++.h>

using namespace std;

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
    	int n;
    	scanf("%d",&n);
    	vector<pair<long long,pair<long long,long long> > >vec;
    	for(int i=0;i<n;i++)
    	{
    		long long a,b,d;
    		scanf("%lld%lld%lld",&a,&b,&d);
    		vec.push_back(make_pair(d,make_pair(a,b)));
    	}
    	sort(vec.begin(),vec.end());
    	priority_queue<pair<int,int> >q;
    	double ans=0.0,t=0.0;
    	for(int i=0;i<n;i++)
    	{
    		q.push(make_pair(vec[i].second.first,vec[i].second.second));
    		t+=vec[i].second.second;
    		while(t>vec[i].first)
    		{
    			pair<int,int>pa=q.top();
    			q.pop();
    			if(t-pa.second<=vec[i].first)
    			{
    				pa.second-=t-vec[i].first;
    				ans+=(double)(t-vec[i].first)/(double)pa.first;
    				t=vec[i].first;
    				q.push(pa);
    			}
    			else
    			{
    				ans+=(double)(pa.second)/(double)pa.first;
    				t-=pa.second;
    			}
    		}
    	}
    	printf("%0.2lf\n",ans);

    }
    return 0;
}
