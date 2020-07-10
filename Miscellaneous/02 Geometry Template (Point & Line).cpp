
/**

STRUCTURE
---------
1. PT
2. LINE

FUNCTION OVERVIEW
-----------------

double dot(PT p, PT q)
double cross(PT p, PT q)
double dist2(PT p, PT q)

PT RotateCCW90(PT p)
PT RotateCW90(PT p)
PT RotateCCW(PT p, double t)

PT LineIntersectionUsingPoint(PT a, PT b, PT c, PT d)
PT LineIntersectionUsingLine(LINE l1, LINE l2)

PT Middle(PT p, PT q)

LINE points_to_line(PT p, PT q)
LINE perpendicular(LINE l, PT p)

PT ComputeCircleCenter(PT a, PT b, PT c)

bool LinesParallel(PT a, PT b, PT c, PT d)
bool LinesCollinear(PT a, PT b, PT c, PT d)

PT ProjectPointLine(PT a, PT b, PT c)
PT ProjectPointSegment(PT a, PT b, PT c)
double DistancePointSegment(PT a, PT b, PT c)
double DistancePointLine(PT a, PT b, PT c)

double HeronTriangleArea(double a,double b,double c)
double PassPointThroughLine(PT a,LINE l)

**/


/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define DBL long long
//#define DBL double

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

double INF = 1e100;
double EPS = 1e-12;

const double eps = 1e-11;
int cmp(double x, double y)
{
    return (x <= y + eps) ? (x + eps < y) ? -1 : 0 : 1; /// 0 -> x equal y , 1 -> x>y , -1 -> x<y
}

struct PT
{
    double x,y;
    PT() {}
    PT(double x,double y) : x(x), y(y) {}
    PT(const PT &p) :   x(p.x), y(p.y) {}

    bool operator==(const PT &p)
    {
        return (cmp(x,p.x) == 0 && cmp(y,p.y) == 0);
    }

    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)    const
    {
        return PT(x*c, y*c  );
    }
    PT operator / (double c)    const
    {
        return PT(x/c, y/c  );
    }
};

struct LINE
{
    double a,b,c;
};

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

double dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}

/// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

PT LineIntersectionUsingPoint(PT a, PT b, PT c, PT d)
{
    b=b-a;
    d=c-d;
    c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

PT LineIntersectionUsingLine(LINE l1, LINE l2)
{
    PT p;

    p.y = (l2.c * l1.a - l1.c * l2.a) / (l1.b * l2.a - l2.b * l1.a);
    p.x = (l2.c * l1.b - l1.c * l2.b) / (l1.a * l2.b - l2.a * l1.b);

    return p;
}

PT Middle(PT p, PT q)
{
    PT m = { (p.x + q.x) / 2, (p.y + q.y) / 2 };

    return m;
}

LINE points_to_line(PT p, PT q)
{
    LINE l;

    l.a = p.y - q.y;
    l.b = q.x - p.x;
    l.c = -l.a * p.x - l.b * p.y;

    return l;
}

LINE perpendicular(LINE l, PT p)
{
    LINE per;

    per.a = -l.b;
    per.b = l.a;
    per.c = -per.a * p.x - per.b * p.y;

    return per;
}

PT ComputeCircleCenter(PT a, PT b, PT c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    return LineIntersectionUsingPoint(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}


bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d)
           && fabs(cross(a-b, a-c)) < EPS
           && fabs(cross(c-d, c-a)) < EPS;
}

/// project point c onto line through a and b
/// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c)
{
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

/// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS)
        return a;
    r = dot(c-a, b-a)/r;
    if (r < 0)
        return a;
    if (r > 1)
        return b;
    return a + (b-a)*r;
}

/// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c)
{
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

/// compute distance from c to line between a and b
double DistancePointLine(PT a, PT b, PT c)
{
    return sqrt(dist2(c, ProjectPointLine(a, b, c)));
}

double HeronTriangleArea(double a,double b,double c)
{
    double s=(a+b+c)*0.5;
    double area=sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

double PassPointThroughLine(PT a,LINE l)
{
    return (l.a*a.x+l.b*a.y+l.c);
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {

    }

    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}

