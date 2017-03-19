/*
  The idea explanition: https://saicheems.wordpress.com/2013/08/21/uva-10264-the-most-potent-corner-2/
  Another solution: http://www.davidudelson.com/blog/2015/06/29/uva-10264-most-potent-corner/
*/

#include <bits/stdc++.h>

using namespace std;

int a[16384],sum[16384]; /* max n is 14 so 2^14 = 16384 */

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<(1<<n);i++)
            scanf("%d",&a[i]);
        for(int i=0;i<(1<<n);i++)
        {
            int edge_sum=0;
            for(int j=0;j<n;j++)
            {
                int pos=i^(1<<j);
                edge_sum+=a[pos];
            }
            sum[i]=edge_sum;
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<n;j++)
            {
                int pos=i^(1<<j);
                ans=max(ans,sum[pos]+sum[i]);
            }
        printf("%d\n",ans);
    }
    return 0;
}
