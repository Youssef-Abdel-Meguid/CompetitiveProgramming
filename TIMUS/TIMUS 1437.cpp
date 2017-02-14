#include <bits/stdc++.h>

using namespace std;

bool visi1[256][256][256],visi2[256+256+256];
int a,b,c,ans,tmp;

void cnt_ways(int x,int y,int z)
{
    if(!visi2[x])
    {
        visi2[x]=true;
        ans++;
    }

    if(!visi2[y])
    {
        visi2[y]=true;
        ans++;
    }

    if(!visi2[z])
    {
        visi2[z]=true;
        ans++;
    }

    if(!visi2[x+y])
    {
        visi2[x+y]=true;
        ans++;
    }

    if(!visi2[x+z])
    {
        visi2[x+z]=true;
        ans++;
    }

    if(!visi2[y+z])
    {
        visi2[y+z]=true;
        ans++;
    }
    
    if(!visi2[x+y+z])
    {
        visi2[x+y+z]=true;
        ans++;
    }
}

void solve(int x,int y,int z)
{
    visi1[x][y][z]=true;
    cnt_ways(x,y,z);

    if(!visi1[a][y][z])
        solve(a,y,z);

    if(!visi1[x][b][z])
        solve(x,b,z);

    if(!visi1[x][y][c])
        solve(x,y,c);

    tmp=min(a-x,y);
    if(!visi1[x+tmp][abs(y-tmp)][z])
        solve(x+tmp,abs(y-tmp),z);

    tmp=min(a-x,z);
    if(!visi1[x+tmp][y][abs(z-tmp)])
        solve(x+tmp,y,abs(z-tmp));

    tmp=min(b-y,x);
    if(!visi1[abs(x-tmp)][y+tmp][z])
        solve(abs(x-tmp),y+tmp,z);

    tmp=min(b-y,z);
    if(!visi1[x][y+tmp][abs(z-tmp)])
        solve(x,y+tmp,abs(z-tmp));

    tmp=min(c-z,x);
    if(!visi1[abs(x-tmp)][y][z+tmp])
        solve(abs(x-tmp),y,z+tmp);

    tmp=min(c-z,y);
    if(!visi1[x][abs(y-tmp)][z+tmp])
        solve(x,abs(y-tmp),z+tmp);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    while(cin>>a>>b>>c)
    {
        memset(visi1,false,sizeof(visi1));
        memset(visi2,false,sizeof(visi2));
        ans=0;
        solve(0,0,0);
        cout<<ans-1<<endl;
    }
    return 0;
}
