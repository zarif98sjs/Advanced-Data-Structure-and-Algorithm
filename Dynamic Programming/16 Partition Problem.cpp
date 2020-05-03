
/**

Problem : Partition Problem

Given a set of positive integers, find if it can be divided into two subsets with equal sum.

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

vector<int> ara = { -1,7,3,1,5,4,8};
//vector<int> ara = { -1,3,1,1,2,2,1};

/** 1 based indexing **/

/**

dp[i][j] = include or exclude
base case : if sum possible return true

**/

int dp[nmax][nmax];

int solve(int i,int s)
{
    if(i<=0 || s<0)
        return 0;

    if(s==0)
        return 1;

    int &ret = dp[i][s];

    if(ret!=-1)
        return ret;

    int inc = solve(i-1,s-ara[i]);
    int exc = solve(i-1,s);

    return ret = inc|exc;

}

string solve_print(int i,int s)
{
    if(i==0 || s<0)
        return "";
    if(s==0)
        return "";

    int inc = solve(i-1,s-ara[i]);
    int exc = solve(i-1,s);

    if(inc)
        return  solve_print(i-1,s-ara[i]) +  " " + to_str(i);
    else
        return solve_print(i-1,s);

}

int main()
{
    optimizeIO();

    memset(dp,-1,sizeof dp);

    int n = ara.size()-1;

    int total = 0;

    for(int i=1;i<=n;i++)
        total += ara[i];

    if(total%2==1)
        cout<<"Not Possible"<<endl;
    else
    {
        cout<<solve(n,total/2)<<endl;
        cout<<"One part indexes : "<<solve_print(n,total/2)<<endl;
    }

//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=max_cap; j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }

    return 0;
}


