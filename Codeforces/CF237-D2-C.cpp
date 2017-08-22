#include<bits/stdc++.h>

using namespace std;

int primes[1000001],a,b,k;

void seive()
{
    for(int i=2;i<=b;i++)
        primes[i]=1;
    for(int i=2;i<=b;i++)
        if(primes[i])
            for(int j=i+i;j<=b;j+=i)
                primes[j]=0;
    for(int i=2;i<=b;i++)
        primes[i]+=primes[i-1];
}

bool valid(int l)
{
    for(int i=a;i+l<=b+1;i++)
        if(primes[i+l-1]-primes[i-1]<k)
            return false;
    return true;
}

int bs()
{
    int s=1,e=b-a+1,mid,ret=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(valid(mid))
        {
            ret=mid;
            e=mid-1;
        }
        else
            s=mid+1;
    }
    return ret;
}

int main()
{
    while(cin>>a>>b>>k)
    {
        seive();
        cout<<bs()<<endl;
    }
    return 0;
}
