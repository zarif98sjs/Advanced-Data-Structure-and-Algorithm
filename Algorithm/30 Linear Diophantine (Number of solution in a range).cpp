
/**

Problem : Given ax+by+c = 0,
find the number of solution in the range [x1,x2] and [y1,y2]

**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;



/*

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

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

LL gcd( LL a, LL b )
{
    while ( b )
    {
        a = a % b;
        swap ( a, b );
    }
    return a;
}

LL po(LL x,LL n) /// x^n
{
    LL res = 1;

    while(n>0)
    {
        if(n&1)
            res = res*x;

        x = x*x;
        n >>= 1;
    }

    return res;
}

LL bigMod(LL x,LL n,LL mo) /// x^n % mo
{
    x %= mo;

    LL res = 1;

    while(n>0)
    {
        if(n&1)
            res = ((res%mo)*(x%mo)) % mo;

        x = ((x%mo)*(x%mo)) %mo;
        n >>= 1;
    }

    return res;

}

/**
ax + by = GCD(a,b)
r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
**/
LL ext_gcd ( LL A, LL B, LL &X, LL &Y )
{
    LL x2, y2, x1, y1, x, y, r2, r1, q, r;
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

/**
when inverse of a (w.r.to mo) && mo is not prime
**/
LL modInv_general ( LL a, LL m )
{
    LL x, y;
    ext_gcd( a, m, x, y );

    // Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 )
        x += m;
    return x;
}

/*--------------------------Template Ends---------------------------------*/

const int nmax = 2e5+7;
const LL LINF = 1e17;

/**

Find any solution of eqn : ax+by = c

**/

bool find_any_solution(LL a, LL b, LL c, LL &x0, LL &y0, LL &g)
{
    g = ext_gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}

void shift_solution(LL & x, LL & y, LL a, LL b, LL cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

/**

Find number of solutions of eqn : ax+by = c

in range [minx,maxx] and [miny,maxy]

**/

LL find_all_solutions(LL a, LL b, LL c, LL minx, LL maxx, LL miny, LL maxy)
{
    LL x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    LL sign_a = a > 0 ? +1 : -1;
    LL sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    LL lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    LL rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    LL lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    LL rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    LL lx = max(lx1, lx2);
    LL rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main()
{
    //optimizeIO();

    freopen("LOJ 1306.txt","w",stdout);

    int tc;
    //cin>>tc;
    scanf("%d",&tc);

    for(int w=1; w<=tc; w++)
    {
        LL a,b,c,x1,x2,y1,y2,ans = 0;
        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&x1,&x2,&y1,&y2);

        c *= -1; /// converting to ax + by = *C*

        if(a==0 && b==0)
        {
            if(c==0)
                ans = (x2 - x1 + 1)*(y2 - y1 + 1);
            else
                ans = 0;
        }
        else if(a==0)
        {
            if(c%b)
                ans = 0;
            else
            {
                LL y = c/b;

                if(y>=y1 && y<=y2)
                    ans = x2 - x1 + 1;
                else
                    ans = 0;
            }
        }
        else if(b==0)
        {
            if(c%a)
                ans = 0;
            else
            {
                LL x = c/a;

                if(x>=x1 && x<=x2)
                    ans = y2 - y1 + 1;
                else
                    ans  = 0;
            }
        }
        else
        {
            ans = find_all_solutions(a,b,c,x1,x2,y1,y2);
        }

        printf("Case %d: %lld\n",w,ans);
    }

    return 0;
}
