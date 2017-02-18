#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int x,y;
    double cost;

    bool operator < (const Node &a) const
    {
        return a.cost < cost;
    }
};

int rankk[501],parent[501],xi[501],yi[501];
int s,p,forests;

void initi(int n)
{
    forests=n;
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
        rankk[i]=1;
    }
}

int find_set(int x)
{
    if(parent[x]==x)
        return x;
    return parent[x]=find_set(parent[x]);
}

void link(int x,int y)
{
    if(rankk[x]>rankk[y])
        swap(x,y);
    parent[x]=y;
    if(rankk[x]==rankk[y])
        rankk[y]++;
}

bool union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if(x!=y)
    {
        link(x,y);
        forests--;
    }
    return x!=y;
}

bool same_set(int x,int y)
{
    return find_set(x)==find_set(y);
}

double MST()
{
    priority_queue<Node>q;
    for(int i=0;i<p;i++)
        for(int j=i+1;j<p;j++)
        {
            int x1=xi[i];
            int y1=yi[i];
            int x2=xi[j];
            int y2=yi[j];
            double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            Node tmp;
            tmp.x=i,tmp.y=j,tmp.cost=d;
            q.push(tmp);
        }
    double ret=0.0;
    int edges=0;
    while(edges!=abs(p-s))
    {
        Node cur=q.top();
        q.pop();
        if(union_set(cur.x,cur.y))
        {
            edges++;
            ret=max(ret,cur.cost);
        }
    }
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&s,&p);
        for(int i=0;i<p;i++)
            scanf("%d%d",&xi[i],&yi[i]);
        initi(p);
        printf("%0.2lf\n",MST());
    }
    return 0;
}
