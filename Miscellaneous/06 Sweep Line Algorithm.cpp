/**

Sweep Line Algorithm

Problem : https://www.codechef.com/problems/LAZER
(Need to count how many segments are intersected by a horizontal line , per query)

Solution :

One needs to go from lower y values to higher y values .
When the lower point of segment is found , make the segment active (+1)
When the higher point of segment is found , make the segment inactive (-1)

Answer the queries offline.

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

int ara[nmax],ql[nmax],qr[nmax],qy[nmax];

struct event{

    int type;
    int idx;
    int y;

};

bool cmp(const event &A,const event &B)
{
    return MP(A.y,A.type) < MP(B.y,B.type); /** type is included too , so that delete operation always happens at the last **/
}

/** BIT / FENWICK TREE **/
/*** 1 based indexing ***/

LL BIT[nmax];
void update(int index,int val,int len) /** POINT update , adds to the current value **/
{
    while(index<=len)
    {
        BIT[index] = BIT[index]+val;
        index += index&(-index);
    }
}

LL query(int index) /** RANGE query **/
{
    LL sum=0;
    while(index>0)
    {
        sum = sum+BIT[index];
        index -= index&(-index);
    }
    return sum;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,q;
        cin>>n>>q;

        for(int i=1;i<=n;i++)
            cin>>ara[i];

        for(int i=1;i<=q;i++)
            cin>>ql[i]>>qr[i]>>qy[i];

        vector<event>v;
        vector<LL>ans(q+1);

        for(int i=1;i<n;i++)
        {
            int minn = min(ara[i],ara[i+1]);
            int maxx = max(ara[i],ara[i+1]);

            v.push_back({1,i,minn}); /** Add Segment **/
            v.push_back({3,i,maxx}); /** Remove Segment **/
        }

        for(int i=1;i<=q;i++)
            v.push_back({2,i,qy[i]});

        sort(v.begin(),v.end(),cmp);

        for(auto e:v)
        {
            if(e.type==1)
            {
                update(e.idx,1,n-1);
            }
            else if(e.type==2)
            {
                int r = qr[e.idx]-1; /** -1 is to adjust with segment number **/
                int l = ql[e.idx];
                ans[e.idx] = query(r) - query(l-1);
            }
            else
            {
                update(e.idx,-1,n-1);
            }
        }

        for(int i=1;i<=q;i++)
            cout<<ans[i]<<endl;

    }

    return 0;
}


