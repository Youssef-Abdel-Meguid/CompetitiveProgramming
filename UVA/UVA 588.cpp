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
#define dp(a,b)( (conj(a)*(b)).real() )
#define cp(a,b)( (conj(a)*(b)).imag() )
#define length(a)(hypot((a).imag(), (a).real()))
#define normalize(a)(a)/length(a)
#define polar(r,ang)((r)*exp(point(0,ang)))
#define rotateO(p,ang)((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)(rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)(conj((v)/(m))*(m))

bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false; 

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t2 < -EPS || t2 > 1 + EPS)
    return false;
  return true;
}


pair<vector<point>, vector<point> > polygonCut(vector<point> &p,point A, point B) {
        
  vector<point> left, right;
  point intersect;

  for (int i = 0; i < p.size(); ++i) {
    point cur = p[i], nxt = p[(i + 1) % p.size()];

    if ( cp(B-A, cur-A) >= 0)
      right.push_back(cur);

    if (intersectSegments(A, B, cur, nxt, intersect)) {  
      right.push_back(intersect);
      left.push_back(intersect);
    }

    if ( cp(B-A, cur-A) <= 0)
      left.push_back(cur);
  }
  return make_pair(left, right);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int n,c=1;
    while(cin>>n&&n)
    {
        vector<point>p;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            p.push_back(point(x,y));
        }
        vector<point>p1=p;
        for(int i=0;i<n;i++)
            p=polygonCut(p,p1[i],p1[(i+1)%n]).first;
        cout<<"Floor #"<<c++<<"\n";
        if(p.size()==0)
            cout<<"Surveillance is impossible.\n";
        else
            cout<<"Surveillance is possible.\n";
        cout<<"\n";
    }
    return 0;
}
