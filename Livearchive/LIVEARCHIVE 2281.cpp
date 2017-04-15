/*
greedy
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r[16], g[16], b[16];
    for(int i = 0; i < 16; i++)
        cin >> r[i] >> g[i] >> b[i];
    int rr, gg, bb;
    while(cin >> rr >> gg >> bb)
    {
        if(rr == -1 && gg == -1 && bb == -1)
            break;
        int indx = -1;
        long long ans = 0;
        for(int i = 0; i < 16; i++)
        {
            long long d = (r[i]-rr)*(r[i]-rr)+(g[i]-gg)*(g[i]-gg)+(b[i]-bb)*(b[i]-bb);
            if(ans > d || indx == -1)
            {
                indx = i;
                ans = d;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", rr,gg,bb, r[indx], g[indx], b[indx]);
    }
    return 0;
}
