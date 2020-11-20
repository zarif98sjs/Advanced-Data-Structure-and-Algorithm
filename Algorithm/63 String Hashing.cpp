
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
const int prime = 31;
const int mod = 1e9+7;

int p[nmax];
int prefixHash[nmax];

/*
 * Modular Arithmetic
 * */

int MUL(int a,int b)
{
    a %= mod;
    b %= mod;
    return (1LL*a*b) % mod;
}

int ADD(int a,int b)
{
    a %= mod;
    b %= mod;
    return (1LL*a+b) % mod;
}

int MINUS(int a,int b)
{
    a %= mod;
    b %= mod;
    return (1LL*a-b+mod)%mod;
}

void precalc()
{
    p[0] = 1;
    for(int i=1;i<nmax;i++) p[i] = MUL(p[i-1],prime);
}

void computePrefixHash(string s) /*prefix hash function*/
{
    int n = s.size();
    s = "#" + s;

    for(int i=1;i<=n;i++) prefixHash[i] = ADD(prefixHash[i-1],MUL(s[i]-'a'+1,p[i-1]));
}

int getSubstringHash(int l,int r) /*1 based indexing*/
{
    int ret = MINUS(prefixHash[r],MUL(prefixHash[l-1],p[r-l+1])); /*substring hash from prefix hash*/
    return ret;
}

int32_t main()
{
    optimizeIO();

    precalc(); /*precalculating prime exponentiations*/

    string s;
    cin>>s;

    computePrefixHash(s);

    int n = s.size();
    s = "#" + s;

    return 0;
}

/**

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
