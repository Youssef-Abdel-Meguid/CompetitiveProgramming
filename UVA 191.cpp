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

bool isPointOnRay1(point p0, point p1, point p2)
{
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}

bool isPointOnSegment1(point a, point b, point c)
{
    return isPointOnRay1(a, b, c) && isPointOnRay1(b, a, c);
}

bool intersectSegments(point a, point b, point p, point q, point & intersect)
{
	double d1=cp(p-a,b-a);
	double d2=cp(q-a,b-a);
	intersect=(d1*q-d2*p)/(d1-d2);
	if(isPointOnSegment1(a,b,p)||isPointOnSegment1(a,b,q)||isPointOnSegment1(p,q,a)||isPointOnSegment1(p,q,b))
		return true;
	return fabs(d1-d2)>EPS && isPointOnSegment1(a,b,intersect) && isPointOnSegment1(p,q,intersect);
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
    	int xstart,ystart,xend,yend,xleft,ytop,xright,ybottom;
    	scanf("%d%d%d%d%d%d%d%d",&xstart,&ystart,&xend,&yend,&xleft,&ytop,&xright,&ybottom);
    	if(ybottom>ytop)
    		swap(ytop,ybottom);
    	if(xleft>xright)
    		swap(xright,xleft);
    	point line_start(xstart,ystart),line_end(xend,yend);
    	point top_left(xleft,ytop),top_right(xright,ytop);
    	point bottom_left(xleft,ybottom),bottom_right(xright,ybottom);
    	bool found=false;
    	point inter;
    	found|=intersectSegments(top_left,top_right,line_start,line_end,inter);
    	found|=intersectSegments(top_right,bottom_right,line_start,line_end,inter);
    	found|=intersectSegments(bottom_right,bottom_left,line_start,line_end,inter);
    	found|=intersectSegments(top_left,bottom_left,line_start,line_end,inter);
    	if(line_start.X>bottom_left.X&&line_start.X<top_right.X&&line_start.Y>bottom_left.Y&&line_start.Y<top_left.Y)
    		found=true;
    	if(found)
    		printf("T\n");
    	else
    		printf("F\n");
    }
    return 0;
}
