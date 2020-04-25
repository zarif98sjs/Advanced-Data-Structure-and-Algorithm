
/**

Problem : Number of paths in a matrix with certain cost

Find the number of paths from [1,1] to [r,c] with TARGET weight

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

int r = 4, c = 4;

int ara[5][5] =
{
    { 0, 0, 0, 0, 0 },
    { 0, 4, 7, 1, 6 },
    { 0, 5, 7, 3, 9 },
    { 0, 3, 2, 1, 2 },
    { 0, 7, 1, 6, 3 }
};

int target = 25;

/** 1 based indexing **/

/**

dp[i][j][cost] = number of paths with TARGET weight starting from ara[i][j] , current weight = cost
dp[i][j][cost] = solve(i,j+1,cost + ara[i][j+1]) + solve(i+1,j,cost + ara[i+1][j])

**/

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool isValid(int i,int j)
{
    if(i>=1 && i<=r && j>=1 && j<=c)
        return true;
    return false;
}

int dp[nmax][nmax][nmax]; /** use unordered_map<string,int>dp for memory optimization **/

int solve(int i,int j,int cost)
{
    if(cost>target)
        return 0;

    if(i==r && j==c)
    {
        if(cost==target) return 1;
        else return 0;
    }

    int &ret = dp[i][j][cost];

    if(ret!=-1) return ret;

    ret = 0;
    if(isValid(i,j+1)) ret += solve(i,j+1,cost + ara[i][j+1]);
    if(isValid(i+1,j)) ret += solve(i+1,j,cost + ara[i+1][j]);

    return ret;
}

int main()
{
    optimizeIO();

    memset(dp,-1,sizeof dp);

    cout<<solve(1,1,ara[1][1])<<endl;
//    cout<<dp[1][1][ara[1][1]]<<endl;
//    cout<<dp[r][c-1][22]<<endl;
//    cout<<dp[r-1][c][22]<<endl;

    return 0;
}


