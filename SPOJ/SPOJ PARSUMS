#include <bits/stdc++.h>

using namespace std;

int a[2000000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[n+i]=a[i];
        }
        int ans=0,sum=0;
        for(int i=2*n-1;i>=0;i--)
        {
            sum+=a[i];
            if(sum>=0)
            {
                if(n>i)
                    ans++;
                sum=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
