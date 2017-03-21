#include <bits/stdc++.h>

using namespace std;

typedef vector<long long>row;
typedef vector<row>matrix;

const int mod = 1e9;

matrix zero(int n,int m)
{
    return matrix(n, row(m, 0));
}

matrix identityMatrix(int n)
{
    matrix ret = zero(n, n);
    for(int i = 0; i < n; i++)
        ret[i][i] = 1;
    return ret;
}

matrix reflect(matrix a)
{
    matrix ret = zero(a.size(), a[0].size());
    for(int i = 0; i < a.size() ; i++)
        for(int j = 0; j < a[0].size() ; j++)
            ret[j][a.size() - 1 - i] = a[i][j];
    return ret;
}

matrix add(matrix &a, matrix &b)
{
    matrix ret = zero(a.size() , a[0].size());
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a[0].size(); j++)
            ret[i][j] = a[i][j] + b[i][j];
    return ret;
}

matrix addidentity(matrix &a)
{
    matrix ret = a;
    for(int i = 0; i < a.size(); i++)
        ret[i][i] += 1;
    return ret;
}

matrix multiply(const matrix &a, const matrix &b)
{
    matrix ret = zero(a.size(), b[0].size());
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b[0].size(); j++)
            for(int k = 0; k < b[0].size(); k++)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
    return ret;
}

matrix power(const matrix& a, long long p)
{
    if(p == 0)
        return identityMatrix(a.size());
    if(p % 2 == 1)
        return multiply(a, power(a, p - 1));
    return power(multiply(a, a), p / 2);
}

int k, b[10], c[10], n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
            scanf("%d", &b[i]);
        for(int i = 0; i < k; i++)
            scanf("%d", &c[i]);
        scanf("%d", &n);
        if(n <= k)
        {
            printf("%d\n", b[n - 1]);
            continue;
        }
        matrix init = zero(k, k);
        for (int i = 0; i < k; ++i)
        {
            init[0][i] = b[i];
        }
        matrix trans = zero(k, k);
        for (int i = 1; i < k; ++i)
        {
            trans[i][i-1] = 1;
        }
        for (int i = 0; i < k; ++i)
        {
            trans[i][k-1] = c[k - i - 1];
        }
        matrix trnass = power(trans, n-k);
        matrix ans = multiply(init, trnass);
        printf("%lld\n", ans[0][k-1]);
    }
    return 0;
}
