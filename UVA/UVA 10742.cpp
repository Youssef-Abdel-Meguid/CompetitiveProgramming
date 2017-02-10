#include <bits/stdc++.h>

using namespace std;

vector<int>primes;
bool isprime[1000010];

void seive()
{
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<=1000000;i++)
        if(isprime[i])
        {
            primes.push_back(i);
            for(int j=i*2;j<=1000000;j+=i)
                isprime[j]=false;
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    seive();
    int n,c=1;
    while(scanf("%d",&n)&&n)
    {
        int ans=0;
        for(int i=0;i<primes.size();i++)
            if(primes[i]<n)
                ans+=lower_bound(primes.begin(),primes.end(),min(primes[i],n-primes[i]+1))-primes.begin();
        printf("Case %d: %d\n",c++,ans);
    }
    return 0;
}
