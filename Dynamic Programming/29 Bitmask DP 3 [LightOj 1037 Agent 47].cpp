
/**

Problem : LightOJ 1037

Idea
====

Bitmask DP

- The answer will be some permutation of the n person
- In bitmask dp , the condition for killing will be : take the one for maximum damage among the already killed ones and kill with that

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
using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

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
LL h[16];
LL ara[16][16];
LL dp[1<<16];

LL solve(int mask)
{
    if(mask==((1<<n)-1))
        return 0;

    LL &ret = dp[mask];

    if(ret!=-1)
        return ret;

    ret = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(!(mask&(1<<i)))
        {
            LL mx = 1; /** max damage by default 1 **/

            for(int j=0; j<n; j++)
                if(mask&(1<<j))
                    mx = max(mx,ara[j][i]); /** maximum damage among the already killed ones and kill with that **/

            ret = min(ret,(h[i]+mx-1)/mx + solve(mask|(1<<i)));
        }
    }

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

        for(int i=0; i<n; i++)
            cin>>h[i];

        char x;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>x, ara[i][j] = x - '0';


        memset(dp,-1,sizeof dp);
        LL ans = solve(0);

        cout<<"Case "<<qq<<": "<<ans<<endl;
    }

    return 0;
}


