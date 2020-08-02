
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

inline void bit_on(int &x,int k)
{
    x |= (1<<k);
}

inline void bit_off(int &x,int k)
{
    x &= ~(1<<k);
}

inline void bit_invert(int &x,int k)
{
    x ^= (1<<k);
}

inline void lastOneBit_off(int &x)
{
    x = x&(x-1);
}

inline void allOneBit_off_except_last(int &x)
{
    x = x&(-x);
}

inline bool isPowerOfTwo(int x)
{
    return (x&(x-1)) == 0 ? true : false;
}

void PRINT(int x)
{
    cout<<bitset<8>(x)<<endl;
}

int main()
{
    optimizeIO();

    while(true)
    {
        int x;
        cin>>x;
        PRINT(x);

        cout<<isPowerOfTwo(x)<<endl;

        bit_on(x,2);
        PRINT(x);

        bit_off(x,2);
        PRINT(x);

        bit_invert(x,2);
        PRINT(x);

        lastOneBit_off(x);
        PRINT(x);

        allOneBit_off_except_last(x);
        PRINT(x);

    }

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


