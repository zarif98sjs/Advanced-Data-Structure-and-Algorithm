
/**

Meet In The Middle
==================

Demo Problem : LightOj 1127 ( Funny Knapsack )
----------------------------------------------

Given n integers and a knapsack of weight W,
you have to count the number of combinations for which you can add the items in the knapsack without overflowing the weight.

1 ≤ n ≤ 30 and 1 ≤ W ≤ 2 * 1e9

Idea
----
The idea is that you split the large set into two small sets, small enough for you to handle them using the standard algorithm you know,
and then use the result from these two small sets to arrive at the required solution.

Complexity
----------
O(2^(n / 2) log (2^(n / 2))

Related Problems
----------------
LightOj 1127
LightOj 1235
CodeChef : Nice subsets (INSQ15_C)


**/

/** Which of the favors of your Lord will you deny ? **/

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

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

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

vector<LL> subsetSum(const vector<LL> &v)
{
    int n = v.size();

    vector<LL>sum;

    for(int i=0;i<(1<<n);i++)
    {
        LL s = 0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
                s += v[j];
        }
        sum.push_back(s);
    }
    return sum;
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        int n;
        LL w;
        cin>>n>>w;

        vector<LL>v1,v2;

        for(int i=0;i<n;i++)
        {
            LL x;
            cin>>x;

            if(i&1) v2.push_back(x);
            else v1.push_back(x);
        }

        vector<LL> subsetSum1 = subsetSum(v1);
        vector<LL> subsetSum2 = subsetSum(v2);

        sort(ALL(subsetSum2));

        LL ans = 0;

        for(LL s1:subsetSum1)
        {
            LL s2 = w - s1;
            ans += upper_bound(ALL(subsetSum2),s2) - subsetSum2.begin();
        }

        cout<<"Case "<<q<<": ";
        cout<<ans<<endl;

    }


    return 0;
}

/**

10
4 10
1 4 2 8

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


