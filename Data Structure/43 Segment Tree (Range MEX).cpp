
/*
*   Range MEX Query
*   ===============
*   Idea : https://stackoverflow.com/questions/41633225/please-tell-me-the-efficient-algorithm-of-range-mex-query
*/

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

int ara[nmax];

struct node
{
    int mn;

    void create_leaf(int val)
    {
        mn = val;
    }

    void merge_nodes(node &A,node &B)
    {
        mn = min(A.mn,B.mn);
    }

};

const int nmax2 = nmax<<2;
node Tree[nmax2];

void build(int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        Tree[cur].create_leaf(ara[start]);
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void update(int cur, int start, int end, int updex, LL value) /** POINT update , replaces the current value **/
{
    if (start == end)
    {
        Tree[cur].create_leaf(value);
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    if (updex <= mid) update(lc, start, mid, updex, value);
    else update(rc, mid+1, end, updex, value);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
}

int findFirstSmallerThan(int cur,int start,int end,int val)
{
//    cout<<start<<" , "<<end<<endl;

    if(start == end)
    {
        return start;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    if(Tree[lc].mn < val) return findFirstSmallerThan(lc,start,mid,val); /** go to left as long as possible , as we want the first element to satisfy our condition **/
    else return findFirstSmallerThan(rc,mid+1,end,val);
}

void solveTC()
{
    int n;
    cin>>n;

    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    /// 0 <= a[i] <= 1e5
    for(int i = 1;i<=100000;i++) ara[i] = -1; /** last occurrence of value i */
    int m = n+1;
    build(1,1,m);

    vector<int>a;

    for(int r=1;r<=n;r++)
    {
        update(1,1,m,v[r],r);

        DBG(r);
        for(int l=1;l<=r;l++)
        {
            int mex = findFirstSmallerThan(1,1,m,l); /** find first element which has last occurrence less than l */
//            DBG(mex);
            a.push_back(mex);
        }
    }

    DBG(a);

    for(int x:a) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

    while(tc--)
    {
        solveTC();
    }

    return 0;
}

/**
6
1 5 6 1 2 3
141 says: a = [ 2 2 1 2 1 1 2 2 2 2 3 3 3 3 1 4 4 4 4 1 1  ]
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
