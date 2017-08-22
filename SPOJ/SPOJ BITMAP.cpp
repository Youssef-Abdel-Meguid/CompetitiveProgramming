#include<bits/stdc++.h>

using namespace std;

struct node
{
    int x,y,d;
};

int n,m,a[182][182],ans[182][182];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs()
{
    queue<node>q;
    node cur;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j])
            {
                cur.x=i;
                cur.y=j;
                cur.d=0;
                q.push(cur);
            }
    while(q.size())
    {
        node cur=q.front();
        q.pop();
        if(ans[cur.x][cur.y]!=-1)
            continue;
        ans[cur.x][cur.y]=cur.d;
        for(int i=0;i<4;i++)
        {
            node tmp;
            tmp.x=cur.x+dx[i];
            tmp.y=cur.y+dy[i];
            tmp.d=cur.d+1;
            if(tmp.x<0||tmp.x>=n||tmp.y<0||tmp.y>=m)
                continue;
            q.push(tmp);
        }
    }
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int num;
                scanf("%1d",&num);
                a[i][j]=num;
            }
        memset(ans,-1,sizeof(ans));
        bfs();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
