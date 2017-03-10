#include <bits/stdc++.h>

using namespace std;

vector<long long> divisors(long long num)
{
    vector<long long>ret;
    long long i;
    for(i=2;i*i<num;i++)
        if(num%i==0)
        {
            ret.push_back(i);
            ret.push_back(num/i);
        }
    if(i*i==num)
        ret.push_back(i);
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    long long n,m,k;
    while(scanf("%lld%lld%lld",&n,&m,&k)!=EOF)
    {
    	if(n%2==0)
    	{
    		printf("Marsel\n");
    		continue;
    	}
    	vector<long long>div=divisors(m);
    	bool flag=false;
    	if(m>1)
    		div.push_back(1);
    	for(int i=0;i<div.size()&&!flag;i++)
    		if(div[i]>=k)
    			flag=true;
    	if(flag)
    		printf("Timur\n");
    	else
    		printf("Marsel\n");
    }
    return 0;
}
