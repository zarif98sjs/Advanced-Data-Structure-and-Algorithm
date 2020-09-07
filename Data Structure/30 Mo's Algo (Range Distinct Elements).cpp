
/**

Problem : Given a range [l,r], find the number of distinct elements in the range

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

const int nmax = 3e4+7;
const int nmax2 = 1e6+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int ara[nmax];

/** Mo's Algorithm **/
/*** 1 based indexing ***/

int block_size;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

int cnt[nmax2];
int max_cnt[nmax2]; /** this part is needed because when a value is removed , we need to check
                    if this value was the only one with maximum freq **/
int st = 0; /** set size **/

inline void init(int n)
{
    st = 0;
    fill(cnt,cnt+nmax2,0);
    fill(max_cnt,max_cnt+nmax2,0);
    block_size = sqrt(n);
}

void remov(int idx);  // TODO: remove value at idx from data structure
void add(int idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

inline void add(int idx)
{
    int val = ara[idx];

    if(cnt[val]==0) st++;
    cnt[val]++;
}

inline void remov(int idx)
{
    int val = ara[idx];
    cnt[val]--;

    if(cnt[val]==0) st--;
}

inline int get_answer()
{
    return st;
}

vector<int> mo_s_algorithm(vector<Query> queries)
{
    vector<int> answers(queries.size()+1);
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_l > q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l)
        {
            remov(cur_l);
            cur_l++;
        }
        while (cur_r > q.r)
        {
            remov(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
    }

    init(n); /** IMP **/
    vector<Query>qv;

    for(int i=1; i<=q; i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);

        qv.push_back({l,r,i});
    }

    auto ans = mo_s_algorithm(qv);

    for(int i=1; i<=q; i++)
    {
        printf("%d\n",ans[i]);
    }

    return 0;
}

/**

10 10
2 5 6 5 2 1 7 9 7 2
5 5
2 4
6 7
2 2
7 8
7 9
1 8
6 9
8 10
6 8

1
2
2
1
2
2
6
3
3
3

**/
