#include<bits/stdc++.h>

using namespace std;

string to_binary(int x)
{
    string ret="";
    while(x)
    {
        if(x&1)
            ret+='1';
        else
            ret+='0';
        x>>=1;
    }
    return ret;
}

class TheMoviesLevelThreeDivTwo
{
public:
    int find(vector <int> timeJ, vector <int> timeB)
    {
        int n=timeB.size(),ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            int j=0,b=0;
            bool flag1=true,flag2=true;
            string s=to_binary(i);
            while(s.size()<n)
                s+='0';
            ///---------------------///
            for(int k=0;k<n;k++)
                if(s[k]=='1')
                    j+=timeJ[k];
            for(int k=0;k<n;k++)
                if(s[k]=='0')
                {
                    b+=timeB[k];
                    if(b>j)
                        flag1=false;
                    j+=timeJ[k];
                }
            ///---------------------///
            for(int k=0;k<n;k++)
                if(s[k]=='1')
                    s[k]='0';
                else
                    s[k]='1';
            j=b=0;
            ///---------------------///
            for(int k=0;k<n;k++)
                if(s[k]=='1')
                    b+=timeB[k];
            for(int k=0;k<n;k++)
                if(s[k]=='0')
                {
                    j+=timeJ[k];
                    if(j>b)
                        flag2=false;
                    b+=timeB[k];
                }
            ///---------------------///
            if(flag1&&flag2)
                ans++;
        }
        return ans;
    }
};
