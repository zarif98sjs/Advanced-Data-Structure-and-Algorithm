
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX
#define PI 2*acos(0)

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

const int nmax = 1e7+7;
const LL LINF = 1e17;


// ax + by = GCD(a,b)
// r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
int ext_gcd ( int A, int B, int &X, int &Y )
{
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2;
    Y = y2;
    return r2;
}

bool linearDiophantine ( int A, int B, int C, int &x, int &y ) {
    int g = __gcd ( A, B );
    if ( C % g != 0 ) return false; //No Solution

    int a = A / g, b = B / g, c = C / g;
    ext_gcd( a, b, x, y ); //Solve ax + by = 1

    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
        a *= -1; b *= -1; c *= -1;
    }

    x *= c; y *= c; //ax + by = c
    return true; //Solution Exists
}

int main () {
    int x, y, A = 2, B = 3, C = 5;

    // Ax + By = C
    bool res = linearDiophantine ( A, B, C, x, y );

    if ( res == false ) printf ( "No Solution\n" );
    else {
        printf ( "One Possible Solution (%d %d)\n", x, y );

        int g = __gcd ( A, B );

        int k = 1; //Use different value of k to get different solutions
        printf ( "Another Possible Solution (%d %d)\n", x + k * ( B / g ), y - k * ( A / g ) );
    }

 return 0;
}


