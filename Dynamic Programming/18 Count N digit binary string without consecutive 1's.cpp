
/**

Problem : N-digit binary strings without any consecutive 1’s

Given a positive integer N, count all N-digit binary strings without any consecutive 1’s.

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

dp[i][j] = solve with 0 [if last digit was 1]
dp[i][j] = solve with 0 + solve with 1 [if last digit was 0]

**/

int dp[nmax][2];

int solve(int i,int last_dig)
{
    if(i==0)
        return 0;
    if(i==1)
    {
        if(last_dig)
            return 1; /** 01 **/
        else
            return 2; /** 00 10 **/
    }

    int &ret = dp[i][last_dig];

    if(ret!=-1)
        return ret;

    if(last_dig)
        ret = solve(i-1,0);
    else
        ret = solve(i-1,0) + solve(i-1,1);

    return ret;
}

void print(int i,int last_dig,string out)
{
    if(i==0)
    {
        cout<<out<<endl;
        return;
    }

    if(last_dig)
        print(i-1,0,out+"0");
    else
    {
        print(i-1,0,out+"0");
        print(i-1,1,out+"1");
    }

}

int main()
{
    optimizeIO();

    memset(dp,-1,sizeof dp);

    int n;
    cin>>n;

    cout<<"Total Possible : "<<solve(n,0)<<endl;
    string out = "";
    print(n,0,out);

    return 0;
}


