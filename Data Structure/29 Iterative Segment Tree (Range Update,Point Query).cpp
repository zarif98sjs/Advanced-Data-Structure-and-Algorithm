
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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

int n;  /// array size
LL ara[nmax];

struct node
{
    LL sum;

    node(): sum(0){} /// imp
    node(LL sum) : sum(sum) {}

    void create_leaf(LL val)
    {
        sum=val;
    }
};

node combine(node A,node B)
{
    node ret;
    ret.sum = A.sum + B.sum;
    return ret;
}

node t[2 * nmax];

void build()    /// build the tree
{
    for (int i = 0; i < n; ++i) /// give the values in the leaves
        t[n+i].create_leaf(ara[i]);
}

void modify(int l,int r,int add) /// Add "add" in the range [l,r]
{
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) t[l++].sum += add;
        if (r&1) t[--r].sum += add;
    }
}

LL query(int p) /// value at point p
{
    LL res = 0;

    for (p += n; p > 0; p >>= 1) res += t[p].sum;

    return res;
}

void DEBUG()
{
    cout<<"Current state : ";
    for(int i=0;i<n;i++)
    {
        cout<<query(i)<<" ";
    }
    cout<<endl;
}

int main()
{
//    optimizeIO();

    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>ara[i];

    build();

    int q;
    cin>>q;

    while(q--)
    {
        DEBUG();

        int type;
        cin>>type;

        if(type==1) /** RANGE update **/
        {
            int l,r,add;
            cin>>l>>r>>add;

            l-- , r--; /// 0 based

            modify(l,r,add);
        }
        else /** POINT query **/
        {
            int idx;
            cin>>idx;

            idx--; /// 0 based

            cout<<query(idx)<<endl;
        }
    }


    return 0;
}

/**

10
1 4 3 2 5 7 8 9 10 12

1000

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


