#include <bits/stdc++.h>

using namespace std;

int n,k,nodes[100001];
pair<int,int>pa[100001];
vector<pair<int,int> >ans;

void solve()
{
    queue<pair<int,int> >q;
    q.push(pa[0]);
    for(int i=1;i<n;i++)
    {
        pair<int,int>p;
        while(q.size())
        {
            p=q.front();
            if(nodes[p.second]<k&&pa[i].first-p.first==1)
                break;
            q.pop();
        }
        if(q.empty())
            return;
        ans.push_back(make_pair(p.second,pa[i].second));
        nodes[p.second]++;
        nodes[pa[i].second]++;
        q.push(pa[i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        pa[i].first=x;
        pa[i].second=i+1;
    }
   sort(pa,pa+n);
   if(pa[0].first!=0)
   {
        printf("-1\n");
        return 0;
   }
   solve();
   if(ans.size()!=n-1)
        printf("-1\n");
    else
    {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
