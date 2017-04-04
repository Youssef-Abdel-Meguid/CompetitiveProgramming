/*
easy dp games problem just iterate over all stones and if u can take any number of stones form the m number gevin in the input ,,, and 
dp[i - a[j]] = false ,, then you will lose in i - a[j] state ,,, then mark dp[i] = true ,,, now you taked a[j] stones and force the
other player in a losing position
*/

#include<bits/stdc++.h>

using namespace std;

bool dp[1000001];

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int a[m];
        for(int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        memset(dp, false, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < m; j++)
                if(i >= a[j] && !dp[i - a[j]])
                {
                    dp[i] = true;
                    break;
                }
        if(dp[n])
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
