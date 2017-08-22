#include <bits/stdc++.h>

using namespace std;

int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif*/
    int n;
    while(cin>>n)
    {
        int a[n],b[n],c[n];
        for(int i=0;i<n;i++)
            a[i]=b[i]=i;
        bool visi[n];
        memset(visi,false,sizeof(visi));
        for(int i=0;i<n;i++)
        {
            c[i]=(a[i]+b[i])%n;
            visi[c[i]]=true;
        }
        bool flag=false;
        for(int i=0;i<n;i++)
            if(!visi[i])
                flag=true;
        if(flag)
            cout<<-1<<endl;
        else
        {
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
            for(int i=0;i<n;i++)
                cout<<b[i]<<" ";
            cout<<endl;
            for(int j=0;j<n;j++)
                cout<<c[j]<<" ";
            cout<<endl;
        }
    }
   	return 0;
}
