
/**

Problem : LightOj 1036
2 Way Prefix Sum

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

const int nmax = 500+7;
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

int r,c;

int U[nmax][nmax];
int R[nmax][nmax];
int dp[nmax][nmax];

int solve(int i,int j)
{
    if(i==0 || j==0) return 0;

    int &ret = dp[i][j];

    if(ret!=-1) return ret;

    int left = solve(i,j-1) + R[i][j]; /** go left and add All Radiums upwards from that position (Prefix Sum) **/
    int up = solve(i-1,j) + U[i][j];   /** go up and add All Uraniums leftwards from that position (Prefix Sum) **/

    return ret = max(left,up);
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int qq=1; qq<=tc; qq++)
    {
        cin>>r>>c;

        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
            {
                cin>>U[i][j];

                if(j>1)
                    U[i][j] += U[i][j-1];
            }

        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
            {
                cin>>R[i][j];

                if(i>1)
                    R[i][j] += R[i-1][j];
            }

        memset(dp,-1,sizeof dp);
        int ans = solve(r,c);

        cout<<"Case "<<qq<<": "<<ans<<endl;
    }

    return 0;
}


