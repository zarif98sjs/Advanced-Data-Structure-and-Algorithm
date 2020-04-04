
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

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
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

LL ara[nmax];

/** Segment Tree LAZY PROPAGATION **/

struct node
{
    LL sum,prop;

    void create_leaf(LL val)
    {
        sum = val;
        prop = 0;
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

    Tree[cur].sum = Tree[lc].sum + Tree[rc].sum;

}

void update(int cur, int start, int end, int l, int r, LL value) /** RANGE update , adds to the current value **/
{
    if(end<l || start>r )
        return;

    if (start>=l && end<=r)
    {
        Tree[cur].sum += (end-start+1)*value;
        Tree[cur].prop += value;
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    update(lc, start, mid, l, r, value);
    update(rc, mid+1, end, l, r, value);

    Tree[cur].sum = Tree[lc].sum + Tree[rc].sum + Tree[cur].prop*(end-start+1);
}

LL query(int cur,int start,int end,int l,int r,LL carry) /** RANGE query **/
{
    if(end<l || start>r )
        return 0;

    if(start>=l && end<=r)
        return Tree[cur].sum + carry*(end-start+1);

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    LL p1 = query(lc,start,mid,l,r, carry + Tree[cur].prop);
    LL p2 = query(rc,mid+1,end,l,r, carry + Tree[cur].prop);

    return p1+p2;
}

int main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
        //update(1,1,n,i,ara[i]); /** use build instead of this point update **/
    }

    build(1,1,n);

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1) /** RANGE update **/
        {
            int l,r,val;
            cin>>l>>r>>val;

            update(1,1,n,l,r,val);
        }
        else /** RANGE query **/
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r,0)<<endl;
        }
    }



    return 0;
}


