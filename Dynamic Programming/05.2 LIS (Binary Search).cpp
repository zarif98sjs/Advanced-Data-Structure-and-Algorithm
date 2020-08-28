
/**

Longest Increasing Subsequnce (Optimized using Binary Search)
-----------------------------

Complexity : O( NlogN )

Details : https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
 
**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

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
const int INF = 1e9;

int solveLIS(vector<int> &v)
{
    int n = v.size();

    vector<int>d(n+1,INF); /// d[i] = element at which subsequence of length i terminates
    vector<int>LIS(n,1);
    d[0] = -INF;

    for(int i=0;i<n;i++)
    {
        int len = upper_bound(ALL(d),v[i]) - d.begin(); /// finding the one and only correct position of the current element

        if(v[i] > d[len-1] && v[i] < d[len]) /// if greater than previous element and a better option
            d[len] = v[i] , LIS[i] = len;
    }

    return *max_element(ALL(LIS));
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int LIS_len = solveLIS(v);
    cout<<LIS_len<<endl;

    return 0;
}

/**
10
1 2 3 4 5 4 3 2 1 10
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
    for(T i:v)
    {
        os<<i<<" " ;
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


