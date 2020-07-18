
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long unsigned int
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

int ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    int od,ev;
    int lazy;

    node()
    {
        od = ev = 0;
        lazy = 0;
    }

    void create_leaf(int val)
    {
        if(val&1) od = 1;
        else ev = 1;

        lazy = 0;
    }

    void merge_nodes(node &A,node &B)
    {
        od = A.od + B.od;
        ev = A.ev + B.ev;
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

void node_update(int v,int add)
{
    swap(Tree[v].od,Tree[v].ev);
    Tree[v].lazy += add;

}
void push(int v)
{
    int lc = v<<1, rc = lc|1;

    if(Tree[v].lazy&1)
    {
        node_update(lc,Tree[v].lazy);
        node_update(rc,Tree[v].lazy);

        Tree[v].lazy = 0;
    }
}

void update(int cur, int start, int end, int l,int r, int add)
{
    if(l>r)
        return;

    if(l==start && r==end)
    {
        node_update(cur,1);
    }
    else
    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        push(cur);

        update(lc, start, mid,l,min(r,mid), add);
        update(rc, mid+1, end,max(l,mid+1),r, add);

        Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
    }
}

LL query(int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r)
        return 0;

    if(start>=l && end<=r)
    {
        return Tree[cur].od;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    push(cur);

    LL p1 = query(lc,start,mid,l,min(r,mid));
    LL p2 = query(rc,mid+1,end,max(l,mid+1),r);

    return p1+p2; /// sum

}

void CLEAR()
{
    for(int i=0;i<nmax2;i++)
        Tree[i].create_leaf(0);
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

//    WRITE;

    int tc = 1;

    while(tc--)
    {
        CLEAR();

        int n,q;
        cin>>n>>q;

        for(int i=1;i<=n;i++)
            ara[i] = 0;

        build(1,1,n);

        while(q--)
        {
//            DEBUG(n);

            int type;
            cin>>type;

            if(type==0)
            {
                int l,r,add = 1;
                cin>>l>>r;

                update(1,1,n,l,r,add);
            }
            else
            {
                int l,r;
                cin>>l>>r;

                LL t = query(1,1,n,l,r);

//                cout<<"Ans : "<<t<<endl;
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


