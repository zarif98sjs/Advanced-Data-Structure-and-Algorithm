
/**

Problem : Longest Increasing Subsequence

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
const LL LINF = 1e17;

/** 1 based indexing **/

/**

LIS[i] = LIS ending at index i

**/

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>LIS(n,1); /** length of longest increasing sequence ending at i **/
    vector<vector<int>>SEQ(n);  /** longest increasing sequence ending at i **/

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                if(LIS[j]+1 > LIS[i])
                {
                    LIS[i] = LIS[j]+1;
                    SEQ[i] = SEQ[j];
                }
            }
        }
        SEQ[i].push_back(v[i]);
        DBG(SEQ[i]);
    }

    int lis_len = *max_element(ALL(LIS));
    DBG(lis_len);

    int mx = 0;
    vector<int>MX;

    for(int i=0; i<n; i++)
    {
        if(LIS[i]>mx)
        {
            mx = LIS[i];
            MX = SEQ[i];
        }
    }

    for(auto x:MX)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
/**
5
1 6 2 3 5
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


