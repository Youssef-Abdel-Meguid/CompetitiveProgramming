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

struct VEC
{
    double XX,YY;
    VEC(double _XX, double _YY) : XX(_XX) , YY(_YY){}
};

VEC toVEC(point a,point b)
{
    return VEC(b.X-a.X,b.Y-a.Y);
}

VEC scale(VEC v,double s)
{
    return VEC(v.XX*s,v.YY*s);
}

double DOT(VEC v1,VEC v2)
{
    return (v1.XX * v2.XX + v2.YY * v1.YY);
}

double normal_sq(VEC v)
{
    return v.XX * v.XX + v.YY * v.YY;
}

point translate(point p,VEC v)
{
    return point(p.X+v.XX,p.Y+v.YY);
}


double dis(point p1, point p2)
{
    return hypot(p1.X-p2.X, p1.Y-p2.Y);
}

int dcmp(const double& a, const double& b)
{
    if (fabs(a - b) < 1e-9)
        return 0;
    return a < b ? -1 : 1;
}

double distToLine( point p0, point p1, point p2, point &ret)
{
    VEC p1p0 = toVEC(p1,p0);
    VEC p1p2 = toVEC(p1,p2);
    double u = DOT(p1p0,p1p2) / normal_sq(p1p2);
    ret = translate(p1, scale(p1p2, u));
    return dis(p0,ret);
}

double distToSegment( point p0, point p1, point p2 ,point &ret)
{
    VEC p1p0 = toVEC(p1,p0);
    VEC p1p2 = toVEC(p1,p2);
    double u = DOT(p1p0,p1p2) / normal_sq(p1p2);
    if(u < 0.0)
    {
        ret = p1;
        return dis(p0,p1);
    }
    if(u > 1.0)
    {
        ret = p2;
        return dis(p0,p2);
    }
    return distToLine(p0,p1,p2,ret);
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    double x,y;
    while(cin>>x>>y)
    {
        point m(x,y);
        int n;
        cin>>n;
        point p[n+1];
        for(int i=0;i<n+1;i++)
        {
            cin>>x>>y;
            point tmp(x,y);
            p[i]=tmp;
        }
        double d=1e9;
        point ans,tmp,ret;
        for(int i=0;i<n;i++)
        {
            double d1=distToSegment(m,p[i],p[i+1],ret);
            if(d1<d)
            {
                d=d1;
                ans=ret;
            }
        }
        cout<<fixed<<setprecision(4)<<ans.X<<"\n"<<ans.Y<<"\n";
    }
    return 0;
}
