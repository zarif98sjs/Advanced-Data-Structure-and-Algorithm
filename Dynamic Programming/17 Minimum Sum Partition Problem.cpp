
/**

Problem : Minimum Sum   Partition Problem

Given a set of positive integers S, partition the set S into two subsets S1, S2 such that
the difference between the sum of elements in S1 and the sum of elements in S2 is minimized.

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

vector<int> ara =  { -1,10, 20, 15, 5, 25 };
//vector<int> ara = { -1,3,1,1,2,2,1};

/** 1 based indexing **/

/**

dp[i][j] = include or exclude
base case : if last index , return difference

**/

int dp[nmax][nmax];

int solve(int i,int s1,int s2)
{
    if(i==0)
        return abs(s1-s2);

    int &ret = dp[i][s1]; /** only i and s1 is enough as s2 is nothing but s-s1 **/

    if(ret!=-1)
        return ret;

    int incs1 = solve(i-1,s1+ara[i],s2);
    int incs2 = solve(i-1,s1,s2+ara[i]);

    return ret = min(incs1,incs2);
}

string solve_print_1(int i,int s1,int s2)
{
    if(i==0)
        return "";

    int incs1 = solve(i-1,s1+ara[i],s2);
    int incs2 = solve(i-1,s1,s2+ara[i]);

    if(incs1<incs2)
        return solve_print_1(i-1,s1+ara[i],s2) + " " + to_str(ara[i]);
    else
        return solve_print_1(i-1,s1,s2+ara[i]);

}

string solve_print_2(int i,int s1,int s2)
{
    if(i==0)
        return "";

    int incs1 = solve(i-1,s1+ara[i],s2);
    int incs2 = solve(i-1,s1,s2+ara[i]);

    if(incs1<incs2)
        return solve_print_2(i-1,s1+ara[i],s2);
    else
        return solve_print_2(i-1,s1,s2+ara[i])+ " " + to_str(ara[i]);

}
int main()
{
    optimizeIO();

    memset(dp,-1,sizeof dp);

    int n = ara.size()-1;

    cout<<solve(n,0,0)<<endl;
    cout<<"One Partition : "<<solve_print_1(n,0,0)<<endl;
    cout<<"Other Partition : "<<solve_print_2(n,0,0)<<endl;


//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=max_cap; j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }

    return 0;
}


