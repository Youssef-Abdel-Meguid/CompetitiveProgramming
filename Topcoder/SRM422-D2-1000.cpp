#include<bits/stdc++.h>

using namespace std;

class BirthdayCake
{
public:
    int howManyFriends(vector <string> a, vector <string> b, int k)
    {
        int n=a.size(),m=b.size(),ans=0;
        map<string,int>ma;
        vector<int>vec[20];
        bool visi[50];
        for(int i=0;i<n;i++)
            ma[a[i]]=i;
        for(int i=0;i<m;i++)
        {
            string s=b[i],s1;
            stringstream ss(s);
            while(ss>>s1)
                if(ma.count(s1))
                    vec[i].push_back(ma[s1]);
                else
                    vec[i].push_back(-1);
        }
        for(int i=0;i<(1<<m);i++)
        {
            memset(visi,false,sizeof(visi));
            int c=0;
            for(int j=0;j<m;j++)
                if((1<<j)&i)
                    for(int k=0;k<vec[j].size();k++)
                        if(vec[j][k]!=-1)
                            if(!visi[vec[j][k]])
                            {
                                c++;
                                visi[vec[j][k]]=true;
                            }
            int x=n-c;
            if(x>=k)
                ans=max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};
