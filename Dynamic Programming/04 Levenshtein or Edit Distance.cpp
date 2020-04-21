
/**

Problem : Levenshtein /Edit Distance
The Levenshtein distance between two words is the minimum number of single-character edits
(i.e. insertions, deletions or substitutions) required to change one word into the other.
Each of these operations has unit cost.

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

unordered_map<string,int>dp;

int e_length(string X,string Y,int m,int n)
{
    if(m==0 || n==0)
        return max(m,n); /** the one which is not 0 **/

    string key  = to_str(m) + "|" + to_str(n);

    if(dp.find(key)!=dp.end())
        return dp[key];

    if(X[m-1]==Y[n-1])
        dp[key] = e_length(X,Y,m-1,n-1);
    else
        dp[key] = 1 + min(e_length(X,Y,m-1,n-1),min(e_length(X,Y,m,n-1),e_length(X,Y,m-1,n)));

    return dp[key];
}

string e_print(string X,string Y,int m,int n)
{
    if(m==0 && n==0) return "";
    if(m==0) return "+("+Y.substr(0,n)+")"; /** Add the part of Y which is left **/
    if(n==0) return "-("+X.substr(0,m)+")"; /** Delete the part of X which is left **/

    if(X[m-1]==Y[n-1])
        return e_print(X,Y,m-1,n-1) + X.substr(m-1,1);

    string key1  = to_str(m-1) + "|" + to_str(n-1);
    string key2  = to_str(m-1) + "|" + to_str(n);
    string key3  = to_str(m) + "|" + to_str(n-1);

    int val1 = dp[key1] , val2 = dp[key2] , val3 = dp[key3];
    int minn = min(val1,min(val2,val3));

    if(minn==val1) return e_print(X,Y,m-1,n-1) + "(-"+X.substr(m-1,1)+"+"+Y.substr(n-1,1)+")"; /** Substitution **/
    if(minn==val2) return e_print(X,Y,m-1,n) + "-"+X.substr(m-1,1); /** Deletion **/
    if(minn==val3) return e_print(X,Y,m,n-1) + "+"+Y.substr(n-1,1); /** Addition **/

}

int main()
{
    optimizeIO();

    string X = "kitten";
    string Y = "sitting";

//    string X = "kiy";
//    string Y = "sitting";

    cout<<"X : "<<X<<endl;
    cout<<"Y : "<<Y<<endl;

    cout<<"Edit Distance : "<<e_length(X,Y,X.size(),Y.size())<<endl;
    cout<<"Edit String : "<<e_print(X,Y,X.size(),Y.size())<<endl;

    return 0;
}


