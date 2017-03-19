/*
idea explanition: http://www.algorithmist.com/index.php/UVa_10161 (i wrote the code in my way :D )
another idea: https://saicheems.wordpress.com/2013/11/29/uva-10161-ant-on-a-chessboard/
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(scanf("%d",&n)&&n)
    {
        int a=ceil(sqrt(n));
        int b=a*a;
        int x,y;
        if(b%2)
        {
            if(b-n<a)
            {
                x=b-n+1;
                y=a;
            }
            else
            {
                x=a;
                y=n-(a-1)*(a-1);
            }
        }
        else
        {
            if(b-n<a)
            {
                x=a;
                y=b-n+1;
            }
            else
            {
                y=a;
                x=n-(a-1)*(a-1);
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
