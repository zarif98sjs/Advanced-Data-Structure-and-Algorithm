
/** Which of the favors of your Lord will you deny ? **/

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
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

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

const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

/** Inverse Mod General **/

/// ax + by = GCD(a,b)
/// r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
template <class T>
T ext_gcd ( T A, T B, T &X, T &Y )
{
    T x2, y2, x1, y1, x, y, r2, r1, q, r;
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

template <class T>
T invMod_general(T a,T m) /// when inverse of a (w.r.to mo) && mo is not prime
{
    T x, y;
    ext_gcd( a, m, x, y );

    /// Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 )
        x += m;
    return x;
}


/** nCr : O(n^2) **/

const int nmax2 = 5e3+7;
LL dp[nmax2][nmax2]; /** nCr = n-1Cr + n-1Cr-1 **/

void precalc_iter(LL lim,LL m)
{
    for(LL i=0; i<=lim; i++)
    {
        dp[i][0]=1;
        dp[i][i]=1;
        for(LL j=1; j<=i; j++)
            dp[i][j] = (dp[i-1][j]%m + dp[i-1][j-1]%m)%m;
    }
}

/** nCr : O(n) **/

const int fnmax = 1e6+7;
LL facto[fnmax];

void precalc(LL lim,LL m)
{
    facto[0] = 1;

    for(LL i=1; i<=lim; i++)
        facto[i]=((facto[i-1]%m)*(i%m))%m; /// (facto[i-1]*i)%m
}

LL nCr(LL n,LL r,LL m)
{
    LL up = facto[n];
    LL d1 = facto[n-r];
    LL d2 = facto[r];

    d1 = invMod_general(d1,m);
    d2 = invMod_general(d2,m);

    LL ans = (up * d1)%m;
    ans = (ans * d2)%m;

    return ans;
}

int main()
{
    optimizeIO();

    LL mod = 1e9+7;

    precalc_iter(5000,mod);
    cout<<dp[1000][512]<<endl;


    precalc(1e6,mod);
    cout<<nCr(1000,512,mod)<<endl;
    cout<<nCr(100000,51200,mod)<<endl;

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


