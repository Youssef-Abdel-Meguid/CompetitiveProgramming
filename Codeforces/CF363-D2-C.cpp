#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    string s;
    while(cin>>s)
    {
    	memset(cnt,0,sizeof(cnt));
    	string ans="";
    	char tmp=s[0];
    	ans+=s[0];
    	cnt[tmp-'a']++;
    	for(int i=1;i<s.size();i++)
    		if(s[i]==tmp)
    		{
    			if(cnt[tmp-'a']<2)
    			{
    				ans+=s[i];
    				cnt[tmp-'a']++;
    			}
    		}
    		else
    		{
    			cnt[tmp-'a']=0;
    			tmp=s[i];
    			cnt[tmp-'a']++;
    			ans+=s[i];
    		}
    	tmp=ans[0];
    	int c=1;
    	for(int i=1;i<ans.size();i++)
    	{
    		if(ans[i]==tmp)
    			c++;
    		else
    		{
    			if(c==2)
    			{
    				if(ans[i]==ans[i+1])
    					ans[i]='_';
    			}
    			c=1;
    			tmp=ans[i];
    		}
    	}
    	for(int i=0;i<ans.size();i++)
    		if(ans[i]!='_')
    			cout<<ans[i];
    	cout<<endl;
    }
   	return 0;
}
