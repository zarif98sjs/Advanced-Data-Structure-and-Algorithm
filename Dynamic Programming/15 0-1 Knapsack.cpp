
/**

Problem : 0-1 Knapsack

In 0-1 Knapsack problem, we are given a set of items, each with a weight and a value and
we need to determine the number of each item to include in a collection so that
the total weight is less than or equal to a given limit and the total value is as large as possible.

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

const int nmax = 100+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

vector<int> vara = { -1, 20, 5, 10, 40, 15, 25 };
vector<int> wara = { -1, 1, 2,  3,  8,  7, 4 };
int max_cap = 10;

/** 1 based indexing **/

/**

dp[i][j] = max(include the item , exclude the item)

**/

int dp[nmax][nmax];

int solve(int i,int w)
{
    if(w<0) return INT_MIN; /** **/

    if(i==0 || w==0) return 0;

    int &ret = dp[i][w];

    if(ret!=-1) return ret;

    int inc = vara[i] + solve(i-1,w-wara[i]);
    int exc = solve(i-1,w);

    return ret = max(inc,exc);
}

string solve_print(int i,int w)
{
    if(w<0) return ""; /** **/

    if(i==0 || w==0) return "";

    int inc = vara[i] + dp[i-1][w-wara[i]];
    int exc = dp[i-1][w];

    if(inc>exc)
        return to_str(vara[i]) + " " + solve_print(i-1,w-wara[i]);
    else
        return solve_print(i-1,w);
}


int main()
{
    optimizeIO();

    memset(dp,-1,sizeof dp);

    int n = vara.size()-1;

    cout<<solve(n,max_cap)<<endl;
    cout<<solve_print(n,max_cap)<<endl;

//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=max_cap; j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }

    return 0;
}


