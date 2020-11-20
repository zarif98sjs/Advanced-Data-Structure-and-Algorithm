
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

const int nmax = 2e5+7;

#define int long long

/*
 * Implicit Treap
 * ==============
 * 0 based indexing
 * */

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int a, int b)
{
    int x = uniform_int_distribution<int>(a, b)(rng);
    return x;
}

struct Node
{
    int data,prior,subTreeSize;
    Node* l;
    Node* r;

    // extra variables to solve problems , change here
    int sum,lazy;

    Node(int data)
    {
        this->data = data;
        prior = getrand(-2e9, 2e9);
        subTreeSize = 1;

        l = r = NULL;

        // change here
        sum = data;
        lazy = 0;
    }

    friend ostream &operator<<(ostream &os, const Node &node) {
        os << "data: " << node.data << " prior: " << node.prior << " subTreeSize: " << node.subTreeSize << " sum: "
           << node.sum << " lazy: " << node.lazy;
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
        if(t) t->sum = t->data;
    }

    void combine(Treap &ret,Treap l,Treap r) // change here
    {
        if(!l || !r)
        {
            if(l) ret = l;
            if(r) ret = r;
            return;
        }
        ret->sum = l->sum + r->sum;
    }

    void push(Treap t) // change here
    {
        if(!t || !t->lazy) return;

        /*lazy operation*/
        t->data += t->lazy;
        t->sum  += t->lazy * sz(t);

        /*pushing to children*/
        if(t->l) t->l->lazy += t->lazy;
        if(t->r) t->r->lazy += t->lazy;

        t->lazy = 0;
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
        t2->lazy += val; /*lazy update*/ // change here

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

        return ans;
    }

    void print(Treap t,int add)
    {
        if(!t) return;

        cout<<*t<<endl;

        print(t->l,add);
        print(t->r,add + sz(t->l) + 1);
    }

    void print()
    {
        print(root,0);
    }

    // operations

    void insert(int val)
    {
        Treap newTreap = new Node(val);
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
};


int32_t main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    ImplicitTreap t;

    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i] , t.insert(v[i]);

//    t.print();

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
