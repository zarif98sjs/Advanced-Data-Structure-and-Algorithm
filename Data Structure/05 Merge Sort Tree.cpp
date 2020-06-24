
/**

PROBLEM : Array of N integers
          Query(l,r,k) : number of integers < k in the range [l,r]


Query Modifications
===================

Type 1 : number of integers >= OR <= in a range
======

( Mod 0 ) number of integers less < k in the range [l,r]  : lower_bound(ALL(Tree[cur].v),k) - Tree[cur].v.begin();

0 1 2 ... k-1 k k+1...
--------------^-------

( Mod 1 ) number of integers less <= k in the range [l,r] : upper_bound(ALL(Tree[cur].v),k) - Tree[cur].v.begin();

0 1 2 ... k-1 k k k k k k  k+1...
----------------------------^----

(Mod 2 ) number of integers x such that ( a <= x <= b )  : upper_bound(ALL(Tree[cur].v),b) - lower_bound(ALL(Tree[cur].v),a);

0 1 2 ... a a a a a a ..... b b b b b b+1...
----------^----------------------------^----

Type 2 : smallest number greater or equal to a specified number k
======

if(end<l || start>r)
        return INT_MAX;
-----------------------
auto pos = lower_bound(ALL(Tree[cur].v),k)
if(pos != Tree[cur].v.end())
    return *pos;
return INF;
------------------------
return min(p1,p2);



=========================================================================================================================

DATA STRUCTURE
--------------
MERGE SORT TREE

Complexity
----------

Build   :   O( N (logN)^2 )
Query   :   O( (logN)^2 )
Update  :   O( (logN)^2 )

Memory  :   O( NlogN )


RESOURCE
--------
1) https://www.commonlounge.com/discussion/d871499b49e443259cfbea9b16f9b958
2) https://cp-algorithms.com/data_structures/segment_tree.html

**/


/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

int ara[nmax];

/** Merge Sort Tree **/

struct node
{
    vector<int>v;

    void create_leaf(int val)
    {
        v.push_back(val);
    }

    void merge_nodes(node &A,node &B)
    {
        merge(ALL(A.v),ALL(B.v),back_inserter(v));
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

int query(int cur,int start,int end,int l,int r,int k) /** RANGE query **/
{
    if(end<l || start>r)
        return 0;

    if(start>=l && end<=r)
    {
        return lower_bound(ALL(Tree[cur].v),k) - Tree[cur].v.begin();
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    int p1 = query(lc,start,mid,l,r,k);
    int p2 = query(rc,mid+1,end,l,r,k);

    return p1 + p2;
}

int main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
    }

    build(1,1,n);

    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;

        cout<<query(1,1,n,l,r,k)<<"\n";

    }

    return 0;
}


