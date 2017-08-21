#include<bits/stdc++.h>

using namespace std;

class NetworkXMessageRecovery
{
    vector<int>cnt;
    vector<vector<int>>vec;
    set<char>se;

    string solve()
    {
        string ans="";
        set<char>q;

        while(se.size())
        {
            char c=*se.begin();
            se.erase(se.begin());
            if(!cnt[c])
                q.insert(c);
        }

        while(q.size())
        {
            char c=*q.begin();
            q.erase(q.begin());
            ans+=c;
            for(int i=0;i<vec[c].size();i++)
            {
                cnt[vec[c][i]]--;
                if(!cnt[vec[c][i]])
                    q.insert(vec[c][i]);
            }
        }
        return ans;
    }

public:
    string recover(vector <string> messages)
    {
        vec.resize(200);
        cnt.resize(200);

        for(int i=0;i<messages.size();i++)
            for(int j=0;j+1<messages[i].size();j++)
                vec[messages[i][j]].push_back(messages[i][j+1]);

        for(int i=0;i<vec.size();i++)
            for(int j=0;j<vec[i].size();j++)
                cnt[vec[i][j]]++;

        for(int i=0;i<messages.size();i++)
            for(int j=0;j<messages[i].size();j++)
                se.insert(messages[i][j]);

        return solve();
    }
};
