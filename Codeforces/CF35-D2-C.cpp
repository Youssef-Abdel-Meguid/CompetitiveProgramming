#include <bits/stdc++.h>

using namespace std;

int n,m,k,ansr,ansc;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool visi[2000][2000];
queue<pair<int,int>>q;

bool isvalid(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m&&!visi[i][j];
}

void bfs()
{
    while(q.size())
    {
        ansr=q.front().first;
        ansc=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int r=dx[i]+ansr;
            int c=dy[i]+ansc;
            if(isvalid(r,c))
            {
                visi[r][c]=true;
                q.push(make_pair(r,c));
            }
        }
    }
}

int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif*/
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(cin>>n>>m)
    {
        memset(visi,false,sizeof(visi));
        cin>>k;
        while(k--)
        {
            int x,y;
            cin>>x>>y;
            x--,y--;
            visi[x][y]=true;
            q.push(make_pair(x,y));
        }
        bfs();
        cout<<ansr+1<<" "<<ansc+1<<endl;
    }
   	return 0;
}
