#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int x,y,cost;
};

int x1,y1,x2,y2;
map<int,set<int>>ma;
map<pair<int,int>,bool>visi;
int dx[8]={1,-1,0,0,1,-1,-1,1};
int dy[8]={0,0,1,-1,1,-1,1,-1};

int bfs()
{
    queue<Node>q;
    Node cur;
    cur.x=x1,cur.y=y1,cur.cost=0;
    q.push(cur);
    while(q.size())
    {
        cur=q.front();
        q.pop();
        if(cur.x==x2&&cur.y==y2)
            return cur.cost;
        for(int i=0;i<8;i++)
        {
            Node tmp;
            tmp.x=cur.x+dx[i];
            tmp.y=cur.y+dy[i];
            tmp.cost=cur.cost+1;
            if(!visi[make_pair(tmp.x,tmp.y)]&&ma[tmp.x].find(tmp.y)!=ma[tmp.x].end())
            {
                q.push(tmp);
                visi[make_pair(tmp.x,tmp.y)]=true;
            }
        }
    }
    return -1;
}

int main()
{
    cin>>x1>>y1>>x2>>y2;
    int n,a,b,r;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++)
            ma[r].insert(j);
    }
    cout<<bfs()<<endl;
}
