
/**

Problem : Largest Square Matrix with all 1's

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

dp[i][j] = Largest Square Matrix with all 1's ending at ara[i][j]

For a square matrix of n*n , the left,top and top left is a n-1*n-1 square matrix.
So , dp[i][j] = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]) // if ara[i][j] = 1

Here the minimum is considered because all 3 corner has to have the same number of 1's , otherwise adding one element
won't make it a square matrix with all 1's

**/
int dp[nmax][nmax];

int main()
{
    optimizeIO();

    int r = 8 , c = 6;

    int ara[r+1][c+1] =
	{
	    { 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 1 },
		{ 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 1, 1, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 0, 1, 1 }
	};

	int max_square_n = 0;

	for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(ara[i][j]==1)
            {
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                max_square_n = max(max_square_n,dp[i][j]);
            }
        }
    }

    cout<<"MAx Square Size : "<<max_square_n<<endl;

//    for(int i=1;i<=r;i++)
//    {
//        for(int j=1;j<=c;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }

    return 0;
}


