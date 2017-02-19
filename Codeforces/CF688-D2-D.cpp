#include <bits/stdc++.h>

using namespace std;

int primes[1000001],cnt[1000001];

void seive()
{
    primes[0]=primes[1]=1;
    for(int i=2;i<=1000000;i++)
        if(!primes[i])
            for(int j=i;j<=1000000;j+=i)
                primes[j]=i;
}

void primes_factor(int x)
{
    while(x>1)
    {
        int p=primes[x];
        int c=0;
        while(x%p==0)
        {
            c++;
            x/=p;
        }
        cnt[p]=max(c,cnt[p]);
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    seive();
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            primes_factor(x);
        }
        bool found=true;
        while(k>1)
        {
            if(!cnt[primes[k]])
            {
                found=false;
                break;
            }
            cnt[primes[k]]--;
            k/=primes[k];
        }
        if(found)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
