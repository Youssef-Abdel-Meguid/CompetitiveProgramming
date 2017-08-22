#include <bits/stdc++.h>

using namespace std;

int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    #endif*/
    string s;
    while(cin>>s)
    {
        vector<int>vec1,vec2;
        for(int i=0;i<s.size();i++)
            if(s[i]=='r')
                vec1.push_back(i+1);
            else
                vec2.push_back(i+1);
        for(int i=0;i<vec1.size();i++)
            cout<<vec1[i]<<"\n";
        for(int i=vec2.size()-1;i>=0;i--)
            cout<<vec2[i]<<"\n";
    }
   	return 0;
}
