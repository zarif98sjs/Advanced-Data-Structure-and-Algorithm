
/**

Problem : 0-1 Knapsack
In 0-1 Knapsack problem, we are given a set of items, each with a weight and a value and
we need to determine the number of each item to include in a collection so that
the total weight is less than or equal to a given limit and the total value is as large as possible.

====================================================================================================

F(i,W) = max( include ith item , exclude ith item )

Here ,
include ith item = F(i+1,W+w[i]) + v[i]
exclude ith item = F(i+1,W)

Base case:

F(i,W>MAX_WEIGHT)     = INT_MIN
F(i>n,W<=MAX_WIGHT)   = 0
F(i>n,W>MAX_WIGHT)    = INT_MIN

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

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

const int nmax = 1e2+7;
const int nmax2 = 1e5+7;
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int n,MAX_WEIGHT;

LL w[nmax];
LL v[nmax];
LL dp[nmax][nmax2];

LL solve(int pos,int W) /** maximum value to get using maximum weight W **/
{
    if(W>MAX_WEIGHT) return INT_MIN; /** if anytime W>MAX_HEIGHT , not possible . This is used just to avoid RTE **/

    if(pos>n) /** Done with n items and now check condition **/
    {
        return W<=MAX_WEIGHT ? 0 : INT_MIN;
    }

    LL &ret = dp[pos][W];
    if(ret!=-1) return ret;

    LL inc = solve(pos+1,W+w[pos]) + v[pos];
    LL exc = solve(pos+1,W);

    return ret = max(inc,exc);
}

string solve_print(int pos,int W)
{
    if(W>MAX_WEIGHT) return "";
    if(pos>n) return "";

    LL inc = solve(pos+1,W+w[pos]) + v[pos];
    LL exc = solve(pos+1,W);

    if(inc>exc) return to_str(v[pos]) + " " + solve_print(pos+1,W+w[pos]);
    else return solve_print(pos+1,W);
}

int main()
{
    optimizeIO();

    cin>>n>>MAX_WEIGHT;

    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];

    memset(dp,-1,sizeof dp);

    cout<<solve(0,0)<<endl;
    cout<<solve_print(0,0)<<endl;

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

//string solve_print(int i,int w)
//{
//    if(w<0) return ""; /** **/
//
//    if(i==0 || w==0) return "";
//
//    int inc = vara[i] + dp[i-1][w-wara[i]];
//    int exc = dp[i-1][w];
//
//    if(inc>exc)
//        return to_str(vara[i]) + " " + solve_print(i-1,w-wara[i]);
//    else
//        return solve_print(i-1,w);
//}
