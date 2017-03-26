#include <bits/stdc++.h>

using namespace std;

bool primes[1000001];
int cases, n, c;
set<long long>ans;
vector<int>p;

void seive()
{
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;
    for(int i = 2; i < 1000001; i++)
        if(primes[i])
        {
            p.push_back(i);
            for(int j = i*2; j < 1000001; j+=i)
                primes[j] = false;
        }
}

void prime_factors(long long x)
{
    for(int i = 0; i < p.size() && p[i] * p[i] <= x; i++)
    {
        bool flag = false;
        while(x % p[i] == 0)
        {
            x /= p[i];
            flag = true;
        }
        if(flag)
            ans.insert(p[i]);
    }
    if(x > 0 && x != 1)
        ans.insert(x);
}

int main()
{
    seive();
    scanf("%d", &cases);
    c = 1;
    while(cases--)
    {
        scanf("%d", &n);
        ans.clear();
        for(int i = 0; i < n; i++)
        {
            long long x;
            scanf("%lld", &x);
            prime_factors(x);
        }
        printf("Case #%d: %d\n", c++ ,ans.size());
        set<long long> :: iterator it;
        for(it = ans.begin(); it != ans.end(); it++)
            printf("%lld\n", *it);
    }
    return 0;
}
