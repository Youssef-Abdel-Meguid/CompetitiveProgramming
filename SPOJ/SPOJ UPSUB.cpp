#include<bits/stdc++.h>

using namespace std;

set<string>ans;
int dp[101][101];
string s;

int solve(int i,int j)
{
    if(j>=s.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret=0;
    if(s[i]<=s[j])
        ret=max(ret,max(1+solve(j,j+1),solve(i,j+1)));
    else
        ret=solve(i,j+1);
    return dp[i][j]=ret;
}


void print(int i,int j,string a)
{

    if(j>=s.size())
        {
            ans.insert(a);
            return;
        }
    if(s[i]<=s[j])
        {
            if(solve(j,j+1)+1>=solve(i,j+1))
                print(j,j+1,a+s[j]);
            if(solve(j,j+1)+1<=solve(i,j+1))
                print(i,j+1,a);

        }
    else
        print(i,j+1,a);
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
        {
            cin>>s;
            s='\0'+s;
            memset(dp,-1,sizeof(dp));
            int x=solve(0,1);
            ans.clear();
            print(0,1,"");
            set<string>::iterator it;
            for(it=ans.begin();it!=ans.end();it++)
                cout<<*it<<endl;
        }
    return 0;
}
