
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
#include <ostream>

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

const int nmax = 3e5+7;

/*
 * hashing
 * */

const int prime = 31;
const int mod = 1e9+9;

int p[nmax];

/**
 * Modular Arithmetic
 * **/

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

/// ax + by = GCD(a,b)
/// r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
template <class T>
T ext_gcd ( T A, T B, T &X, T &Y )
{
    T x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2;
    Y = y2;
    return r2;
}

template <class T>
T invMod_general(T a,T m) /// when inverse of a (w.r.to mo) && mo is not prime
{
    T x, y;
    ext_gcd( a, m, x, y );

    /// Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 )
        x += m;
    return x;
}

void precalc()
{
    p[0] = 1;
    for(int i=1;i<nmax;i++) p[i] = MUL(p[i-1],prime);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int a, int b)
{
    int x = uniform_int_distribution<int>(a, b)(rng);
    return x;
}

struct Node
{
    int prior,subTreeSize;
    char ch;
    Node* l;
    Node* r;

    // extra variables to solve problems , change here
    int hash;
    int sum,lazy;

    Node(char ch,int hash)
    {
        this->ch = ch;
        prior = getrand(-2e9, 2e9);
        subTreeSize = 1;

        l = r = NULL;

        // change here
        this->hash = hash;
        sum = hash;
        lazy = 1;
    }

    friend ostream &operator<<(ostream &os, const Node &node) {
        os << "prior: " << node.prior << " subTreeSize: " << node.subTreeSize << " ch: " << node.ch << " hash: "
           << node.hash << " sum: " << node.sum << " lazy: " << node.lazy;
        return os;
    }
};

typedef Node* Treap;

struct ImplicitTreap
{
    Treap root;

    ImplicitTreap()
    {
        root = NULL;
    }

    int sz()
    {
        return root == NULL ? 0 : root->subTreeSize;
    }

    int sz(Treap t)
    {
        return t == NULL ? 0 : t->subTreeSize;
    }

    void update_sz(Treap t)
    {
        if(t) t->subTreeSize = 1 + sz(t->l) + sz(t->r);
    }

    void reset(Treap t) // change here
    {
        if(t) t->sum = t->hash;
    }

    void combine(Treap &ret,Treap l,Treap r) // change here
    {
        if(!l || !r)
        {
            if(l) ret = l;
            if(r) ret = r;
            return;
        }
        ret->sum = ADD(l->sum,r->sum);
    }

    void push(Treap t) // change here
    {
        if(!t || t->lazy==1) return;

        /*lazy operation*/
        t->hash = MUL(t->hash,t->lazy);
        t->sum  = MUL(t->sum,t->lazy);

        /*pushing to children*/
        if(t->l) t->l->lazy = MUL(t->l->lazy,t->lazy);
        if(t->r) t->r->lazy = MUL(t->r->lazy,t->lazy);

        t->lazy = 1;
    }

    void segmentTreeOperation(Treap t)
    {
        if(!t) return;

        reset(t); /*unlike segment tree , we need to do this as this element doesn't belong to wither of the child's range*/
        push(t->l);
        push(t->r);
        combine(t,t,t->l);
        combine(t,t,t->r);
    }

    void split(Treap t,Treap &l,Treap &r,int pos,int add = 0)
    {
        if(!t)
        {
            l = NULL;
            r = NULL;
            return;
        }

        push(t); /*push*/

        int implicit_pos = add + sz(t->l); /*implicit indexing in implicit treap*/

        if(implicit_pos <= pos)
        {
            split(t->r,t->r,r,pos,implicit_pos + 1);
            l = t;
        }
        else
        {
            split(t->l,l,t->l,pos,add);
            r = t;
        }

        update_sz(t); /*update size*/
        segmentTreeOperation(t); /*segment tree operation*/
    }

