
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

    Node(int data)
    {
        this->data = data;
        prior = getrand(-2e9, 2e9);
        subTreeSize = 1;

        l = r = NULL;

        // change here
    }

    friend ostream &operator<<(ostream &os, const Node &node) {
        os << "data: " << node.data << " prior: " << node.prior << " subTreeSize: " << node.subTreeSize;
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

    /*Add
     * 1. reset
     * 2. combine
     * 3. push
     * 4. segmentTreeOperation
     * */

    void split(Treap t,Treap &l,Treap &r,int pos,int add = 0)
    {
        if(!t)
        {
            l = NULL;
            r = NULL;
            return;
        }

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
    }

    void meld(Treap &ret,Treap l,Treap r)
    {

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
