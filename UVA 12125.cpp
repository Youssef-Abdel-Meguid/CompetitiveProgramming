#include <bits/stdc++.h>

using namespace std;

int n,cap[205][205],flow[205][205],pre[205];
double d,x[105],y[105];

int bfs(int s,int t)
{
	queue<int>q;
	q.push(s);
	for(int i=0;i<2*n;i++)
		pre[i]=-2;
	pre[s]=-1;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		if(x==t)
		{
			int new_flow=1e9;
			for(int i=t;pre[i]!=-1;i=pre[i])
				new_flow=min(new_flow,flow[pre[i]][i]);
			//cout<<new_flow<<endl;
			return new_flow;
		}
		for(int i=0;i<2*n;i++)
		{
			if(pre[i]==-2&&flow[x][i])
			{
				//cout<<flow[x][i]<<endl;
				pre[i]=x;
				q.push(i);
			}
		}
	}
	return 0;
}

int max_flow(int s,int t)
{
	memcpy( flow, cap, sizeof flow );
	int ret=0,new_flow=0;
	while(new_flow=bfs(s,t))
	{
		ret+=new_flow;
		for(int i=t;pre[i]!=-1;i=pre[i])
		{
			flow[pre[i]][i]-=new_flow;
			flow[i][pre[i]]+=new_flow;
		}
	}
	return ret;
}

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
    	cin>>n>>d;
    	int total_pen=0;
    	n++;
    	memset(cap,0,sizeof(cap));
    	for(int i=1;i<n;i++)
    	{
    		int p,m;
    		cin>>x[i]>>y[i]>>p>>m;
    		total_pen+=p;
    		cap[i][i+n]=m;
    		cap[n][i]=p;
    	}
    	for(int i=1;i<n;i++)
    		for(int j=i+1;j<n;j++)
    		{
    			double dis=hypot(x[i]-x[j],y[i]-y[j]);
    			if(d+1e-7>=dis)
    			{
    				cap[i+n][j]=1e9;
    				cap[j+n][i]=1e9;
    			}
    		}
    	cap[0][n]=1e9;
    	bool found=false;
    	for(int i=1;i<n;i++)
    		if(max_flow(0,i)==total_pen)
    		{
    			if(!found)
    				found=true;
    			else
    				printf(" ");
    			printf("%d",i-1);
    		}
    	if(!found)
    		printf("-1");
    	printf("\n");
    }
    return 0;
}
