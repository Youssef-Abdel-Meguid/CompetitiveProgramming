#include <bits/stdc++.h>

using namespace std;

char a[100005];

bool cmp(string a,string b)
{
	if(a.size()!=b.size())
		return a.size()>b.size();
	return a>=b;
}

int main()
{
    while(scanf("%s",&a)!=EOF)
    {
        vector<string>vec;
        string tmp="";
        int n=strlen(a);
        for(int i=n-1;i>=0;i--)
        {
            tmp=a[i]+tmp;
            if(a[i]=='0')
                continue;
            vec.push_back(tmp);
            tmp="";
        }
        int ans=1;
        tmp=vec[vec.size()-1];
        for(int i=vec.size()-2;i>=0;i--)
        {
            if(cmp(tmp,vec[i]))
                ans++;
            else
                ans=1;
            tmp+=vec[i];
        }
        printf("%d\n",ans);
    }
   	return 0;
}
