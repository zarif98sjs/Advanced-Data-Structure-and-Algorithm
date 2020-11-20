
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

/*
 * Treap
 * =====
 * */

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int a, int b)
{
    int x = uniform_int_distribution<int>(a, b)(rng);
    return x;
}

struct Node
{
    int data,prior;
    Node* l;
    Node* r;

    Node(int data)
    {
        this->data = data;
        prior = getrand(-2e9, 2e9);

        l = r = NULL;
    }

    friend ostream &operator<<(ostream &os, const Node &node) {
        os << "data: " << node.data << " prior: " << node.prior;
        return os;
    }

};
typedef Node* Treap;

struct NormalTreap
{
    Treap root;

    NormalTreap()
    {
        root = NULL;
    }

    void split(Treap t,Treap &l,Treap &r,int data) /*l has all values <= data , r has all values > data*/
    {
        if(!t)
        {
            l = NULL;
            r = NULL;
            return;
        }

        if(t->data <= data)
        {
            split(t->r,t->r,r,data);
            l = t;
        }
        else
        {
            split(t->l,l,t->l,data);
            r = t;
        }
    }

    void meld(Treap &ret,Treap l,Treap r)
    {
        if(!l || !r)
        {
            if(l) ret = l;
            if(r) ret = r;

            if(!l && !r) ret = NULL;
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
    }

    void preorder(Treap t)
    {
        if(!t) return;

        cout<<(*t).data;

        if(t->l || t->r)
            cout<<"(";
        preorder(t->l);
        if(t->l || t->r)
            cout<<")";

        if(t->l || t->r)
            cout<<"(";
        preorder(t->r);
        if(t->l || t->r)
            cout<<")";
    }

    void preorder()
    {
        preorder(root);
        cout<<endl;
    }

    Treap search(Treap t,int data)
    {
        if(!t || t->data==data)
            return t;

        if(data < t->data) return search(t->l,data);
        else return search(t->r,data);
    }

    void insert(Treap &ret,Treap in)
    {
        if(!ret) ret = in;
        else if (in->prior > ret->prior)
        {
            split(ret,in->l,in->r,in->data);
            ret = in;
        }
        else
        {
            if(in->data < ret->data) insert(ret->l,in);
            else insert(ret->r,in);
        }
    }

    void remove(Treap &ret,int data)
    {
        if(!ret) return;

        if(ret->data == data)
        {
            Treap toDel = ret;
            meld(ret,ret->l,ret->r);
            delete (toDel);
        }
        else
        {
            if(data < ret->data) remove(ret->l,data);
            else remove(ret->r,data);
        }
    }

    // operations

    void insert(int val)
    {
        Treap newTreap = new Node(val);

        insert(root,newTreap);
    }

    void remove(int val)
    {
        remove(root,val);
    }

    bool search(int val)
    {
        Treap ret = search(root,val);

        return ret!=NULL;
    }

};


int32_t main()
{
    optimizeIO();

//    freopen("in1.txt","r",stdin);
//    freopen("out7.txt","w",stdout);

    NormalTreap t;

    string option;

    while(cin>>option)
    {
        int num;
        cin>>num;

        if(option=="F")
        {
            bool has = t.search(num);
            if(has)
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
        else if(option=="I")
        {
            t.insert(num);
            t.preorder();
        }
        else if(option=="D")
        {
            t.remove(num);
            t.preorder();
        }
    }

#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

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
