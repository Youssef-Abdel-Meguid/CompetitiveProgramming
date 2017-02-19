#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int x,y,cost;

    bool operator < (const Node &a) const
    {
        return a.cost<cost;
    }
};

int rankk[510],parent[510];
int n,forests;
vector<string>vec;

void initi(int n)
{
    forests=n+1;
    for(int i=0;i<n;i++)
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

int dis(string s1,string s2)
{
    int ret=0;
    for(int i=0;i<4;i++)
    {
        int x=s1[i]-'0',y=s2[i]-'0';
        ret+=min(abs(y-x),10-abs(y-x));
    }
    return ret;
}

int MST()
{
    priority_queue<Node>q;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            int d=dis(vec[i],vec[j]);
            Node tmp;
            tmp.x=i,tmp.y=j,tmp.cost=d;
            q.push(tmp);
        }
    int ret=0;
    while(q.size())
    {
        Node cur=q.top();
        q.pop();
        if(union_set(cur.x,cur.y))
            ret+=cur.cost;
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
        vec.clear();
        scanf("%d",&n);
        int minn=1e9;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vec.push_back(s);
            minn=min(minn,dis(s,"0000"));
        }
        initi(n);
        printf("%d\n",minn+MST());
    }
    return 0;
}
