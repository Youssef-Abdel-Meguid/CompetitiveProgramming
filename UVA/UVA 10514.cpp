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

vector<point>vec[13];
double adjmatrix[13][13];
int r1,r2,n;

void initi()
{
    for(int i=0;i<13;i++)
        for(int j=0;j<13;j++)
            if(i==j)
                adjmatrix[i][j]=adjmatrix[j][i]=0;
            else
                adjmatrix[i][j]=adjmatrix[j][i]=1e9;
    for(int i=0;i<13;i++)
        vec[i].clear();
}

double min_dis(int x,int y)
{
    double ret=1e9;
    for(int i=0;i<vec[x].size();i++)
        for(int j=0;j<vec[y].size()-1;j++)
        {
            point p;
            double d=distToSegment(vec[x][i],vec[y][j],vec[y][j+1],p);
            ret=min(ret,d);
        }
    for(int i=0;i<vec[x].size()-1;i++)
        for(int j=0;j<vec[y].size();j++)
        {
            point p;
            double d=distToSegment(vec[y][j],vec[x][i],vec[x][i+1],p);
            ret=min(ret,d);
        }
    return ret;
}

void make_graph()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j)
                adjmatrix[i][j]=adjmatrix[j][i]=0;
            else
                adjmatrix[i][j]=adjmatrix[j][i]=min_dis(i,j);
}

double floyd_warshall()
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adjmatrix[i][j]=min(adjmatrix[i][j],adjmatrix[i][k]+adjmatrix[k][j]);
    return adjmatrix[0][1];        
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        initi();
        scanf("%d%d%d",&r1,&r2,&n);
        n+=2;
        for(int i=0;i<r1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            vec[0].push_back(point(x,y));
        }
        for(int i=0;i<r2;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            vec[1].push_back(point(x,y));
        }
        for(int i=2;i<n;i++)
        {
            int m;
            scanf("%d",&m);
            point p;
            bool flag=true;
            while(m--)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                vec[i].push_back(point(x,y));
                if(flag)
                {
                    p=point(x,y);
                    flag=false;
                }
            }
            vec[i].push_back(p);
        }
        make_graph();
        printf("%.3f\n",floyd_warshall());
    }
    return 0;
}
