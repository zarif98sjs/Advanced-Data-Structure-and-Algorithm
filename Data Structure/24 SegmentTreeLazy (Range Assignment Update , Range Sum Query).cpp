
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

LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL sum ;
    LL lazy;
    bool assignment;

    node()
    {
        sum = 0;
        lazy = 0;

        assignment = false;
    }

    void create_leaf(LL val)
    {
        sum = val;
        lazy = 0;

        assignment = false;
    }

    void merge_nodes(node &A,node &B)
    {
        sum = A.sum + B.sum;
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

void node_update(int v,int st,int en,LL val)
{
    Tree[v].sum = (en-st+1)*val;
    Tree[v].lazy = val;
    Tree[v].assignment = true;
}

void push(int v,int st,int en)
{
    int mid = (st+en)>>1;
    int lc = v<<1, rc = lc|1;

    if(Tree[v].assignment)
    {
        node_update(lc,st,mid,Tree[v].lazy);
        node_update(rc,mid+1,en,Tree[v].lazy);

        Tree[v].assignment = false;
    }
}

void update(int cur, int start, int end, int l,int r, LL value)
{
    if(l>r)
        return;

    if (l==start && r==end)
    {
        node_update(cur,start,end,value);
    }
    else
    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        push(cur,start,end);

        update(lc, start, mid,l,min(r,mid), value);
        update(rc, mid+1, end,max(l,mid+1),r, value);

        Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
    }
}

LL query(int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r)
        return 0;

    if(start>=l && end<=r)
    {
        return Tree[cur].sum;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    push(cur,start,end);

    LL p1 = query(lc,start,mid,l,min(r,mid));
    LL p2 = query(rc,mid+1,end,max(l,mid+1),r);

    return p1+p2;

}

void DEBUG(int n)
{
    cout<<"Current State : ";
    for(int i=1;i<=n;i++)
    {
        LL t = query(1,1,n,i,i);

        cout<<t<<" ";
    }
    cout<<endl;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {

        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
            cin>>ara[i];

        build(1,1,n);

        int q;
        cin>>q;

        while(q--)
        {
            DEBUG(n);

            int type;
            cin>>type;

            if(type==1)
            {
                int l,r,val;
                cin>>l>>r>>val;

                update(1,1,n,l,r,val);
            }
            else
            {
                int l,r;
                cin>>l>>r;

                LL t = query(1,1,n,l,r);

                cout<<t<<endl;
            }
        }

    }

    return 0;
}

/**

5
1 2 3 4 5

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


