#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    vector<pair<int,int>>vecp;
    vecp.push_back(make_pair(0,a[0]));
    for(int i=0;i<n;i++)
        if(vecp.back().second==a[i])
            vecp.back().first++;
        else
            vecp.push_back(make_pair(1,a[i]));
    priority_queue<pair<int,int>>pqp;
    for(int i=0;i<vecp.size();i++)
        pqp.push(vecp[i]);
    vector<vector<int>>ans;
    pair<int,int>x,y,z;
    while(pqp.size()>=3)
        {
            x=pqp.top();
            pqp.pop();
            y=pqp.top();
            pqp.pop();
            z=pqp.top();
            pqp.pop();
            vector<int>vec;
            vec.push_back(x.second);
            vec.push_back(y.second);
            vec.push_back(z.second);
            ans.push_back(vec);
            if(--x.first)
                pqp.push(x);
            if(--y.first)
                pqp.push(y);
            if(--z.first)
                pqp.push(z);
        }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        {
            sort(ans[i].begin(),ans[i].end());
            reverse(ans[i].begin(),ans[i].end());
            cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
        }
    return 0;
}
