/*
https://drive.google.com/file/d/0B_rSt5dGmwYBVER5bmp1QjF4V0k/view

You must convert the given input from decimal degree to raduis degree
*/

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double Radius = 6378.0;
const double p = acos(-1.0);


double sphericalDist(double p_lat, double p_long, double q_lat, double q_long)
{
    p_lat *= p / 180.0, p_long *= p / 180.0; /* convert from decimal degree to raduis degree*/
    q_lat *= p / 180.0, q_long *= p / 180.0;
    return acos( sin(p_lat)*sin(q_lat) +
                 cos(p_lat)*cos(q_lat) * cos(p_long - q_long) ) * Radius;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n;
    while(scanf("%d", &n) != EOF)
    {
        double x[n], y[n];
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf", &x[i], &y[i]);
        double mn = 1e18;
        int index;
        for (int i = 0; i < n; ++i)
        {
            double mx = 0;
            for (int j = 0; j < n; ++j)
            {
                if(i == j)
                    continue;
                mx = max(mx, sphericalDist(x[i], y[i], x[j], y[j]));
            }
            if(mn >= mx - 1e-9)
            {
                mn = mx;
                index = i;
            }
        }
        printf("%.2lf %.2lf\n", x[index], y[index]);
    }
    return 0;
}
