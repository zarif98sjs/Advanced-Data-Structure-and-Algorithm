
/**

Problem : LightOJ 1011

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
LL ara[16][16];
LL dp[16][1<<16];

LL solve(int r,int mask)
{
    if(r==n) return 0;

    LL &ret = dp[r][mask];

    if(ret!=-1) return ret;

    for(int c = 0;c<n;c++)
        if(!(mask&(1<<c)))
            ret = max(ret, ara[r][c] + solve(r+1,mask | (1<<c)));

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
            for(int j=0;j<n;j++)
                cin>>ara[i][j];

        memset(dp,-1,sizeof dp);
        LL ans = solve(0,0);

        cout<<"Case "<<qq<<": "<<ans<<endl;
    }

    return 0;
}


