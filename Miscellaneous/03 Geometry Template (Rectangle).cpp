
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

struct PT
{
    DBL x,y;
    PT() {}
    PT(DBL x,DBL y) : x(x), y(y) {}
    PT(const PT &p) :   x(p.x), y(p.y) {}

    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (DBL c)    const
    {
        return PT(x*c, y*c  );
    }
    PT operator / (DBL c)    const
    {
        return PT(x/c, y/c  );
    }
};

/**

Rectangles are defined by two points.
One is the LOWER_LEFT and the other one is the UPPER_RIGHT

**/

/**
Intersecting Points of 2 Rectangle
returns false if No Intersection
**/
bool intersectingPoints(PT a,PT b,PT c,PT d,PT &na,PT &nb)
{
    na.x = max(a.x,c.x);
    na.y = max(a.y,c.y);

    nb.x = min(b.x,d.x);
    nb.y = min(b.y,d.y);

    if(na.x>nb.x || na.y>nb.y)
        return false;

    return true;
}


///Calculates Area of a Rectangle
LL computeArea(PT a,PT b)
{
    return (b.x-a.x) * (b.y-a.y);
}


///Calculate the overlapping area of two rectangles.
LL overlapArea(PT a,PT b,PT c,PT d)
{
    /** Check if there is indeed an overlap.
     * e.g.  c.x>=b.x  i.e. the most left point of the rectangle (c,d) is
     *       on the right side of the most right point of the rectangle (a,b),
     *       therefore there is no overlapping.
     */
    if ( (c.x>=b.x) || (c.y>= b.y) || (a.x>=d.x) || (a.y >= d.y) )
        return 0;

    /** bottom left polong long of the overlapping area. */
    LL bl_x = max(a.x, c.x);
    LL bl_y = max(a.y, c.y);

    /** top right polong long of the overlapping area. */
    LL tr_x = min(b.x, d.x);
    LL tr_y = min(b.y, d.y);

    return ((tr_x - bl_x) * (tr_y - bl_y));
}

/**
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner.
**/
LL computeTotalArea(PT a,PT b,PT c,PT d)
{
    /// The addition of area of the two rectangles minus the overlapping area.
    return (computeArea(a,b) + computeArea(c,d) - overlapArea(a,b,c,d));
}

int main()
{
    PT a1(2,2) , b1(4,4) , a2(1,1) , b2(3,5) , a3(3,1) , b3(5,5);

    PT c1,d1,c2,d2;

    intersectingPoints(a1,b1,a2,b2,c1,d1);
    intersectingPoints(a1,b1,a3,b3,c2,d2);

    cout<<c1.x<<" "<<c1.y<<"  ,  "<<d1.x<<" "<<d1.y<<endl;
    cout<<c2.x<<" "<<c2.y<<"  ,  "<<d2.x<<" "<<d2.y<<endl;

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

