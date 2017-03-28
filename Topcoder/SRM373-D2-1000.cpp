/*
easy problem ... don't use complex number ,, to avoid problems ,,, just use integer ,,, cuz every thing is integer 
,,, including the answer.
*/

#include <bits/stdc++.h>

using namespace std;

class point
{
public:
    int X, Y;
};

class P
{
public:
    point p1, p2;
};

int ccw(point a, point b, point c)
{
    int x1 = b.X - a.X, y1 = b.Y - a.Y, x2 = c.X - a.X, y2 = c.Y - a.Y;
    if(y1 * x2 > x1 * y2)
        return -1;
    if(y1 * x2 < x1 * y2)
        return 1;
    if(x1 * x2 < 0 || y1 * y2 < 0)
        return 1;
    if(x1 * x1 + y1 * y1 > x2 * x2 + y2 * y2)
        return -1;
  return 0;
}

bool intersect(point p1,point p2,point p3,point p4)
{
  return ccw(p1,p3,p2) * ccw(p1,p4,p2) <=0 &&
         ccw(p3,p1,p4) * ccw(p3,p2,p4) <=0;
}

bool inside_rec(const P& pp, const point& p)
{
  return pp.p1.X < p.X && pp.p2.X > p.X && pp.p1.Y < p.Y && pp.p2.Y > p.Y;
}

int area(const P& p)
{
   return abs(p.p2.Y - p.p1.Y) * abs(p.p2.X - p.p1.X);
}

class RectangleCrossings
{
public:
    vector <int> countAreas(vector <string> rectangles, vector <string> segments)
    {
        vector<int>ans(2, 0);
        vector<P>line_segment;
        for(int i = 0; i < segments.size(); i++)
        {
            P p;
            sscanf(segments[i].c_str(), "%d%d%d%d", &p.p1.X, &p.p1.Y, &p.p2.X, &p.p2.Y);
            line_segment.push_back(p);
        }

        for(int i = 0; i < rectangles.size(); i++)
        {
            P p, p1, p2, p3, p4;
            sscanf(rectangles[i].c_str(), "%d%d%d%d", &p.p1.X, &p.p1.Y, &p.p2.X, &p.p2.Y);

            ///first point
            p1.p1 = p.p1;
            p1.p2 = p.p1; p1.p2.Y = p.p2.Y;
            ///second point
            p2.p1 = p.p1;
            p2.p2 = p.p1; p2.p2.X = p.p2.X;
            ///third point
            p3.p1 = p.p2;
            p3.p2 = p.p2; p3.p2.Y = p.p1.Y;
            ///fourth point
            p4.p1 = p.p2;
            p4.p2 = p.p2; p4.p2.X = p.p1.X;

            bool flag1 = false, flag2 = false;
            for(int j = 0; j < line_segment.size(); j++)
            {
                if(inside_rec(p, line_segment[j].p1) || inside_rec(p, line_segment[j].p2))
                {
                    flag1 = true;
                    break;
                }
                else if(!flag2)
                {
                    flag2 =  intersect(p1.p1, p1.p2, line_segment[j].p1, line_segment[j].p2)
                          || intersect(p2.p1, p2.p2, line_segment[j].p1, line_segment[j].p2)
                          || intersect(p3.p1, p3.p2, line_segment[j].p1, line_segment[j].p2)
                          || intersect(p4.p1, p4.p2, line_segment[j].p1, line_segment[j].p2);
                }
            }
            if(flag1)
                ans[0] += area(p);
            else if(flag2)
                ans[1] += area(p);
        }
        return ans;
    }
};
