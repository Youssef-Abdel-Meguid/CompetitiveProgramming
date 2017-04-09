/*
  idea -? http://www.cnblogs.com/dwtfukgv/p/5612799.html
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l, d, n, x, y;
    while(scanf("%d%d%d", &l, &d, &n) != EOF)
    {
        vector< pair<double, double> > points;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            double dis = sqrt(d * d - y * y);
            points.push_back( make_pair( min(x + dis, (double)l) , max(x - dis, 0.0) ) );
        }
        sort(points.begin(), points.end());
        int ans = 0;
        double pre = -1;
        for(int i = 0; i < n; i++)
            if(pre < points[i].second)
            {
                ans++;
                pre = points[i].first;
            }
        printf("%d\n", ans);
    }
    return 0;
}
