
/**

Problem
=======

Given an array arr[] of size N, the task is to find the longest increasing sub-sequence such that
index of any element is divisible by index of previous element (LIIDS).

The following are the necessary conditions for the LIIDS:
If i, j are two indices in the given array. Then:

1.  i < j
2.  j % i = 0
3.  arr[i] < arr[j]

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
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

LL ara[nmax];
LL dp[nmax];

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        LL n;
        cin>>n;

        for(LL i=1; i<=n; i++)
            cin>>ara[i];

        LL ans = 0;
        for (LL i = 1; i <= n; i++)
            dp[i] = 1;

        for (LL i=1; i<= n; i++)
        {
            for (LL j=i+i; j <= n; j += i)
            {
                if (ara[j] > ara[i])
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        cout<<ans<<endl;
    }



    return 0;
}

/**

INPUT
-----
4
4
5 3 4 6
7
1 4 2 3 6 4 9
5
5 4 3 2 1
1
9

OUTPUT
------
2
3
1
1

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


