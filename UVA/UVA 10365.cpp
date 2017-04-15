/*
O(n^3) will fit in the TL with the condition in the loops :D ,,, cuz actullay it's not n^3 ,,, assume the worest case (n = 1000)
the number of steps = ~3400 ,,, which fits in TL
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int n;
        scanf("%d", &n);
        int ans = 1e9;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n && (i * j) <= n; j++)
                for(int k = 1; k <= n && (i * j * k) <= n; k++)
                    if(i * j * k == n)
                        ans = min(ans, 2*(i * j + i * k + k * j));
        printf("%d\n", ans);
    }
    return 0;
}
