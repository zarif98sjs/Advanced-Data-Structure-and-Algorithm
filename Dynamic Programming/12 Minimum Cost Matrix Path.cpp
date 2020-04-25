
/**

Problem : Minimum Cost Matrix Path

Given a M x N matrix where each cell has a cost associated with it, find the minimum cost to reach last cell .
Available move : One Right || One Down

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

/** 1 based indexing **/

/**

dp[i][j] = minimum cost to reach cost[i][j]
dp[i][j] = cost[i][j] +  min(dp[i-1][j],dp[i][j-1]) // with corner cases of first row and column

**/
int dp[nmax][nmax];

int main()
{
    optimizeIO();

    int r = 5 , c = 5;

    int cost[r+1][c+1] =
	{
	    { 0, 0, 0, 0, 0, 0 },
		{ 0, 4, 7, 8, 6, 4 },
		{ 0, 6, 7, 3, 9, 2 },
		{ 0, 3, 8, 1, 2, 4 },
		{ 0, 7, 1, 7, 3, 7 },
		{ 0, 2, 9, 8, 9, 3 }
	};

	int min_cost = INT_MAX;

	for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(i==1 && j==1) dp[i][j] = cost[i][j];
            else if(i==1) dp[i][j] = cost[i][j] + dp[i][j-1];
            else if(j==1) dp[i][j] = cost[i][j] + dp[i-1][j];
            else dp[i][j] = cost[i][j] +  min(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<"Minimum Cost : "<<dp[r][c]<<endl;

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}


