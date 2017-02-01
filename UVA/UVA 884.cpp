#include <bits/stdc++.h>

using namespace std;

bool isprime[1000001];
int ans[1000001];

void seive()
{
    memset(isprime,true,sizeof(isprime));
    for (long long i=2;i*i<=1000001;i++) 
        if (isprime[i]) 
            for (int j=i*2;j<=1000001;j+=i)
                isprime[j]=false;
}

void prime_factors()
{
    seive();
    for(int i=2;i<=1000001;i++)
    {
        int p=2,tmp=i;
        while(!isprime[tmp])
        {
            if(isprime[p]&&tmp%p==0)
            {
                ans[i]++;
                tmp/=p;
            }
            else
                p++;
        }
        if(isprime[tmp])
            ans[i]++;
    }
    for(int i=3;i<=1000001;i++)
        ans[i]+=ans[i-1];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    prime_factors();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
