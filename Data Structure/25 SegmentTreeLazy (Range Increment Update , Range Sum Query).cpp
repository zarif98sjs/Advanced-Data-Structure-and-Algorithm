
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

#define int long long

struct Node
{
    int sum;
    int lazy;

    Node() /// change here
    {
        sum = 0 , lazy = 0;
    }

    void create_leaf(int val) /// change here
    {
        sum = val , lazy = 0;
    }
};

Node merge_nodes(Node &a,Node &b) /// change here
{
    Node temp;
    temp.sum = a.sum + b.sum;

    return temp;
}

struct LazySegTree
{
    int n;
    vector<int>data;
    vector<Node>Tree;

    LazySegTree(int n)
    {
        this->n = n;
        int len = n+1;

        data = vector<int>(len);
        Tree = vector<Node>(len<<2);
    }

    void build()
    {
        build(1,1,n);
        return;
    }

    void build(int cur,int start,int end)
    {
        if(start==end)
        {
            Tree[cur].create_leaf(data[start]);
            return;
        }

        int mid = (start+end)>>1;
        int lc = cur<<1 , rc = lc|1;

        build(lc,start,mid);
        build(rc,mid+1,end);

        Tree[cur] = merge_nodes(Tree[lc],Tree[rc]);
    }

    void node_update(int v,int st,int en,int add) /// change here
    {
        Tree[v].sum += (en-st+1) * add;
        Tree[v].lazy += add;
    }

    void push(int v,int st,int en)
    {
        int mid = (st+en)>>1;
        int lc = v<<1, rc = lc|1;

        if(Tree[v].lazy && st!=en) /// not leaf and lazy node
        {
            node_update(lc,st,mid,Tree[v].lazy);   /** Multiplying the size of the left node with the parent's lazy value **/
            node_update(rc,mid+1,en,Tree[v].lazy); /** Multiplying the size of the right node with the parent's lazy value **/

            Tree[v].lazy = 0;
        }
    }

    void update(int ql,int qr,int add)
    {
        update(1,1,n,ql,qr,add);
    }

    void update(int cur,int start,int end,int ql,int qr,int add)
    {
        push(cur,start,end);

        if(end<ql || start>qr) return;

        if(start>=ql && end<=qr)
        {
            node_update(cur,start,end,add);
            // push(cur,start,end);
            return;
        }

        int mid = (start+end)>>1;
        int lc = cur<<1 , rc = lc|1;

        update(lc,start,mid,ql,qr,add);
        update(rc,mid+1,end,ql,qr,add);

        Tree[cur] = merge_nodes(Tree[lc],Tree[rc]); /// bottom up correction after update
    }

    Node query(int ql,int qr)
    {
        return query(1,1,n,ql,qr);
    }

    Node query(int cur,int start,int end,int ql,int qr)
    {
        push(cur,start,end);

        if(end<ql || start>qr) return Node();

        if(start>=ql && end<=qr)
        {
//            cout<<start<<" , "<<end<<" : "<<Tree[cur].sum<<endl;

            return Tree[cur];
        }

        int mid = (start+end)>>1;
        int lc = cur<<1 , rc = lc|1;

        /// query on both child
        Node ansL = query(lc,start,mid,ql,qr);
        Node ansR = query(rc,mid+1,end,ql,qr);

        return merge_nodes(ansL,ansR);
    }
};

int TC = 0;

void solveTC()
{
    int n,q;
    cin>>n>>q;

    LazySegTree s(n);

    for(int i=1;i<=n;i++) s.data[i] = 0;

    s.build(1,1,n);

    while(q--)
    {
        int type;
        cin>>type;

        if(type==0)
        {
            int l,r,add;
            cin>>l>>r>>add;

            s.update(l,r,add);
        }
        else
        {
            int l,r;
            cin>>l>>r;

            int ans = s.query(l,r).sum;
            cout<<ans<<endl;
        }
    }
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
    cin>>tc;

    while(tc--)
    {
        solveTC();
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




