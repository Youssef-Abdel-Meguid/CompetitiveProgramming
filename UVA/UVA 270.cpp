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

bool isCollinear(point a, point b, point c)
{
    return fabs( cp(b-a, c-a) ) < EPS;
}

vector<point>vec;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    scanf("%d\n",&cases);
    while(cases--)
    {
        vec.clear();
        string s;
        while(getline(cin,s))
        {
            if(s=="")
                break;
            stringstream ss;
            ss<<s;
            int x,y;
            ss>>x>>y;
            vec.push_back(point(x,y));
        }
        int ans=0;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=i+1;j<vec.size();j++)
            {
            	int cnt=2;
                for(int k=j+1;k<vec.size();k++)
                    if(isCollinear(vec[i],vec[j],vec[k]))
                    	cnt++;
                ans=max(ans,cnt);
            }
        }
        printf("%d\n",ans);
        if(cases)
            printf("\n");
    }
    return 0;
}