    void meld(Treap &ret,Treap l,Treap r)
    {
        /*push*/
        push(l);
        push(r);

        if(!l || !r)
        {
            if(l) ret = l;
            if(r) ret = r;
        }
        else if(l->prior > r->prior)
        {
            meld(l->r,l->r,r);
            ret = l;
        }
        else
        {
            meld(r->l,l,r->l);
            ret = r;
        }

        update_sz(ret); /*update size*/
        segmentTreeOperation(ret); /*segment tree operation*/
    }

    void range_update(Treap t,int l,int r,int val)
    {
        Treap t1,t2,t3;
        split(t,t1,t2,l-1);
        split(t2,t2,t3,r-l);

        /* t2 represents the range [l,r] */
        t2->lazy = MUL(t2->lazy,val); /*lazy update*/ // change here

        meld(t,t1,t2);
        meld(t,t,t3);
    }

    int range_query(Treap t,int l,int r)
    {
        Treap t1,t2,t3;
        split(t,t1,t2,l-1);
        split(t2,t2,t3,r-l);

        /* t2 represents the range [l,r] */
        int ans = t2->sum; // change here

        meld(t,t1,t2);
        meld(t,t,t3);

        return MUL(ans,invMod_general(p[l],mod));
    }

    void print(Treap t,int add)
    {
        if(!t) return;

        print(t->l,add);

        cout<<(*t).ch<<" ";

        print(t->r,add + sz(t->l) + 1);
    }

    void print()
    {
        print(root,0);
        cout<<endl;
    }

    // operations
    void insert(char ch)
    {
//        cout<<sz(root)<<endl;
        Treap newTreap = new Node(ch,MUL(ch-'a'+1,p[sz(root)]));
        meld(root,root,newTreap);
    }

    void range_update(int l,int r,int val)
    {
        range_update(root,l,r,val);
    }

    int range_query(int l,int r)
    {
        return range_query(root,l,r);
    }

    void deleteAndMeld(int l,int r)
    {
        int len = r-l+1;

        Treap t1,t2,t3;
        split(root,t1,t2,l-1);
        split(t2,t2,t3,r-l); // t2 -> l ... r , t3 -> r+1 ... n-1

        int inv = invMod_general(p[len],mod);

        if(t3) t3->lazy = MUL(t3->lazy,inv);

        meld(root,t1,t3);
    }

    void insertAndMeld(char ch,int pos)
    {
        Treap t1,t2;
        split(root,t1,t2,pos-1);

        assert(sz(t1)==pos);

        Treap newTreap = new Node(ch,MUL(ch-'a'+1,p[sz(t1)]));

        if(t2) t2->lazy = MUL(t2->lazy,p[1]);

        meld(root,t1,newTreap);
        meld(root,root,t2);
    }
};

int32_t main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    precalc();

    string s;
    cin>>s;

    ImplicitTreap t,revt;

    for(int i=0;i<n;i++) t.insert(s[i]);
    for(int i=n-1;i>=0;i--) revt.insert(s[i]);

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            l--,r--;

            int m = t.sz();

            t.deleteAndMeld(l,r);
            revt.deleteAndMeld(m-1-r,m-1-l);

//            t.print();
        }
        else if(type==2)
        {
            char ch;int pos;
            cin>>ch>>pos;

            pos--;

            int m = t.sz();

            t.insertAndMeld(ch,pos);
            revt.insertAndMeld(ch,m-pos);
//            t.print();
        }
        else if(type==3)
        {
            int l,r;
            cin>>l>>r;
            l-- , r--;

            int m = t.sz();

            int h1 = t.range_query(l,r);
            int h2 = revt.range_query(m-1-r,m-1-l);

            if(h1==h2) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else if(type==4)
        {
            /*hash check*/
            int l,r;
            cin>>l>>r;
            l--,r--;

            int ans = t.range_query(l,r);
            DBG(ans);
        }
    }

    return 0;
}

/**
5 10000
aaaaa
2 c 2
2 e 5
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
