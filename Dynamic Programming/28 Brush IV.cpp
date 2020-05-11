
/**

Problem : LightOJ 1018

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

const int nmax = 2e5+7;
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


int n;
int X[16];
int Y[16];
int col[16][16];
int dp[1<<16];

bool collinear(int i, int j, int k) {
  return ((X[i] - X[j]) * (Y[k] - Y[j]) - (Y[i] - Y[j]) * (X[k] - X[j])) == 0;
}

void precalc()
{
    memset(col,0,sizeof col);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(i!=j && collinear(i,j,k))
                    col[i][j] |= (1<<k); /** Number of 1's in col[i][j] = How many Points are collinear with ith and jth point **/

}

int solve(int mask)
{
    if(mask==((1<<n)-1)) return 0;

    if (__builtin_popcount(mask) == (n - 1)) /** n-1 other points are already collinear with this one **/
        return 1;

    int &ret = dp[mask];

    if(ret!=-1) return ret;

    int i;
    for(i=0;mask&(1<<i);i++); /** Go to the lsb which is not collinear **/
    /**Suppose you have satisfied bitmask M of the points. Let the lowest index dust point which hasn't been cleaned yet be x. Note that you are going to have to clean x eventually. Therefore you lose nothing by assuming you definitely clean x now. Then at each state you narrow down to N edges because you have one point which must be on the line **/

    ret = INT_MAX;
    for(int j=0;j<n;j++)
        if(i!=j && !(mask&(1<<j)))
            ret = min(ret,1 + solve(mask|col[i][j]));

    return ret;
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int qq=1; qq<=tc; qq++)
    {
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>X[i]>>Y[i];

        precalc();
        memset(dp,-1,sizeof dp);
        int ans = solve(0);

        cout<<"Case "<<qq<<": "<<ans<<endl;
    }

    return 0;
}


