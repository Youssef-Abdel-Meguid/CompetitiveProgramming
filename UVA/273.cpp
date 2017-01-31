#include <bits/stdc++.h>

using namespace std;

const double PI  = acos(-1.0);
const double EPS = 1e-9;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)(atan2((a).imag(), (a).real()))
#define vec(a,b)((b)-(a))
#define same(p1,p2)(dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)( (conj(a)*(b)).real() )    // a*b cos(T), if zero -> prep
#define cp(a,b)( (conj(a)*(b)).imag() )    // a*b sin(T), if zero -> parllel
#define length(a)(hypot((a).imag(), (a).real()))
#define normalize(a)(a)/length(a)
#define polar(r,ang)((r)*exp(point(0,ang)))  //==> Already added in c++11
#define rotateO(p,ang)((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)(rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)(conj((v)/(m))*(m))

int dcmp(const double& a, const double& b)
{
    if (fabs(a - b) < 1e-9)
        return 0;
    return a < b ? -1 : 1;
}

point reflect(point p, point p0, point p1)
{
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}

double fixAngle(double A)
{
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}

double angleO(point a, point O, point b)
{
  point v1(a - O), v2(b - O);
  return acos( fixAngle ( dp(v1, v2) / length(v1) / length(v2) ) );
}

double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
{
    double ang = angle( vec(b, c)) - angle( vec(b, a));
    if(dcmp(ang, 0) < 0)
        ang+=2*PI;
    return ang;
}

bool isCollinear(point a, point b, point c)
{
    return fabs( cp(b-a, c-a) ) < EPS;
}

bool isPointOnRay1(point p0, point p1, point p2)
{
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}

bool isPointOnRay2(point a, point b, point c) // not tested?
{
    if(!isCollinear(a, b, c))
        return false;
    return dcmp(dp(b-a, c-a), 0) == 1;
}

bool isPointOnSegment1(point a, point b, point c)
{
    return isPointOnRay1(a, b, c) && isPointOnRay1(b, a, c);
}

bool isPointOnSegment2(point a, point b, point c)
{
    double acb = length(a-b), ac = length(a-c), cb = length(b-c);
    return dcmp(acb-(ac+cb), 0) == 0;
}

double distToLine( point p0, point p1, point p2 )
{
    return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}

double distToSegment( point p0, point p1, point p2 )
{
    double d1, d2;
    point v1 = p1-p0, v2 = p2-p0;
    if( (d1 = dp(v1, v2) ) <= 0)
        return length(p2-p0);
    if( (d2 = dp(v1, v1) ) <= d1)
        return length(p2-p1);
    double t = d1/d2;
    return length(p2 - (p0 + v1*t) );
}


bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}

int ccw(point a, point b, point c)
{
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
    return +1;
  if (t < -EPS)
    return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
    return -1;
  if (norm(v1) < norm(v2) - EPS)
    return +1;
  return 0;
}

bool intersect(point p1, point p2, point p3, point p4)
{
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)
        return p1 == p3;
    if(x)
        return ccw(p3, p4, p1) == 0;
    if(y)
        return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    cin>>cases;
    while(cases--)
    {
        point a,b;
        int n;
        cin>>n;
        bool adjmatrix[n+1][n+1];
        memset(adjmatrix,false,sizeof(adjmatrix));
        pair<point,point>pa[n+1];
        for(int i=1;i<=n;i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            point p1(x1,y1);
            point p2(x2,y2);
            pa[i].first=p1;
            pa[i].second=p2;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    adjmatrix[i][j]=adjmatrix[j][i]=1;
                else
                    adjmatrix[i][j]=adjmatrix[j][i]=(intersect(pa[i].first,pa[i].second,pa[j].first,pa[j].second));
            }
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    adjmatrix[i][j]|=(adjmatrix[i][k]&adjmatrix[k][j]);
        int x,y;
        while(cin>>x>>y&&x&&y)
        {
            if(adjmatrix[x][y])
                cout<<"CONNECTED\n";
            else
                cout<<"NOT CONNECTED\n";
        }
        if(cases)
            cout<<"\n";
    }
    return 0;
}
