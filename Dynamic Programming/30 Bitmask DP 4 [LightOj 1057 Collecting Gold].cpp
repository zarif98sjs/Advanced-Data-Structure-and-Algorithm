
/**

Problem : LightOJ 1057

Idea
====

Bitmask DP

- The answer will be some permutation of all gold positions .
- Start from any position and use bitmask dp to solve this .

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


int r,c,n;
PII me;
string grid[20];
vector<PII>gold;
LL dp[(1<<16)+10][20];

inline LL distance(PII a,PII b) /** In each move you can go to all 8 adjacent places inside the city. So , the distance is not (difference of x + difference of y) **/
{
    return max(abs(a.F-b.F) ,abs(a.S-b.S));
}

LL solve(int mask,int prev_idx)
{
    if(mask==((1<<n)-1)) return distance(gold[prev_idx],gold[0]);

    LL &ret = dp[mask][prev_idx];

    if(ret!=-1) return ret;

    ret = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(!(mask&(1<<i)))
        {
            LL dist = distance(gold[i],gold[prev_idx]);
            ret = min(ret,dist+solve(mask|(1<<i),i));
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
        gold.clear();

        cin>>r>>c;

        for(int i=0;i<r;i++)
            cin>>grid[i];

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]=='g' || grid[i][j]=='x') gold.push_back({i,j});

        n = gold.size();

        memset(dp,-1,sizeof dp);
        LL ans = solve(1,0); /** We don't necessarily have to start from 'x' **/

        cout<<"Case "<<qq<<": "<<ans<<endl;
    }

    return 0;
}

/**

3

5 5
x....
g....
g....
.....
g....


5 5
x....
g....
g....
.....
.....


5 6
x....g
...g..
.g....
.....g
...g..

**/


