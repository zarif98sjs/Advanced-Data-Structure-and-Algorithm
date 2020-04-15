
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

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL sum;

    void create_leaf(LL val)
    {
        sum=val;
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

void update(int cur, int start, int end, int updex, LL value) /** POINT update , replaces the current value **/
{
    if (start == end)
    {
        Tree[cur].create_leaf(value);
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    if (updex <= mid)
        update(lc, start, mid, updex, value);
    else
        update(rc, mid+1, end, updex, value);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
}

void query(node &res,int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(start>=l && end<=r)
    {
        res = Tree[cur];
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    if(r<=mid)
        query(res,lc,start,mid,l,r);
    else if(l>mid)
        query(res,rc,mid+1,end,l,r);
    else
    {
        node left,right;
        query(left,lc,start,mid,l,r);
        query(right,rc,mid+1,end,l,r);
        res.merge_nodes(left,right);
    }
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

        if(type==1) /** POINT update **/
        {
            int idx,val;
            cin>>idx>>val;

            update(1,1,n,idx,val);
        }
        else /** RANGE query **/
        {
            int l,r;
            cin>>l>>r;

            node ans;
            query(ans,1,1,n,l,r);
            cout<<ans.sum<<endl;
        }
    }



    return 0;
}


