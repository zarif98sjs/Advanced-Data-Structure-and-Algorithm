
/**

Sparse Table (RMQ)
==================================

Process 1 : O(logN)
---------

LL query(int L,int R) /// Range Min Query O(logN)
{
    LL mn = LLONG_MAX;
    for (int j = K; j >= 0; j--)
    {
        if ((1 << j) <= R - L + 1)
        {
            mn = min(mn,st[L][j]);
            L += 1 << j;
        }
    }

    return mn;
}

Process 2 : O(1)
---------
See code

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

/**

Sparse Table (RMQ)

**/

/// 0 based indexing

const int nmax = 1e6+7;
const int K = 25; /// log(nmax)

int N;
vector<LL>v;
LL st[nmax][K + 1];
int LOG[nmax];

LL f(LL x,LL y)
{
    return min(x,y);
}

void precalc() /// O(NlogN)
{
    for (int i = 0; i < N; i++)
        st[i][0] = v[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = f(st[i][j-1] ,st[i + (1 << (j - 1))][j - 1]);

    LOG[1] = 0;
    for (int i = 2; i < nmax; i++)
        LOG[i] = LOG[i/2] + 1;
}

LL query(int L,int R)
{
    int j = LOG[R - L + 1];
    LL mn = min(st[L][j], st[R - (1 << j) + 1][j]);

    return mn;
}


int main()
{
    optimizeIO();

    cin>>N;

    v = vector<LL>(N);

    for(int i=0;i<N;i++)
        cin>>v[i];

    precalc();

    int q;
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        LL ans = query(l,r);
        DBG(ans);
    }

    return 0;
}

/**
10
5 3 4 6 8 1 2 4 6 7
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


