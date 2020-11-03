
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

/**

Implicit Segment Tree (Point Update , Range Query)
==================================================
1 based indexing

**/

struct Node
{
    int sum;
    Node *left , *right;

    Node() /// change here
    {
        sum = 0;
        left = NULL;
        right = NULL;
    }
};

struct ImplicitSegmentTree
{
    int n;
    Node *root;

    ImplicitSegmentTree(int n)
    {
        this->n = n;
        root = new Node();
    }

    void update(int updex,int val)
    {
        update(root,1,n,updex,val);
    }

    void update(Node* v,int start,int end,int updex,int val)
    {
        if(start==end)
        {
            v->sum += val;
            return;
        }

        int mid = (start+end)>>1;

        if(v->left==NULL) v->left = new Node();
        if(v->right==NULL) v->right = new Node();

        if(updex<=mid) update(v->left,start,mid,updex,val);
        else update(v->right,mid+1,end,updex,val);

        v->sum = v->left->sum + v->right->sum;
    }

    int query(int ql,int qr)
    {
        return query(root,1,n,ql,qr);
    }

    int query(Node *v,int start,int end,int ql,int qr)
    {
        if(v==NULL) return 0;

        if(end<ql || start>qr) return 0;

        if(start>=ql && end<=qr)
        {
            return v->sum;
        }

        int mid = (start+end)>>1;

//        if(v->left==NULL) v->left = new Node();
//        if(v->right==NULL) v->right = new Node();

        /// query on both child
        int p1 = query(v->left,start,mid,ql,qr);
        int p2 = query(v->right,mid+1,end,ql,qr);

        return p1+p2;
    }
};

void solveTC()
{
    int n,q;
//    cin>>n>>q;
    scanf("%d %d",&n,&q);

    int MX = 1e9+2;

    ImplicitSegmentTree s(MX);

    vector<int>v(n+1);

    for(int i=1;i<=n;i++) scanf("%d",&v[i]);

    for(int i=1;i<=n;i++) s.update(v[i],1);

    while(q--)
    {
        char ch;
        scanf(" %c ",&ch);

        if(ch=='!')
        {
            int pos,new_val;
            scanf("%d %d",&pos,&new_val);

            s.update(v[pos],-1);
            v[pos] = new_val;
            s.update(v[pos],1);

        }
        else
        {
            int a,b;
            scanf("%d %d",&a,&b);

            int ans = s.query(a,b);
            printf("%d\n",ans);
        }
    }
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


