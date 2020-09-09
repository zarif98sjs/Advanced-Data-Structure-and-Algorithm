
/**

Fenwick Tree
============

Description
-----------

A data structure to quickly do the following -
1 . Point Update
2 . Prefix Sum Array Update

Operations
----------
- Add value to an index                 : O(logN)
- Calculate Prefix Sum upto an index    : O(logN)

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

/** BIT / FENWICK TREE **/
/*** 1 based indexing ***/

struct Fenwick{

    vector<LL>BIT;
    int N;

    Fenwick (int n) : BIT(n+1,0) , N(n) {}

    inline int LSB(int x) {return x&(-x);} /// find the number with first bit set

    /// POINT update : adds val to index idx
    void add(int idx,LL val)
    {
        for(int i = idx ; i<=N ; i += LSB(i)) /// adding LSB , jumping to next segment covered by this index
            BIT[i] += val;
    }

    /// prefix sum upto index idx
    LL pref(int idx)
    {
        LL sum = 0;

        for(int i = idx ; i>0 ; i -= LSB(i)) /// removing LSB , jumping to next segment covering upto index
            sum += BIT[i];

        return sum;
    }

    /// RANGE Sum query [l,r]
    LL sum(int l,int r)
    {
        return pref(r) - pref(l-1);
    }

    /// first index to have value >= key
    int lower_bound(int key) /** O( (logN)^2 ) **/
    {
        int lo = 1 , hi = N+1;
        while(lo!=hi)
        {
            int mid = lo + (hi-lo)/2;

            if(pref(mid)<key)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }

    /// first index to have value > key
    int upper_bound(int key) /** O( (logN)^2 ) **/
    {
        int lo = 1 , hi = N+1;
        while(lo!=hi)
        {
            int mid = lo + (hi-lo)/2;

            if(pref(mid)<=key)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }

    /// first index to have value >= key
    int lower_bound_lift(LL key) /** O( logN ) **/
    {
        LL sum = 0;
        int pos = 0;

        int k = 0; ///  k = log(N)
        while (1 << (k + 1) <= N)
            k++;

        for(int i=k; i>=0; i--)
        {
            int next_idx = pos + (1 << i);

            /// First check if setting the ith bit won't make 'pos' greater than N
            /// Second check if lifting doesn't make sum >= key
            if( next_idx < N && sum + BIT[next_idx] < key)
            {
                sum += BIT[next_idx];
                pos = next_idx;
            }
        }

        return pos + 1; /// +1 because 'pos' will have position of largest value < key
    }

    /// first index to have value > key
    int upper_bound_lift(LL key) /** O( logN ) **/
    {
        LL sum = 0;
        int pos = 0;

        int k = 0; ///  k = log(N)
        while (1 << (k + 1) <= N)
            k++;

        for(int i=k; i>=0; i--)
        {
            int next_idx = pos + (1 << i);

            /// First check if setting the ith bit won't make 'pos' greater than N
            /// Second check if lifting doesn't make sum > key
            if( next_idx < N && sum + BIT[next_idx] <= key)
            {
                sum += BIT[next_idx];
                pos = next_idx;
            }
        }

        return pos + 1; /// +1 because 'pos' will have position of largest value <= key
    }

    void debug()
    {
        cout<<"Prefix Sum Array : ";
        for(int i=1;i<=N;i++)
            cout<<pref(i)<<" ";
        cout<<endl;
    }
};

int main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    Fenwick f(n);

    vector<LL>ara(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
        f.add(i,ara[i]);
    }

    while(q--)
    {
        f.debug();

        int type;
        cin>>type;

        if(type==1) /** POINT update **/
        {
            int idx,val;
            cin>>idx>>val;

            f.add(idx,val);
        }
        else if(type==2) /** RANGE query **/
        {
            int l,r;
            cin>>l>>r;

            int range_sum = f.sum(l,r);
            cout<<range_sum<<endl;
        }
        else if(type==3) /** lower_bound , upper_bound **/
        {
            int key;
            cin>>key;

            cout<<"Binary Search"<<endl;
            cout<<"lower_bound "<<key<<" : "<<f.lower_bound(key)<<endl;
            cout<<"upper_bound "<<key<<" : "<<f.upper_bound(key)<<endl;

            cout<<"Binary Lifting"<<endl;
            cout<<"lower_bound "<<key<<" : "<<f.lower_bound_lift(key)<<endl;
            cout<<"upper_bound "<<key<<" : "<<f.upper_bound_lift(key)<<endl;
        }
    }


    return 0;
}

/**
10 10
3 4 0 0 0 0 1 2 3 3
1 1 1
3 4
3 8
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
