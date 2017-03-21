/*
the solution is => calculate the fibonacci for n+1 ,,, and the answer will be this number % (1 << m) 

n = 2147483647 ,,, so we can't calculate the fibonacci in O(n) ,,, so we need something faster ,,, we gonna use matrix to get that 
number just in O(log n)

u can know more about this approach here : https://www.youtube.com/watch?v=Tm0KGpoQ5JA

*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<long long>row;
typedef vector<row>matrix;

long long n;
int max_inbox, m;

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
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % max_inbox;
    return ret;
}

matrix power(const matrix& a, int p)
{
    if(p == 0)
        return identityMatrix(a.size());
    if(p % 2 == 1)
        return multiply(a, power(a, p - 1));
    return power(multiply(a, a), p / 2);
}

int fib_matix(long long n)
{
    if(n <= 1)
        return n;
    matrix trans = zero(2, 2);
    trans[0][1] = trans[1][0] = trans[1][1] = 1;
    matrix trans_n = power(trans, n-1);
    matrix init = zero(2, 2);
    init[0][1] = 1;
    matrix fib = multiply(init, trans_n);
    return fib[0][1];
}

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
        scanf("%lld%d", &n, &m);
        max_inbox = 1 << m;
        printf("%d\n", fib_matix(n+1));
    }
    return 0;
}
