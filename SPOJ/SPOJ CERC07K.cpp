#include<bits/stdc++.h>

using namespace std;

class Cell
{
public:
    int i,j,key;
};

int n,m,dist[100][100][16];
char a[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool isvalid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<m);
}

int bfs(int i,int j)
{
    queue<Cell>q;
    Cell cur;
    cur.i=i,cur.j=j,cur.key=0;
    dist[i][j][0]=0;
    q.push(cur);
    while(q.size())
    {
        cur=q.front();
        q.pop();
        if(a[cur.i][cur.j]=='X')
            return dist[cur.i][cur.j][cur.key];
        for(int k=0;k<4;k++)
        {
            int x=dx[k]+cur.i;
            int y=dy[k]+cur.j;
            if(isvalid(x,y)&&a[x][y]!='#')
            {
                int key=cur.key;
                if(a[x][y]=='r')
                    key|=1;
                else if(a[x][y]=='g')
                    key|=2;
                else if(a[x][y]=='y')
                    key|=4;
                else if(a[x][y]=='b')
                    key|=8;
                 if(dist[x][y][key]!=-1)
                    continue;
                if(a[x][y]=='R'&&!(key&1))
                    continue;
                else if(a[x][y]=='G'&&!(key&2))
                    continue;
                else if(a[x][y]=='Y'&&!(key&4))
                    continue;
                else if(a[x][y]=='B'&&!(key&8))
                    continue;
                dist[x][y][key]=dist[cur.i][cur.j][cur.key]+1;
                Cell tmp;
                tmp.i=x;
                tmp.j=y;
                tmp.key=key;
                q.push(tmp);
            }
        }
    }
    return -1;
}

int main()
{
    while(cin>>n>>m&&n&&m)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        memset(dist,-1,sizeof(dist));
        int x,y;
        bool flag=false;
        for(int i=0;i<n&&!flag;i++)
            for(int j=0;j<m&&!flag;j++)
                if(a[i][j]=='*')
                {
                    x=i;
                    y=j;
                    flag=true;
                }
        int ans=bfs(x,y);
        if(ans==-1)
            cout<<"The poor student is trapped!"<<endl;
        else
            cout<<"Escape possible in "<<ans<<" steps."<<endl;
    }
    return 0;
}
