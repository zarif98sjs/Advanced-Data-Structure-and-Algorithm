
/**

Binary Search (Eqn Solve)
=========================

Demo Problem : LightOj 1043 ( Triangle Partitioning )
------------------------------------------------------

        A
        /\
       /  \
     D/----\E
     /      \
    /        \
   B----------C

You are given AB, AC and BC. DE is parallel to BC.
You are also given the area ratio between ADE and BDEC. You have to find the value of AD.

Idea
----

AB/AD = AC/AE = BC/DE

So  , AE = (AC*AD)/AB
and , DE = (BC*AD)/AB

The area ratio of those two triangles can be calculated as a function of AD .
So, we can Binary Search over AD

**/

/** Which of the favors of your Lord will you deny ?* */

#include<bits/stdc++.h>
using namespace std;

double triangleRatio (double ab,double ac,double bc,double ad)
{
    double ae=(ac*ad)/ab, de=(bc*ad)/ab,s1,s2;

    s1 = (ab+ac+bc)/2.0;
    s2 = (ad+ae+de)/2.0;

    double areaBig = sqrt(s1 * (s1-ab) * (s1-ac) * (s1-bc));
    double areaSmall = sqrt(s2 * (s2-ad) * (s2-ae) * (s2-de));

    double areaTrap = areaBig-areaSmall;

    double ratio = areaSmall/areaTrap;

    return ratio;

}

double EPS = 0.00000001;

double BS(double lo,double hi ,double ab,double ac,double bc,double target)
{
    double mid;

    do
    {
        mid = (hi + lo) / 2.0;

        double value = triangleRatio(ab,ac,bc,mid);

        if (value>target) hi = mid;
        else lo = mid;
    }
    while ((hi - lo) > EPS);

    return mid;
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        double ab,ac,bc,ratio;
        scanf("%lf %lf %lf %lf",&ab,&bc,&ac,&ratio);

        printf("Case %d: %lf\n",i,BS(0,ab,ab,bc,ac,ratio));

    }

    return 0;
}
