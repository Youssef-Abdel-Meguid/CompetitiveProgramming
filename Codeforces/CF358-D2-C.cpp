#include <bits/stdc++.h>

using namespace std;

string pushs[4]={"pushStack","pushQueue","pushFront","pushBack"};
string pops[3]={"popStack","popQueue","popFront"};
vector<pair<int,pair<int,string> > >vec[100001];
int n,sz;

void init()
{
	sz=0;
	for(int i=0;i<=100000;i++)
		vec[i].clear();
}

bool cmp(pair<int,pair<int,string> > a,pair<int,pair<int,string> > b)
{
	return a.second.first<b.second.first;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(scanf("%d",&n)!=EOF)
    {
    	init();
    	int a,indx=0;
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&a);
    		if(a)
    			vec[sz].push_back(make_pair(i,make_pair(a,"")));
    		else
    			sz++;
    	}
    	if(a)
    		sz++;
    	for(int i=0;i<sz;i++)
    		sort(vec[i].rbegin(),vec[i].rend(),cmp);
    	for(int i=0;i<sz;i++)
    	{
    		int x=vec[i].size();
    		if(x>=1)
    			vec[i][0].second.second=pushs[0];
    		if(x>=2)
    			vec[i][1].second.second=pushs[1];
    		if(x>=3)
    			vec[i][2].second.second=pushs[2];
    		for(int j=3;j<x;j++)
    			vec[i][j].second.second=pushs[3];
    		sort(vec[i].begin(),vec[i].end());
    		for(int j=0;j<x;j++)
    			printf("%s\n",vec[i][j].second.second.c_str());
    		if(i==sz-1&&a)
    			continue;
    		if(!x)
    			printf("0\n");
    		else if(x==1)
    			printf("1 %s\n",pops[0].c_str());
    		else if(x==2)
    			printf("2 %s %s\n",pops[0].c_str(),pops[1].c_str());
    		else
    			printf("3 %s %s %s\n",pops[0].c_str(),pops[1].c_str(),pops[2].c_str());
    	}
    }
    return 0;
}
