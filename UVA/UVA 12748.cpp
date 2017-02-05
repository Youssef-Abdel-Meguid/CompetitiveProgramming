#include <bits/stdc++.h>

using namespace std;

class Circle
{
public:
    int x,y,r;
};

class Point
{
public:
    int x,y;
};

Circle c[100];
Point p[10];
int n,y;

int dis(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool check(Circle a,Point b)
{
    int d=dis(a.x,a.y,b.x,b.y);
    return d<=a.r*a.r;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases,cc=1;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&y);
        for(int i=0;i<n;i++)
        {
            int x,y,r;
            scanf("%d%d%d",&x,&y,&r);
            c[i].x=x;
            c[i].y=y;
            c[i].r=r;
        }
        for(int i=0;i<y;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            p[i].x=x;
            p[i].y=y;
        }
        printf("Case %d:\n",cc++);
        for(int i=0;i<y;i++)
        {
            bool found=false;
             for(int j=0;j<n&&!found;j++)
                found=check(c[j],p[i]);
            if(found)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
