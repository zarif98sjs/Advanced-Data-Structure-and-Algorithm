
/**

LCP Array Construction

Time Complexity : O( N )

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

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cout << __LINE__ << " says: " << #x << " = " << (x) << endl
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

void count_sort(vector<int> &p,vector<int> &c)
{
    int n = p.size();

    vector<int>cnt(n);

    for(auto el:c)
        cnt[el]++;

    vector<int>np(n);
    vector<int>pos(n); /// pos[i] = first empty position in bucket i

    pos[0] = 0;
    for(int i=1; i<n; i++)
        pos[i] = pos[i-1] + cnt[i-1];

    for(auto el:p)
    {
        int i = c[el]; /// bucket
        np[pos[i]] = el; /// putting element in bucket
        pos[i]++; /// empty position in bucket i increased
    }

    p = np;

}

vector<int> buildSuffixArray(string s)
{
    s += "$";

    int n = s.size();

    /// init p , c

    vector<PII>v(n);

    for(int i=0; i<n; i++)
        v[i] = {s[i],i};
    sort(ALL(v));

    vector<int>p(n), c(n);
    for(int i=0; i<n; i++)
        p[i] = v[i].S;

    c[p[0]] = 0;
    for(int i=1; i<n; i++)
    {
        if(v[i].F!=v[i-1].F)
            c[p[i]] = c[p[i-1]] + 1;
        else
            c[p[i]] = c[p[i-1]];
    }

    /// logN times

    int k = 0;

    while((1<<k) < n)
    {
        for(int i=0; i<n; i++)
            p[i] = (p[i] - (1<<k) + n)%n;

        count_sort(p,c);

        vector<int>nc(n);

        nc[p[0]] = 0;
        for(int i=1; i<n; i++)
        {
            PII now  = { c[p[i]] , c[ (p[i]+(1<<k))%n] };
            PII prev = { c[p[i-1]] , c[ (p[i-1]+(1<<k))%n] };

            if(now!=prev)
                nc[p[i]] = nc[p[i-1]] + 1;
            else
                nc[p[i]] = nc[p[i-1]];
        }

        c = nc;
        k++;
    }

    /// after all the iterations , c[i] = position of the suffix i in p

    return p;
}

vector<int> buildLCPArray(string s,vector<int> &p)
{
    s+="$";
    int n = s.size();

    vector<int>rnk(n);

    for(int i=0;i<n;i++)
        rnk[p[i]] = i; /// this is basically the c array after all iterations

    vector<int>lcp(n);

    int k = 0;

    for(int i=0;i<n-1;i++)
    {
        int pi = rnk[i];
        int j = p[pi-1];

        /// lcp[i] = lcp(s[i...],s[j...])

        while(s[i+k]==s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1,0);
    }

    return lcp;
}

LL totalSubstring(LL n)
{
    return (n*(n+1))/2;
}

int main()
{
    optimizeIO();

    string s;
    cin>>s;

    vector<int>p = buildSuffixArray(s);
    vector<int>lcp = buildLCPArray(s,p);

    LL repeat = 0;
    for(int i=1; i<(int)lcp.size(); i++)
        repeat += lcp[i];

    LL distinct = totalSubstring(s.size()) - repeat;
    cout<<distinct<<endl;

    return 0;
}

/**
abb@bbabb
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


