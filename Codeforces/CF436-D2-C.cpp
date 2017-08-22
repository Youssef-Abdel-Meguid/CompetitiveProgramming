#include <bits/stdc++.h>

using namespace std;

char a[1001][11][11];
int cost[1001][1001],cur_cost[1001],parent[1001];
bool visi[1001];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n,m,k,w;
    while(scanf("%d%d%d%d",&n,&m,&k,&w)!=EOF)
    {
    	for(int ii=1;ii<=k;ii++)
    		for(int i=1;i<=n;i++)
    			for(int j=1;j<=m;j++)
    				cin>>a[ii][i][j];
    	memset(cost,0,sizeof(cost));
    	memset(cur_cost,0,sizeof(cur_cost));
    	memset(parent,0,sizeof(parent));
    	memset(visi,false,sizeof(visi));
    	for(int ii=1;ii<=k;ii++)
    		for(int jj=ii+1;jj<=k;jj++)
    			for(int i=1;i<=n;i++)
    				for(int j=1;j<=m;j++)
    					cost[ii][jj]=cost[jj][ii]+=((int)(a[ii][i][j]!=a[jj][i][j]))*w;
    	for(int i=1;i<=k;i++)
    	{
    		cost[i][0]=cost[0][i]=n*m;
    		cur_cost[i]=n*m;
    	}
    	vector<pair<int,int> >vec;
    	int indx,minx,ans=0;
    	cur_cost[1]=-1;
    	for(int ii=1;ii<=k;ii++)
    	{
    		minx=1e9;
    		for(int i=1;i<=k;i++)
    			if(!visi[i]&&cur_cost[i]<minx)
    			{
    				minx=cur_cost[i];
    				indx=i;
    			}
    		ans+=cost[indx][parent[indx]];
    		vec.push_back(make_pair(indx,parent[indx]));
    		visi[indx]=true;
    		for(int i=1;i<=k;i++)
    			if(indx!=i&&cur_cost[i]>cost[i][indx])
    			{
    				cur_cost[i]=cost[i][indx];
    				parent[i]=indx;
    			}
    	}
    	printf("%d\n",ans);
    	for(int i=0;i<vec.size();i++)
    		printf("%d %d\n",vec[i].first,vec[i].second);
    }
   	return 0;
}
