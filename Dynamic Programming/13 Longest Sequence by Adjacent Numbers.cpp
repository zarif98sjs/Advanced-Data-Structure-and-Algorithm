
/**

Problem : Longest Sequence formed by adjacent numbers in a matrix

Given a N*N  matrix where each cell has distinct value in the 1 to N * N
Find the longest sequence formed by adjacent numbers in the matrix such that
for each number, the number on the adjacent neighbor is +1 its value

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

const int nmax = 2e3+7;
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

int r = 5, c = 5;

int ara[6][6] =
{
    { 0, 0, 0, 0, 0, 0 },
    { 0, 10, 13, 14, 21, 23 },
    { 0, 11,  9, 22,  2,  3 },
    { 0, 12,  8,  1,  5,  4 },
    { 0, 15, 24,  7,  6, 20 },
    { 0, 16, 17, 18, 19, 25 }
};

/** 1 based indexing **/

/**

dp[i][j] = longest sequence starting from ara[i][j]
dp[i][j] = 1 + solve(next move) // if curr-next = 1

**/

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool isValid(int i,int j)
{
    if(i>=1 && i<=r && j>=1 && j<=c)
        return true;
    return false;
}

int dp[nmax][nmax];

int dfs(int i,int j)
{
    if(!isValid(i,j))
        return 0;

    int &ret = dp[i][j];

    if(ret!=-1) return ret;

    for(int k=0;k<4;k++)
        if(isValid(i+dx[k],j+dy[k]) && ara[i+dx[k]][j+dy[k]]-ara[i][j]==1)
            return ret = 1 + dfs(i+dx[k],j+dy[k]);

    return ret = 1;
}

string find_path(int i,int j)
{
    if(!isValid(i,j))
        return "";

    for(int k=0;k<4;k++)
        if(isValid(i+dx[k],j+dy[k]) && ara[i+dx[k]][j+dy[k]]-ara[i][j]==1)
            return to_str(ara[i][j]) + " " + find_path(i+dx[k],j+dy[k]);

    return to_str(ara[i][j]);
}

int main()
{
    optimizeIO();

    memset(dp,-1,sizeof dp);

    int maxx = 0;
    PII maxx_idx = {0,0};

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(dp[i][j]!=-1)
                continue;

            int val = dfs(i,j);
            if(val>maxx)
            {
                maxx = val;
                maxx_idx = {i,j};
            }
        }
    }

    cout<<maxx<<endl;
    cout<<find_path(maxx_idx.F,maxx_idx.S)<<endl;

//    for(int i=1;i<=r;i++)
//    {
//        for(int j=1;j<=c;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }

    return 0;
}


