
/**

2D Fenwick Tree
===============

Description
-----------

A data structure to quickly do the following -
1 . Point Update
2 . Prefix Sum Array Update

Operations
----------
- Add value to an index                 : O( (logN)^2 )
- Calculate Prefix Sum upto an index    : O( (logN)^2 )

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

struct Fenwick2D{

    vector<vector<LL>>BIT;
    int R,C;

    Fenwick2D (int r,int c) : BIT(r+1,vector<LL>(c+1,0)) , R(r) , C(c) {}

    inline int LSB(int x) {return x&(-x);} /// find the number with first bit set

    /// POINT update : adds val to index (x,y)
    void add(int x,int y,LL val)
    {
        for(int i = x ; i<=R ; i += LSB(i))
            for(int j = y ; j<=C ; j += LSB(j))
                BIT[i][j] += val;
    }

    /// prefix sum of [(1,1) , (x,y)] square
    LL pref(int x,int y)
    {
        LL sum = 0;

        for(int i = x ; i>0 ; i -= LSB(i))
            for(int j = y ; j>0 ; j -= LSB(j))
            sum += BIT[i][j];

        return sum;
    }

    void debug()
    {
        cout<<"Prefix Sum Array :\n";
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
                cout<<pref(i,j)<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};


int main()
{
    optimizeIO();

    int r,c;
    cin>>r>>c;

    Fenwick2D f(r,c);

    return 0;
}

/**
5 6 5
2 2 2 4 5 1
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
