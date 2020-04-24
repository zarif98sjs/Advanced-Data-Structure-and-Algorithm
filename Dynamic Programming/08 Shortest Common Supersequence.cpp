
/**

Problem : Shortest Common Supersequence

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

/**
SCS[i][j] = SCS(X[1...i],Y[1...j])
**/

unordered_map<string,int>dp;

int solve(string X,string Y,int m,int n)
{
    if(m==0 || n==0)
        return max(m,n); /** If one string has ended return the remaining length of the other string **/

    string key  = to_str(m) + "|" + to_str(n);

    if(dp.find(key)!=dp.end())
        return dp[key];

    if(X[m-1]==Y[n-1])
        dp[key] = 1 + solve(X,Y,m-1,n-1); /** Take that and solve for the rest **/
    else
        dp[key] = 1 + min(solve(X,Y,m-1,n),solve(X,Y,m,n-1)); /** Take either one and solve for the both **/

    return dp[key];
}

string solve_print(string X,string Y,int m,int n)
{
    if(m==0) return Y.substr(0,n);
    if(n==0) return X.substr(0,m);

    if(X[m-1]==Y[n-1])
        return solve_print(X,Y,m-1,n-1) + X[m-1];

    string key1  = to_str(m) + "|" + to_str(n-1);
    string key2  = to_str(m-1) + "|" + to_str(n);

    if(dp[key1]<dp[key2])
        return solve_print(X,Y,m,n-1) + Y[n-1];
    else
        return solve_print(X,Y,m-1,n) + X[m-1];

}

int main()
{
    optimizeIO();

    string X = "ABCBDAB";
    string Y = "BDCABA";

    cout<<"SCS Length : "<<solve(X,Y,X.size(),Y.size())<<endl;
    cout<<"SCS : "<<solve_print(X,Y,X.size(),Y.size())<<endl;

    return 0;
}


