#include <bits/stdc++.h>

using namespace std;

class JarBox
{
public:
	int numJars(int radius, int woodlength)
	{
		int ans=1	;
		for(int i=3;i<=(woodlength-4)/2;i++)
		{
			double h=((double)woodlength-(double)i*(double)radius*2.0)/2.0;
			int j=0;
			while((double)radius*(2.0+(double)j*(double)sqrt(3))<=h)
				j++;
			int x=j*(i/2);
			if(i%2==0)
				x-=(j/2);
			ans=max(ans,x);
		}
		return ans;
	}
};
