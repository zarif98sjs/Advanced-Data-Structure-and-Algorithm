/**

Problem : Given a range [l,r], find the sum of all highest freq elements aka the MODE Sums

Practice Problem : https://codeforces.com/contest/600/problem/E

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

int cnt[nmax];
int cnt_cnt[nmax]; /// number of elements with this frequency
/** this part is needed because when a value is removed , we need to check
if this value was the only one with maximum freq **/

int cnt_cnt_sum[nmax]; /// sum of elements with this frequency
int mx = 0;

inline void init(int n)
{
    mx = 0;
    fill(cnt,cnt+nmax,0);
    fill(cnt_cnt,cnt_cnt+nmax,0);
    fill(cnt_cnt_sum,cnt_cnt_sum+nmax,0);
    block_size = sqrt(n);
}

void remov(int idx);  // TODO: remove value at idx from data structure
void add(int idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

inline void add(int idx)
{
    int val = ara[idx];
    cnt[val]++;
    cnt_cnt[cnt[val]]++;
    cnt_cnt_sum[cnt[val]] += val; /// this line is new to track sum
    mx = max(mx,cnt[val]);
}

inline void remov(int idx)
{
    int val = ara[idx];
    cnt_cnt[cnt[val]]--;
    cnt_cnt_sum[cnt[val]] -= val; /// this line is new to track sum

    if(cnt_cnt[cnt[val]]==0) /** if this value was the NOT only one with maximum freq , then reduce mx **/
        mx--;

    cnt[val]--;
}

inline int get_answer()
{
    return cnt_cnt_sum[mx];
}

vector<int> mo_s_algorithm(vector<Query> queries)
{
    vector<int> answers(queries.size()+1);
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 1;
    int cur_r = 0;
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
    int tc;
    scanf("%d",&tc);

    while(tc--)
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
            l++,r++;
            qv.push_back({l,r,i});
        }

        auto ans = mo_s_algorithm(qv);

        for(int i=1; i<=q; i++)
        {
            printf("%d\n",ans[i]);
        }
    }

    return 0;
}

/**
100
10 4
1 2 2 2 6 6 7 2 2 6
6 9
3 5
4 8
1 4
10 4
1 2 2 2 6 6 7 2 2 6
4 6
8 10
1 10
5 10
**/
