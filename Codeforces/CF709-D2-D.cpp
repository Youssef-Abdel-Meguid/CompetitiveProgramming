#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    long long a,b,c,d;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF)
    {
        memset(arr,0,sizeof(arr));
        if(a+b+c+d==0)
        {
            cout<<1<<endl;
            continue;
        }
        if(b+c==0)
            if(a>0&&d>0)
            {
                cout<<"Impossible\n";
                continue;
            }
        long long x=0,y=0;
        if(b+c>0)
        {
            x++;
            y++;
        }
        while(x*(x-1)/2<a)
            x++;
        while(y*(y-1)/2<d)
            y++;
        if(x*(x-1)/2!=a||y*(y-1)/2!=d)
        {
            cout<<"Impossible\n";
            continue;
        }
        if(x*y!=b+c)
        {
            cout<<"Impossible\n";
            continue;
        }
        for(int i=0;i<y;i++)
        {
            int z=min(x,c);
            arr[z]++;
            c-=z;
        }
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<arr[x-i];j++)
                cout<<1;
            cout<<0;
        }
        for(int i=0;i<arr[0];i++)
            cout<<1;
        cout<<endl;
    }
    return 0;
}
